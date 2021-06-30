#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;


//This initiates a student field without filling in information.

Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for ( int k = 0; k < completedCourseDaysArray; k++ )
    {
        this-> completedCourseDays[k] = 0;
    }

    this->degreeProgram = UNDECLARED;
}


//Fills in student information with current data from table that was input.
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completedCourseDays[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int k = 0; k < completedCourseDaysArray; k++)
    {
        this->completedCourseDays[k] = completedCourseDays[k];
    }
    this->degreeProgram = degreeProgram;
}

//Deconstructor that refreshes student data.
Student::~Student() 
{
}

//Setters for variables of student data.
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
void Student::setAge(int age)
{
    this->age = age;
}
void Student::setcompletedCourseDays(int completedCourseDays[])
{
    for (int k = 0; k < completedCourseDaysArray; k++)
    {
        this->completedCourseDays[k] = completedCourseDays[k];
    }
}
void Student::setDegreeProgram(DegreeProgram program) {
    this->degreeProgram = program;
}



//Getters for student data variables.
string Student::getStudentID() const
{
    return studentID;
}
string Student::getFirstName() const
{
    return firstName;
}
string Student::getLastName() const
{
    return lastName;
}
string Student::getEmailAddress() const
{
    return emailAddress;
}
int Student::getAge() const
{
    return age;
}

//Pointer used on the variable to retrieve most recent number and set it as the value.
int* Student::getcompletedCourseDays()
{
    return completedCourseDays;
}
DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

//Prints out the retrieved data and formats it.
void Student::print()

{
    cout 
        << "First Name- " << firstName << " |\t" << "Last Name- " << lastName << " |\t" << "Age- " << age << " |\t" << "Student ID- " << studentID << " |\t"
        << "Days to complete a course - (" << completedCourseDays[0] << ", " << completedCourseDays[1] << ", "
        << completedCourseDays[2] << ") |" << "Degree Program- " << degreeProgramOptions[getDegreeProgram()];

}