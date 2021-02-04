#include "Instructor.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

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

Instructor::Instructor(Instructor * instructor) {
  this->username = instructor->username;
  this->password = instructor->password;
  this->fullName = instructor->fullName;
} //constructor

bool Instructor::login(std::string username, std::string password, char **argv) {
  ifstream instructorFile(argv[1]);
  string fileReader;

  bool succesfulLogin{false};

  string s;

  while (getline(instructorFile, fileReader)) {
    istringstream tempString{fileReader};
    while (getline(tempString, s, '\t')) {
      if (s.compare(username) == 0) {
        getline(tempString, s, '\t');
        if (s.compare(password) == 0) {
          succesfulLogin = true;
        } //if
      } //if
    } //while
  } //while
  return succesfulLogin;
} //login

string Instructor::getInstructorName() {
  return this->fullName;
} //getInstructorName

string Instructor::getUsername() {
  return this->username;
} //getUserName

string Instructor::getPassword() {
  return this->password;
} //getPassword

bool Instructor::getStudent(std::string username, Student students[], int numStudents) {
  for (int i = 0; i < numStudents; i++) {
    if (students[i].getUsername() == username) {
      std::cout << endl;
      std::cout << "Student name: " << students[i].getStudentName() << std::endl;
      std::cout << "\t Project " << students[i].getProjectGrade() << std::endl;
      std::cout << "\t Quiz " << students[i].getQuizGrade() << std::endl;
      std::cout << "\t Midterm " << students[i].getMidtermGrade() << std::endl;
      std::cout << "\t Final " << students[i].getFinalGrade() << std::endl;
      std::cout << "\t Overall " << students[i].getOverallGrade() << std::endl;
      return true;
    } //if
  } //for

  std::cout << "Student username is not valid" << std::endl;
  return false;
} //getStudent

string Instructor::getMinStudent(int gradeType, Student students[], int numStudents) {
  double min {100};
  Student minStudent{students[0]};

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getProjectGrade() < min) {
        minStudent = students[i];
        min = minStudent.getProjectGrade();
      } //if
    } //for
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getQuizGrade() < min) {
        minStudent = students[i];
        min = minStudent.getQuizGrade();
      } //if
    } //for
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getMidtermGrade() < min) {
        minStudent = students[i];
          min = minStudent.getMidtermGrade();
      } //if
    } //for
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getFinalGrade() < min) {
        minStudent = students[i];
        min = minStudent.getFinalGrade();
      } //if
    } //for
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getOverallGrade() < min) {
        minStudent = students[i];
        min = minStudent.getOverallGrade();
      } //if
    } //for
  } //if

  std::cout << "\t min \t" << min << "% (" << minStudent.getStudentName() << ")" << endl;
  return "";
} //getMinStudent

string Instructor::getMaxStudent(int gradeType, Student students[], int numStudents) {
  double max {0};
  Student maxStudent{students[0]};

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getProjectGrade() > max) {
        maxStudent = students[i];
        max = maxStudent.getProjectGrade();
      } //if
    } //for
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getQuizGrade() > max) {
        maxStudent = students[i];
        max = maxStudent.getQuizGrade();
      } //if
    } //for
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getMidtermGrade() > max) {
        maxStudent = students[i];
        max = maxStudent.getMidtermGrade();
      } //if
    } //for
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getFinalGrade() > max) {
        maxStudent = students[i];
        max = maxStudent.getFinalGrade();
      } //if
    } //for
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      if (students[i].getOverallGrade() > max) {
        maxStudent = students[i];
        max = maxStudent.getOverallGrade();
      } //if
    } //for
  } //if
  std::cout << "\t max \t" << max << "% (" << maxStudent.getStudentName() << ")" << endl;
  return "";
} //getMaxStudent

string Instructor::getAvg(int gradeType, Student students[], int numStudents) {
  double avg{0};
  double sum{0};

  if (gradeType == 1) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getProjectGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 2) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getQuizGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 3) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getMidtermGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 4) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getFinalGrade();
    } //for
      avg = sum / numStudents;
  } else if (gradeType == 5) {
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getOverallGrade();
    } //for
      avg = sum / numStudents;
  } //if

  std::cout << "\t avg \t" << avg << "%" << endl;
  return "";
} //getAvg

void Instructor::operator=(Instructor i) {
  this->fullName = i.getInstructorName();
  this->username = i.getUsername();
  this->password = i.getPassword();
} //copy
