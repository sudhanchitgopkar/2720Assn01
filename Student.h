#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student {

 private:
  string fullName;
  string username;
  string password;
  
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;

 public:

  Student();
  Student(Student * student);
  Student(string name, string username, string password, int projectGrade, int quizGrade, int midtermGrade, int finalGrade);
  
  bool login(string username, string password);
  string getStudentName();

  int getProjectGrade();
  int getQuizGrade();
  int getMidtermGrade();
  int getFinalGrade();
  double getOverallGrade();
  string getUsername();
  string getPassword();

  void operator=(Student s);
  
  //string printStats();
};

#endif
  
