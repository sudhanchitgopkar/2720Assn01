#include<unistd.h>

#include<iostream>
#include<fstream>

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
  int increment{0};

  while(getline(instructorFile, temp)) {
    //cout << temp << endl;
    instructorNumber++;
  }
  while(getline(studentFile, temp)) {
    //cout << temp << endl;
    studentNumber++;
  }

  Instructor instructors [numInstructors];
  Student students [numStudents];

  for (int i = 0; i < numStudents; i++) {
    string temp [7];
    for (int i = 0; i < 7; i++) {
      temp[i] = file.get();
    } //for
    students[i] = new Student(temp[1],temp[2],temp[3],temp[4],temp[5]
                              temp[6],temp[7]);
    students[i].printStats();
  } //for

  cout << "InstructorNumber: " << instructorNumber << endl;
  cout << "StudentNumber: " << studentNumber << endl;
  
  cout << "User types," << endl << "\t1 - Instructor" << endl << "\t2 - Student" << endl;
  cout << "Select a login user type or enter 3 to exit:" << endl;

}
