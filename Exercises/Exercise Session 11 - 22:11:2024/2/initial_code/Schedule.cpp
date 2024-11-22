//
// Created by Federica Filippini on 16/11/2020.
//

#include "Schedule.h"


void Schedule::validate() {
    // Guarantees that the schedule is valid, i.e. a job
    // starts after the end of the one before :

    if(order.empty())
        return; // Just for clarity since we would go inside the following for loop.

    for (std::size_t ii = 1; ii < size(); ++ii) {
        if (order[ii].get_start_time() < order[ii - 1].get_end_time()) {
            order[ii].set_start_time(order[ii - 1].get_end_time());
        }
    }
}


Schedule::size_type Schedule::size() const
{
    return order.size();
}

void Schedule::add(const std::shared_ptr<Job> &job) {

    if (order.empty())
        order.push_back(ScheduledJob(job));
    else{
        ScheduledJob s_job(job, std::max(job->get_submission_time(), order.back().get_end_time()));
        order.push_back(s_job);

        //order.push_back(ScheduledJob(job, std::max(job->get_submission_time(), order.back().get_end_time())));
    }

}

double Schedule::evaluate() const {
    double weighted_tardiness = 0;
    for (const auto& s_job: order) {
        weighted_tardiness += s_job.evaluate();
    }
    return weighted_tardiness;
}


void Schedule::print() const
{
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        order[i].print();
        std::cout << std::endl;
    }
}
