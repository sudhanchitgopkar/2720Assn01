#include "Student.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Student::Student() {

  fullName = "";
  username = "";
  password = "";
  
  projectGrade = 0;
  quizGrade = 0;
  midtermGrade = 0;
  finalGrade = 0.0;

 }

Student::Student(string studentFile) {

  fullName = "";
  username = "";
  password = "";
  
  projectGrade = 0;
  quizGrade = 0;
  midtermGrade = 0;
  finalGrade = 0.0;

}

Student::Student(Student * student) {
  this->fullName = student->fullName;
  this->username = student->username;
  this->password = student->password;
  
  this->projectGrade = student->projectGrade;
  this->quizGrade = student->quizGrade;
  this->midtermGrade = student->midtermGrade;
  this->finalGrade = student->finalGrade;
}

Student::Student(string name, string username, string password, int projectGrade, int quizGrade, int midtermGrade, int finalGrade, string studentFile) {
  fullName = name;
  this->username = username;
  this->password = password;
  
  this->projectGrade = projectGrade;
  this->quizGrade = quizGrade;
  this->midtermGrade = midtermGrade;
  this->finalGrade = finalGrade;

}

bool Student::login(string username, string password, char **argv) {
  ifstream studentFile(argv[2]);
  string fileReader;

  bool succesfulLogin{false};

  string s;
  
  while (getline(studentFile, fileReader)) {
    istringstream tempString{fileReader};
    while (getline(tempString, s, '\t')) {
      if (s.compare(username) == 0) {
	getline(tempString, s, '\t');
	if (s.compare(password) == 0) {
	  succesfulLogin == true;
	}
      }
    }
  }
  return succesfulLogin; 
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

void Student::operator=(Student s) {
  this->fullName = s.getStudentName();
  this->username = s.getUsername();
  this->password = s.getPassword();
  
  this->projectGrade = s.getProjectGrade();
  this->quizGrade = s.getQuizGrade();
  this->midtermGrade = s.getMidtermGrade();
  this->finalGrade = s.getFinalGrade();
}

/*
string Student::printStats() {
std::cout << username << password << fullName;
std::cout << projectGrade << quizGrade << midtermGrade << finalGrade << std::endl;
}
*/
