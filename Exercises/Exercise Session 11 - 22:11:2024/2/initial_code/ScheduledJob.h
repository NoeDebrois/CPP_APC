//
// Created by Federica Filippini on 16/11/2020.
//

#ifndef SCHEDULEEVALUATION_SCHEDULEDJOB_H
#define SCHEDULEEVALUATION_SCHEDULEDJOB_H

#include <memory> // For shared_ptr

#include "Job.h"

// It could be an inheritance of Job class, but it was not the chosen implementation here.
// We have to avoid memory usage ; and a ScheduledJob is nothing more than a Job with a Start Time.
class ScheduledJob {
private:
    std::shared_ptr<Job> job;
    Job::time_instant start_time;

    void adjust_start_time(); // Guarantees that start_time and submission_time of the job are compatible.

public:
    // std::shared_ptr<Job>& job to avoid memory usage.
    ScheduledJob (const std::shared_ptr<Job>& job, Job::time_instant st_time)
            : job(job), start_time (st_time)
    {
        adjust_start_time();
    }

    // job(std::make_shared<Job>(j)) because j is a Job, and job should be a std::shared_ptr<Job>.
    ScheduledJob (Job j, Job::time_instant st_time)
            : job(std::make_shared<Job>(j)), start_time(st_time)
    {
        adjust_start_time();
    }

    // COPY-CONSTRUCTOR :
    explicit ScheduledJob (const std::shared_ptr<Job>& job) // copy-constructor
            : job(job), start_time(job->get_submission_time())
    // If no start_time given, let's initialize it to submission_time. The most natural thing to do.
    {}

    // All the getters :
    Job::time_instant get_end_time() const;
    Job::time_instant get_start_time() const;
    Job::time_instant get_deadline() const;
    Job::time_instant get_execution_time() const;
    Job::time_instant get_submission_time() const;

    // Single setter (to set the start time) :
    void set_start_time (Job::time_instant  st_time);

    double evaluate() const;

    void print() const;
};


#endif //SCHEDULEEVALUATION_SCHEDULEDJOB_H
