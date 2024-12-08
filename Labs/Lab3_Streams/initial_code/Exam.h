//
// Created by Danilo Ardagna on 18/11/2019.
//

#ifndef STUDENTSFILE_EXAM_H
#define STUDENTSFILE_EXAM_H

#include <string>

class Exam {

    size_t course_id;
    std::string date;
    unsigned grade;

public:
    Exam(size_t courseId, const std::string& date, unsigned grade);

    size_t getCourseId() const;

    void setCourseId(size_t courseId);

    const std::string& getDate() const;

    void setDate(const std::string& date);

    unsigned getGrade() const;

    void setGrade(unsigned grade);
};


#endif //STUDENTSFILE_EXAM_H
