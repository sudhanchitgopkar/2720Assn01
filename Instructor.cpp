#include "Instructor.h"
#include "Student.h"
#include <string>
#include <iostream>

Instructor::Instructor() {
  username = "";
  password = "";
  fullName = "";
} //constructor

Instructor::Instructor(std::string username, std::string password, std::string fullName) {
  this->username = username;
  this->password = password;
  this->fullName = fullName;
} //constructor

bool Instructor::login(std::string username, std::string password) {
  if (this->username == username && this->password == password) {
    return true;
  } else {
    return false;
  } //if
} //login

string Instructor::getInstructorName() {
  return fullName;
} //getInstructorName

Student Instructor::getStudent(std::string username, Student * students[], int numStudents) {
  bool flag = false;
  for (int i = 0; i < numStudents; i++) {
    if (students[i]->getUsername() == username) {
      flag = true;
      Student student {students[i]};
      std::cout << "Student name: " << students[i]->getStudentName() << std::endl;
      std::cout << "\t Project " << students[i]->getProjectGrade() << std::endl;
      std::cout << "\t Quiz " << students[i]->getQuizGrade() << std::endl;
      std::cout << "\t Midterm " << students[i]->getMidtermGrade() << std::endl;
      std::cout << "\t Final " << students[i]->getFinalGrade() << std::endl;
      std::cout << "\t Overall " << students[i]->getOverallGrade() << std::endl;
      return student;
      } //if
    } //for
    if (flag == false) {
      std::cout << "Student username is not valid" << std::endl;
    }
  } //getStudent

Student Instructor::getMinStudent(int gradeType, Student * students[], int numStudents) {
  double min = 100;

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getProjectGrade() < min) {
        min = students[i]->getProjectGrade();
      } //if
    } //for
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getQuizGrade() < min) {
        min = students[i]->getQuizGrade();
      } //if
    } //for
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getMidtermGrade() < min) {
        min = students[i]->getMidtermGrade();
      } //if
    } //for
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getFinalGrade() < min) {
        min = students[i]->getFinalGrade();
      } //if
    } //for
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getOverallGrade() < min) {
        min = students[i]->getOverallGrade();
      } //if
    } //for
  } //if

    std::cout << minGrade << endl;
} //getMinStudent

Student Instructor::getMaxStudent(int gradeType, Student * student[], int numStudents) {


} //getMaxStudent

double Instructor::getAvg(int gradeType, Student * student[], int numStudents) {

} //getAvg
