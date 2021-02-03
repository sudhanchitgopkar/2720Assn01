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

bool Instructor::getStudent(std::string username, Student * students[], int numStudents) {
  for (int i = 0; i < numStudents; i++) {
    if (students[i]->getUsername() == username) {
       std::cout << "Student name: " << students[i]->getStudentName() << std::endl;
      std::cout << "\t Project " << students[i]->getProjectGrade() << std::endl;
      std::cout << "\t Quiz " << students[i]->getQuizGrade() << std::endl;
      std::cout << "\t Midterm " << students[i]->getMidtermGrade() << std::endl;
      std::cout << "\t Final " << students[i]->getFinalGrade() << std::endl;
      std::cout << "\t Overall " << students[i]->getOverallGrade() << std::endl;
      return true;
    } //if
  } //for

  std::cout << "Student username is not valid" << std::endl;
  return false;
} //getStudent

Student Instructor::getMinStudent(int gradeType, Student * students[], int numStudents) {
  double min {100};
  Student minStudent{students[0]};

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getProjectGrade() < min) {
        minStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getQuizGrade() < min) {
        minStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getMidtermGrade() < min) {
        minStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getFinalGrade() < min) {
        minStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getOverallGrade() < min) {
        minStudent = students[i];
      } //if
    } //for
  } //if
  return minStudent;
} //getMinStudent

Student Instructor::getMaxStudent(int gradeType, Student * students[], int numStudents) {
  double max {0};
  Student maxStudent{students[0]};

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getProjectGrade() > max) {
        maxStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getQuizGrade() > max) {
        maxStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getMidtermGrade() > max) {
        maxStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getFinalGrade() > max) {
        maxStudent = students[i];
      } //if
    } //for
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i]->getOverallGrade() > max) {
        maxStudent = students[i];
      } //if
    } //for
  } //if
  return maxStudent;
} //getMaxStudent

double Instructor::getAvg(int gradeType, Student * students[], int numStudents) {
  double avg{0};
  double sum{0};

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i]->getProjectGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i]->getQuizGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i]->getMidtermGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i]->getFinalGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i]->getOverallGrade();
    } //for
      avg = sum / numStudents;
  } //if

  return avg;
} //getAvg
