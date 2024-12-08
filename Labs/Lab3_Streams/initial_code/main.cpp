/* Here is what we have to implement :
- A class FileManager that can be used to read a generic CSV file and that stores the corresponding
elements in table_type fields;
- add_students() and add_exams() that receive as parameters the table fields created by FileManager
and the map of students’ data and add to the map the students read from students.txt and the exams
read from exams.txt, respectively.
- Print, for each student the average of their grades (implemented in main).
*/

#include <iostream>
#include <unordered_map>

#include "FileManager.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;

typedef vector<string> row_type;
typedef vector<row_type> table_type;
typedef unordered_map<unsigned,StudentsData> students_type;

void add_students (const table_type&, students_type&);
void add_exams (const table_type&, students_type&);

int main () {

    string filename_students = "../students.txt";
    string filename_exams = "../exams.txt";

    students_type students;

    FileManager FM;

    // parse students file
    table_type fields = FM.parse_file(filename_students);

    // add students to the map
    add_students(fields, students);

    // parse exams file
    fields = FM.parse_file(filename_exams);

    // add exams to the corresponding students, if they exist in the map
    add_exams(fields, students);

    // compute and print average of students' grades
    /* MY CODE */
    for (students_type::const_iterator cit = students.begin(); cit != students.cend(); ++cit) {
        cout << "id : " << cit->first << endl;
        const StudentsData& my_student_data = cit->second;
        float average_grade = my_student_data.average_grade();
        cout << "average grade : " << average_grade << endl;
    }

}

void add_students (const table_type& fields, students_type& students) {
    // MY CODE :
    // Iterate through each row in the table (fields) parsed from the CSV file.
    for (const row_type& row : fields) {
        // Extract the student ID from the first column of the row and convert it to an unsigned integer.
        unsigned id = std::stoi(row[0]);

        // Create a new StudentsData object using the remaining columns of the row :
        // -> row[1], row[2], and row[3] correspond to the student's name, surname, and birthdate.
        StudentsData new_students_data(row[1], row[2], row[3]); // cf constructor in StudentsData.

        // Insert the student ID and the associated StudentsData object in the "unordered map".
        // The students unordered map uses the student ID as the key and StudentsData as the value.
        students.insert({id, new_students_data});
    }
}

void add_exams (const table_type& fields, students_type& students) {
    // Iterate through each row in the table (fields) parsed from the exams CSV file.
    for (const row_type& row : fields) {
        // Extract the student ID from the first column of the row and convert it to an unsigned integer.
        unsigned id = std::stoi(row[0]); // Student ID

        // Find the student in the students unordered map using their ID.
        students_type::iterator it = students.find(id);

        // Check if the student exists in the unordered map.
        if (it != students.end()) { // If the student exists:
            StudentsData& student = it->second; // Retrieve the corresponding StudentsData object.

            // Create a new Exam object using the remaining columns of the row:
            // -> row[1]: Exam ID (converted to an unsigned integer)
            // -> row[2]: Exam date (string)
            // -> row[3]: Exam grade (converted to an unsigned integer)
            Exam new_exam(std::stoi(row[1]), row[2], std::stoi(row[3]));

            // Add the exam to the student's data using the add_exam method (cf StudentsData.cpp).
            student.add_exam(new_exam);
        } else {
            // If the student doesn't exist, output an error message using std::cerr.
            cerr << "ERROR: Could not add exam to student " << id
                 << " because he/she doesn't exist." << endl;
        }
    }
}
