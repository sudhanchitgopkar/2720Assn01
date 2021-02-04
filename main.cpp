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
  int numInstructors{0};
  int numStudents{0};
  Student * students;
  Instructor * instructors;

  while(getline(instructorFile, fileReader)) {
    numInstructors++;
  }
  while(getline(studentFile, fileReader)) {
    numStudents++;
  }

  //instructors = new Instructor [numInstructors];
  students = new Student [numStudents];
  studentFile.clear();
  studentFile.seekg(0);

  instructors = new Instructor [numInstructors];
  instructorFile.clear();
  instructorFile.seekg(0);

  string instIdentifier[3];
  string studIdentifier[3];
  int studGrades[4];
  int i{0};
  int j{0};
  string s;


    cout << "User Types," << endl << "\t 1- Instructor" << endl << "\t 2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit: ";

    string input;
    string inputUsername;
    string inputPassword;
    bool incorrectInput = true;

    cin >> input;
    while (incorrectInput) {
      if (input == "1" || input == "2" || input == "3") {
        incorrectInput = false;
      } else {
        cout << "Invalid option. Please enter a valid option." << endl;
        cin >> input;
      }
    }

    cout << endl;

    cout << "Enter credentials to login, \n\t Enter Username: ";;
    cin >> inputUsername;
    cout << "\t Enter Password: ";
    cin >> inputPassword;

    while (getline(studentFile, fileReader)) {
      istringstream tempString{fileReader};
      i = 0;
      while (getline(tempString, s, '\t')) {
        if (i < 3) {
          studIdentifier[i] = s;
        } else {
          studGrades[i-3] = stoi(s, nullptr, 10);
        } //if
        i++;
      }

      Student temp{studIdentifier[2], studIdentifier[0], studIdentifier[1], studGrades[0], studGrades[1], studGrades[2], studGrades[3], argv[2]};
      students[j] = temp;
      j++;
    } //while

    j=0;
    while (getline(instructorFile, fileReader)) {
      istringstream tempString{fileReader};
      i = 0;
      while (getline(tempString, s, '\t')) {
        instIdentifier[i] = s;
        i++;
      } //while

      Instructor temp{instIdentifier[0],instIdentifier[1],instIdentifier[2]};
      instructors[j] = temp;
      j++;
    } //while


  if (input == "1") {
    for (int i = 0; i < numInstructors; i++) {
      } //for
    Instructor temp{};
    if(temp.login(inputUsername,inputPassword,argv)) {
      for (int i = 0; i < numInstructors; i++) {
          if (inputUsername == instructors[i].getUsername()) {
          temp = instructors[i];
        } //if
      } //for

      cout << "\n You are now logged in as instructor " << temp.getInstructorName() << endl;
      cout << "\n Query options, \n\t 1 - view grades of a student \n\t 2 - view stats" << endl;
      cout << "Enter option number: ";
      cin >> input;

      bool invalidInput{true};
      while (invalidInput) {
	if (input == "1" || input == "2") {
	  invalidInput = false;
	} else {
	  cout << "Invalid option. Please enter a valid option." << endl;
	  cin >> input;
	}
      } //while

      if (input == "1") {
        cout << "Enter student username to view grades: ";
        string studentName;
        cin >> studentName;
        if (temp.getStudent(studentName,students,numStudents)) {

        } else {
          //cout << "Student username is not valid" << endl;
        } //if

      } else if (input == "2") {
        cout << endl;
        cout << "Grade types," << endl;
        cout << "\t 1 - Project grade \n\t 2 - Quiz grade";
        cout << "\n\t 3 - Midterm grade \n\t 4 - Final grade \n\t 5 - Overall grade" << endl;
        cout << "Select a grade type to view stats: ";
        cin >> input;

        invalidInput = true;
        if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
          invalidInput = false;
        } //if
        while (invalidInput) {
          cout << "Invalid option. Please enter a valid option.";
          cout << endl;
          cout << "Grade types," << endl;
          cout << "\t 1 - Project grade \n\t 2 - Quiz grade";
          cout << "\n\t 3 - Midterm grade \n\t 4 - Final grade \n\t 5 - Overall grade" << endl;
          cout << "Select a grade type to view stats: ";
          cin >> input;
        } //while
        if (input == "1") {
          cout << endl;
          cout << "Project grade stats," << endl;
          cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents);
        } else if (input == "2") {
          cout << endl;
          cout << "Quiz grade stats," << endl;
          cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents);
        } else if (input == "3") {
          cout << endl;
          cout << "Midterm grade stats," << endl;
          cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents);
        } else if (input == "4") {
          cout << endl;
          cout << "Final grade stats," << endl;
          cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents);
        } else if (input == "5") {
          cout << endl;
          cout << "Overall grade stats," << endl;
          cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents);
          cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents);
        }
      } //if

    } else {
      cout << "Login as instructor failed." << endl;
    } //if



  } else if (input == "2") {
    Student test{};
    if (test.login(inputUsername, inputPassword, argv)) {
      for (int i = 0; i < numStudents; i++) {
	if (students[i].getUsername() == inputUsername) {
	  test = students[i];
	}
      }
      string gradeInput;
      cout << "You are now logged in as student " << test.getStudentName() << endl;
      cout << "Do you want to view grades (y/n)?";
      cin >> gradeInput;
      if(gradeInput == "y") {
	std::cout << "Student name: " << test.getStudentName() << std::endl;
	std::cout << "\t Project " <<test.getProjectGrade() << std::endl;
	std::cout << "\t Quiz " << test.getQuizGrade() << std::endl;
	std::cout << "\t Midterm " << test.getMidtermGrade() << std::endl;
	std::cout << "\t Final " << test.getFinalGrade() << std::endl;
	std::cout << "\t Overall " << test.getOverallGrade() << std::endl;
      } else {
	
      }
    } else {
      cout << "Login as student failed" << endl;
    }
  }
} //main

void getCredentials() {

} //getCredentials
