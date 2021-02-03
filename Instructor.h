#include <string>
#include "Student.h"

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor {
 public:
  Instructor();
  Instructor(std::string username, std::string password, std::string fullName);

  bool login(std::string username, std::string password);
  string getInstructorName();

  bool getStudent(std::string username, Student * students[], int numStudents);
  Student getMinStudent(int gradeType, Student * students[], int numStudents);
  Student getMaxStudent(int gradeType, Student * students[], int numStudents);
  double getAvg(int gradeType, Student * students[], int numStudents);

 private:
  std::string fullName;
  std::string username;
  std::string password;
}; //Instructor

#endif
