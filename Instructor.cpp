#include "Instructor.h"
#include <string.h>

Instructor::Instructor() {
  username = "";
  password = "";
  fullName = "";
} //constructor

Instructor::Instructor(string username, string password, string fullName) {
  this->username = username;
  this->password = password;
  this->fullName = fullName;
} //constructor

bool Instructor::login(string username, string password) {
  if (this->username == username && this->password) {
    return true;
  } else {
    return false
  } //if
} //login

string Instructor::getInstructorName() {
  return fullName;
} //getInstructorName

Student Instructor::getStudent(string username) {
  Student student{username};

  return student;
} //getStudent

Student Instructor:getMinStudent(int gradeType) {

} //getMinStudent

Student Instructor::getMaxStudent(int gradeType) {


} //getMaxStudent

double Instructor::getAvg(int gradeType) {

} //getAvg
