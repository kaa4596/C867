#pragma once
#include "degree.h"
#include <string>
using namespace std;

// Header class to define variables needed for the table and data.

class Student
{
	//Array created to help retrieve all input data for days taken to complete a course. Used to average the days.

	public:

		const static int completedCourseDaysArray = 3;

	//Defining the variables for student data collected. 

	private:

		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int completedCourseDays[completedCourseDaysArray];
		DegreeProgram degreeProgram;
	
	//Constructor for student data.

	public:
		
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completedCourseDays[], DegreeProgram degreeProgram);

	//
		~Student();

	//Setters for all student data variables.
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setcompletedCourseDays(int completedCourseDays[completedCourseDaysArray]);
		void setDegreeProgram(DegreeProgram degreeProgram);
		void print();

	//Getters for all student data variables. Completed course days uses a pointer to create a variable that gathers from memory. 
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmailAddress() const;
		int getAge() const;
		int* getcompletedCourseDays();
		DegreeProgram getDegreeProgram() const;


};