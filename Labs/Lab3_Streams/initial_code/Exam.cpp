//
// Created by Danilo Ardagna on 18/11/2019.
//

#include "Exam.h"

using std::string;

Exam::Exam(size_t courseId, const string& date, unsigned grade):
    course_id(courseId), date(date), grade(grade) {}

size_t Exam::getCourseId() const {
    return course_id;
}

void Exam::setCourseId(size_t course_id) {
    this->course_id = course_id;
}

const string& Exam::getDate() const {
    return date;
}

void Exam::setDate(const string& date) {
    this->date = date;
}

unsigned Exam::getGrade() const {
    return grade;
}

void Exam::setGrade(unsigned grade) {
    this->grade = grade;
}
