//
// Created by Federica Filippini on 16/11/2020.
//

#ifndef SCHEDULEEVALUATION_SCHEDULE_H
#define SCHEDULEEVALUATION_SCHEDULE_H

#include <vector>

#include "ScheduledJob.h"

class Schedule {

private:
    std::vector<ScheduledJob> order;

    // Guarantees that the schedule is valid, i.e. a job
    // starts after the end of the one before :
    void validate();

public:
    typedef std::vector<ScheduledJob>::size_type size_type;

    Schedule() = default;

    size_type size() const;

    // Add new job to the schedule
    void add (const std::shared_ptr<Job>& job); // Look at the main file !

    // Evaluate total weighted tardiness for the schedule;
    double evaluate() const;

    void print() const;

    virtual ~Schedule() = default;
};


#endif //SCHEDULEEVALUATION_SCHEDULE_H
