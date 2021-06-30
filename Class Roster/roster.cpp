#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

// Initializes the roster and table before retrieving the data. 
Roster::Roster() 
{
    this->totalStudents = 0; 
    this->finalStudent = -1; 
    this->population = nullptr; 

}

//Initializes roster for the correct amount of students recorded in the data. 
//Pointer used to set the most recent array to new value.
Roster::Roster(int totalStudents) 
{
    this->totalStudents = totalStudents;
    this->finalStudent = -1; 
    this->population = new Student * [totalStudents]; 
}



//Returns the data in associated strings, gives it a temporary space, and sends it to further functions.
void Roster::stringData (string newData)
{ 
    vector<string> studentData; 
    stringstream dataSStream(newData); 

    //Separates the data given by the comma used in inputting the data to assign it to the correct value.
    while (dataSStream.good())
    { 
        string data;
        getline(dataSStream, data, ',');
        studentData.push_back(data);
    }

    //Adds data now parsed by commas to the system and changes it to the correct data type. Ex. stoi string to integer.
    add(studentData.at(0), studentData.at(1), studentData.at(2), studentData.at(3), stoi(studentData.at(4)), stoi(studentData.at(5)), stoi(studentData.at(6)), stoi(studentData.at(7)), convert(studentData.at(8)) 
    );
}

//Checks the data returned in the enum for the program it matches. If none matches it returns Undeclared.
DegreeProgram Roster::convert(string deg)
{ 
    if (deg == "SECURITY") return SECURITY;
    else if (deg == "SOFTWARE") return SOFTWARE;
    else if (deg == "NETWORK") return NETWORK;
    else return UNDECLARED;
}

//Function saves data input and inserts it as a new student.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{ 
    //If statement used to increase total number of students in the system so it does not cause an error in overflow.
    if (finalStudent < totalStudents)
    { 
        finalStudent++; 
        this->population[finalStudent] = new Student();
        this->population[finalStudent]->setStudentID(studentID);
        this->population[finalStudent]->setFirstName(firstName);
        this->population[finalStudent]->setLastName(lastName);
        this->population[finalStudent]->setEmailAddress(emailAddress);
        this->population[finalStudent]->setAge(age);
        int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        this->population[finalStudent]->setcompletedCourseDays(days);
        this->population[finalStudent]->setDegreeProgram(degreeProgram);
    }
 //Else statement catches the overflow error.
    else 
    {
        cerr << endl << "The number on the roster is > the number of students! Please fix and try again." << endl;
    }
}

//Returns all data for students.
void Roster::printAll()
{
    cout << "All Current Students" << endl;
    for (int k = 0; k <= this->finalStudent; k++)
    {

        (this->population)[k]->print();
        cout << endl;
    }
    cout << endl;
}

//Function averages out the 3 days input for course completions. Uses a boolean to check for student id in system.
void Roster::printAverageDaysInCourse(string studentID)
{


    bool found = false;

    for (int k = 0; k <= finalStudent; k++)
    {
        //If ID is present, a pointer to grab the data from an array. Averages the array data. 
        if (this->population[k]->getStudentID() == studentID)
        {
            found = true;
            int* days = this->population[k]->getcompletedCourseDays();
            double averageDays = static_cast<double>(days[0] + days[1] + days[2]) / 3.0;
            cout << studentID << " completes courses in an average of " << averageDays << " days. \n\n";
        }
    }
    if (!found)
    {
        cerr << studentID << " does not exist." << endl;
    }


}


//Function lists any students with wrong email addresses.
void Roster::printInvalidEmails()
{
    
    cout << "Invalid Email Addresses" << endl;
    bool found = false; 

    //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    for (int k = 0; k <= finalStudent; k++)
    { 
        string email = this->population[k]->getEmailAddress();
        if (
            (email.find('.') == string::npos) || 
            (email.find('@') == string::npos) || 
            !(email.find(' ') == string::npos)   
            )
        { 
            found = true;
            this->population[k]->print();
            cout << endl;
        }
    }
    cout << endl;
    if (!found)
    {
        cout << "All emails are in correct format." << endl;
    }
}

//Function arranges students in display by their specific degree program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    cout << "The " << degreeProgramOptions[degreeProgram] << " Program's Students" << endl;
    for (int k = 0; k <= finalStudent; k++)
    {
        if (this->population[k]->getDegreeProgram() == degreeProgram)
        {
            this->population[k]->print();
            cout << endl;
        }
    }
    cout << endl;

}

//Destructor to remove roster from memory when it falls out of scope. Removes each student and then the empty container/object.
Roster::~Roster()
{
    for (int k = 0; k < totalStudents; k++)
    {
        delete this->population[k];
    }
    delete this;
}

//Function helps delete students from the roster. Uses a boolean to determine if the student id matches in the system.
void Roster::remove(string studentID)
{

    bool found = false;

    for (int k = 0; k <= finalStudent; k++)
    {
        if (this->population[k]->getStudentID() == studentID)
        {
            found = true;
            delete this->population[k];
            this->population[k] = this->population[finalStudent];
            finalStudent--;
            cout << studentID << " has been removed." << endl;
        }
    }
    if (!found)
    {
        cerr << studentID << " does not exist." << endl;
    }

}