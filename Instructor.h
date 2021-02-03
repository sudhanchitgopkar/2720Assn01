#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor {
 public:
  Instructor();

  bool login(string username, string password);
  string getInstructorName();

  Student getStudent(string username);
  Student getMinStudent(int gradeType);
  Student getMaxStudent(int gradeType);
  double getAvg(int gradeType);

 private:
  string fullName;
  string username;
  string password;
} //Instructor
#endif
