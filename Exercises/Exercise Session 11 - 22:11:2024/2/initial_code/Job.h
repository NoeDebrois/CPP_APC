//
// Created by Federica Filippini on 16/11/2020.
//

#ifndef SCHEDULEEVALUATION_JOB_H
#define SCHEDULEEVALUATION_JOB_H

#include <iostream>

class Job {

// Classical way of coding a class when it's only for storing data :
// - All the data is private ;
// - Getters and Setters that are public.

public:
    typedef long int time_instant;
    typedef unsigned int id_type;

private:
    id_type id;

    time_instant submission_time;
    time_instant execution_time;
    time_instant deadline;
    double weight;

    void adjust_deadline();

public:

    Job (id_type j_id, time_instant sub_time, time_instant exe_time,
         time_instant dline, double w = 1.0)
            : id (j_id), submission_time (sub_time),
              execution_time (exe_time), deadline (dline), weight (w)
    {
        adjust_deadline();
    }

    time_instant get_deadline() const;
    time_instant get_execution_time() const;
    time_instant get_submission_time() const;
    id_type get_ID() const;
    double get_weight() const;

    void set_deadline (time_instant deadline);
    void set_execution_time (time_instant execution_time);
    void set_submission_time (time_instant submission_time);
    void set_weight (double weight);

    void print() const;
};


#endif //SCHEDULEEVALUATION_JOB_H
