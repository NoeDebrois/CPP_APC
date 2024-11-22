//
// Created by Federica Filippini on 16/11/2020.
//

#include "ScheduledJob.h"


void ScheduledJob::adjust_start_time() {
    if (start_time < job->get_submission_time()) {
        start_time = job->get_submission_time();
    }
}

// If you don't want to give access to everything, you have to re-implement the getters from Job
// in here (i.e ScheduledJob) :
Job::time_instant ScheduledJob::get_end_time() const
{
    return start_time + job->get_execution_time();
    // job is a shared-ptr !
}

Job::time_instant ScheduledJob::get_start_time() const
{
    return start_time;
}

Job::time_instant ScheduledJob::get_deadline() const
{
    return job->get_deadline();
}

Job::time_instant ScheduledJob::get_execution_time() const
{
    return job->get_execution_time();
}

Job::time_instant ScheduledJob::get_submission_time() const
{
    return job->get_submission_time();
}



void ScheduledJob::set_start_time(Job::time_instant  st_time) {
    start_time = st_time;
    adjust_start_time(); // TO BE SAFE !!
}

double ScheduledJob::evaluate() const {
    if (get_start_time() < get_end_time()) {
        return 0.0;
    }

    // Else :
    return job->get_weight() * (get_end_time() - get_deadline());
}

void ScheduledJob::print() const
{
    job->print();
    std::cout << " start_time " << start_time
              << " end_time " << get_end_time();
}
