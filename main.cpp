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
  
  ifstream instructors(argv[1]);
  ifstream students(argv[2]);
  string temp;
  int instructorNumber{0};
  int studentNumber{0};
  int increment{0};
  while(getline(instructors, temp)) {
    cout << temp << endl;
    instructorNumber++;
  }
  while(getline(students, temp)) {
    cout << temp << endl;
    studentNumber++;
  }
  while(getline(students, temp)) {
    cout << temp << endl;
  }
 
  cout << "InstructorNumber: " << instructorNumber << endl;
  cout << "StudentNumber: " << studentNumber << endl;
  
  cout << "User types," << endl << "\t1 - Instructor" << endl << "\t2 - Student" << endl;
  cout << "Select a login user type or enter 3 to exit:" << endl;
  
}
