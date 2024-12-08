//
// Created by Danilo Ardagna on 18/11/2019.
//

#include "StudentsData.h"

using std::string;

StudentsData::StudentsData(const string& name, const string& lastName, const string& birthDate):
    name(name), last_name(lastName), birth_date(birthDate) {}

void StudentsData::add_exam(const Exam& e) {
    exams.push_back(e);
}

float StudentsData::average_grade() const {
    float sum = 0.;

    for (const Exam& e : exams)
        sum += e.getGrade();

    return sum/exams.size();
}
