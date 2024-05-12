#include <iostream>
#include <fstream>
using namespace std;

class Course {
private:
    string course_number;
    string course_name;
    int credit_hours;
    char grade;

public:
    void setCourseNumber(const string& number) {
        course_number = number;
    }

    string getCourseNumber() const {
        return course_number;
    }

    void setCourseName(const string& name) {
        course_name = name;
    }

    string getCourseName() const {
        return course_name;
    }

    void setCreditHours(int hours) {
        credit_hours = hours;
    }

    int getCreditHours() const {
        return credit_hours;
    }

    void setGrade(char g) {
        grade = g;
    }

    char getGrade() const {
        return grade;
    }
};

class Student {
private:
    string first_name, last_name;
    string ID;
    char tuition_paid;
    int number_of_courses;
    Course courses[10];
public:
    void setFirstName(const string& first) {
        first_name = first;
    }

    string getFirstName() const {
        return first_name;
    }

    void setLastName(const string& last) {
        last_name = last;
    }

    string getLastName() const {
        return last_name;
    }

    void setID(const string& id) {
        ID = id;
    }

    string getID() const {
        return ID;
    }

    void setTuitionPaid(char paid) {
        tuition_paid = paid;
    }

    char getTuitionPaid() const {
        return tuition_paid;
    }

    void setNumberOfCourses(int numCourses) {
        number_of_courses = numCourses;
    }

    int getNumberOfCourses() const {
        return number_of_courses;
    }

    void setCourse(int index, const Course& course) {
        courses[index] = course;
    }

    Course getCourse(int index) const {
        return courses[index];
    }

    double calculateGPA() const {
        double totalPoints = 0;
        double totalCredits = 0;

        for (int i = 0; i < number_of_courses; ++i) {
            if (courses[i].getGrade() == 'A') {
                totalPoints += 4.0 * courses[i].getCreditHours();
            } else if (courses[i].getGrade() == 'B') {
                totalPoints += 3.0 * courses[i].getCreditHours();
            } else if (courses[i].getGrade() == 'C') {
                totalPoints += 2.0 * courses[i].getCreditHours();
            } else if (courses[i].getGrade() == 'D') {
                totalPoints += 1.0 * courses[i].getCreditHours();
            }
            totalCredits += courses[i].getCreditHours();
        }
        double gpa = (totalPoints / totalCredits);
        return gpa;
    }
};

class GradeReport {
private:
    int tuitionRate;
    Student students[10];
public:
    GradeReport(int rate) : tuitionRate(rate) {}

    void readDataFromFile(const string& filename) {
        ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            cerr << "Error opening the file!" << endl;
            return;
        }

        int numStudents;
        inputFile >> numStudents >> tuitionRate;

for (int i = 0; i < numStudents; ++i) 
{
    Student student;
    
    string first_name, last_name, ID;
    char isTuitionPaid;
    int number_of_courses;

    inputFile >> first_name >> last_name >> ID >> isTuitionPaid >> number_of_courses;
    student.setFirstName(first_name);
    student.setLastName(last_name);
    student.setID(ID);
    student.setTuitionPaid(isTuitionPaid);
    student.setNumberOfCourses(number_of_courses);

    for (int j = 0; j < student.getNumberOfCourses(); ++j) 
    {
        Course course;
        string course_name, course_number;
        int credit_hours;
        char grade;

        inputFile >> course_name >> course_number >> credit_hours >> grade;
        course.setCourseName(course_name);
        course.setCourseNumber(course_number);
        course.setCreditHours(credit_hours);
        course.setGrade(grade);

        student.setCourse(j, course);
    }

    students[i] = student;
}
        inputFile.close();
    }

    void displayGradeReport() const 
    {
        for (int i = 0; i < 10; ++i) 
        {
            cout << "Student " << i + 1 << ":" << endl << endl;
            if (students[i].getTuitionPaid() == 'Y') 
            {
                student_data(students[i]);
            } else 
            {
                displayHoldMessage(students[i]);
            }
        }
    }

private:
    void displayHoldMessage(const Student& student) const {
        cout << "Student Name: " << student.getFirstName() << " " << student.getLastName() << endl;
        cout << "Student ID: " << student.getID() << endl;
        cout << "Number of courses enrolled: " << student.getNumberOfCourses() << endl;
        cout << "Grades have been held for nonpayment of tuition fee." << endl;
        int billingAmount = 0;
        for (int j = 0; j < student.getNumberOfCourses(); ++j) {
            billingAmount += student.getCourse(j).getCreditHours();
        }
        cout << "Billing amount: $" << tuitionRate * billingAmount << endl;
        cout << endl;
    }
};

int main() {
    GradeReport gradeReport(0);

    gradeReport.readDataFromFile("report.txt");

    gradeReport.displayGradeReport();

    return 0;
}