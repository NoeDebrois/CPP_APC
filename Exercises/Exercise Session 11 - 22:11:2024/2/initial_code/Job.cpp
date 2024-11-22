//
// Created by Federica Filippini on 16/11/2020.
//

#include "Job.h"

void Job::adjust_deadline()
{
    if (deadline < submission_time + execution_time)
        deadline = submission_time + execution_time;
}

Job::time_instant Job::get_deadline() const
{
    return deadline;
}

Job::time_instant Job::get_execution_time() const
{
    return execution_time;
}

Job::time_instant Job::get_submission_time() const
{
    return submission_time;
}

double Job::get_weight() const
{
    return weight;
}

Job::id_type Job::get_ID() const
{
    return id;
}

void Job::set_deadline (time_instant d)
{
    deadline = d;
    adjust_deadline();
}

void Job::set_execution_time (time_instant t)
{
    execution_time = t;
    adjust_deadline();
}

void Job::set_submission_time (time_instant t)
{
    submission_time = t;
    adjust_deadline();
}

void Job::set_weight (double w)
{
    weight = w;
}

void Job::print() const
{
    std::cout << "id: " << id << " submission_time " << submission_time
              << " execution_time " << execution_time <<  " deadline "
              << deadline << " weight " << weight;
}
