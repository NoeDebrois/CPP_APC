//
// Created by Danilo Ardagna on 18/11/2019.
//

#ifndef STUDENTSFILE_STUDENTSDATA_H
#define STUDENTSFILE_STUDENTSDATA_H

#include <vector>
#include <string>

#include "Exam.h"

class StudentsData {

    std::string name;
    std::string last_name;
    std::string birth_date;

    std::vector<Exam> exams;

public:
    StudentsData(const std::string& name, const std::string& lastName,
                 const std::string& birthDate);

    void add_exam(const Exam& e);

    float average_grade() const;
};


#endif //STUDENTSFILE_STUDENTSDATA_H
