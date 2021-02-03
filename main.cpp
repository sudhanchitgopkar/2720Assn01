#include<unistd.h>

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<sstream>

#include "Student.h"
#include "Instructor.h"

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "Usage: main [instructors_file] [students_file]" << endl;
    return 1;
  }

  ifstream instructorFile(argv[1]);
  ifstream studentFile(argv[2]);
  string fileReader;
  //ifstream instructors(argv[1]);
  //ifstream students(argv[2]);
  int numInstructors{0};
  int numStudents{0};
  //Instructor * instructors;
  Student * students;

  while(getline(instructorFile, fileReader)) {
    //cout << temp << endl;
    numInstructors++;
  }
  while(getline(studentFile, fileReader)) {
    //cout << temp << endl;
    numStudents++;
  }

  //instructors = new Instructor [numInstructors];
  students = new Student [numStudents];
  studentFile.clear();
  studentFile.seekg(0);

  string studIdentifier[3];
  int studGrades[4];
  int i{0};
  string s;
  
  while (getline(studentFile, fileReader)) {
    istringstream tempString{fileReader};
    i = 0;
    while (getline(tempString, s, '\t')) {
      if (i < 3) {
	studIdentifier[i] = s;
      } else {
	studGrades[i-3] = stoi(s, nullptr, 10);
      }
      i++;
    }
    
    //cout << studentFile.get() << endl;
  }

  
  /*for (int i = 0; i < numStudents; i++) {
    string temp [7];
    for (int i = 0; i < 7; i++) {
      temp[i] = studentFile.get();
    } //for
    students[i] = Student();
    //students[i].printStats();
  } //for
  */

  cout << "InstructorNumber: " << numInstructors << endl;
  cout << "StudentNumber: " << numStudents << endl;
  
  cout << "User types," << endl << "\t1 - Instructor" << endl << "\t2 - Student" << endl;
  cout << "Select a login user type or enter 3 to exit:" << endl;

}
