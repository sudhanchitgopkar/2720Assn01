#include "Student.h"

Student::Student() {

  fullName = "";
  username = "";
  password = "";
  
  projectGrade = 0;
  quizGrade = 0;
  midtermGrade = 0;
  finalGrade = 0.0;
  
}

Student::Student(string name, string username, string password, int projectGrade, int quizGrade, int midtermGrade, int finalGrade) {
  fullName = name;
  this->username = username;
  this->password = password;
  
  this->projectGrade = projectGrade;
  this->quizGrade = quizGrade;
  this->midtermGrade = midtermGrade;
  this->finalGrade = finalGrade;
}

bool Student::login(string username, string password) {
  if (this->username == username && this->password == password) {
    return true;
  } else {
    return false;
  }
}

string Student::getStudentName() {
  return this->fullName;
}

int Student::getProjectGrade() {
  return this->projectGrade;
}

int Student::getQuizGrade() {
  return this->quizGrade;
}

int Student::getMidtermGrade() {
  return this->midtermGrade;
}

int Student::getFinalGrade() {
  return this->finalGrade;
}

double Student::getOverallGrade() {
  return ((0.3 * getProjectGrade()) + (0.1 * getQuizGrade()) + (0.2 * getMidtermGrade()) + (0.4 * getFinalGrade()));
}

string Student::getUsername() {
  return this->username;
}

string Student::getPassword() {
  return this->password;
}
