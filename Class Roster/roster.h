#pragma once
#include "student.h"
using namespace std;

//Roster class defines variable to create a calculation of the amount of students. Defines functions to be used later.

class Roster

{
public: 
	int totalStudents;
	int finalStudent;
	Student** population;

	//Initiates the roster, fills the roster, and resets the roster.
	Roster();
	Roster(int totalStudents);
	~Roster();

	//Defines variable functions to be constructed in cpp. 
	void stringData(string newData); 
	DegreeProgram convert(string str); 
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
    void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};