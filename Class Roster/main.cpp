//This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "roster.h"
using namespace std;



int main() {

    // "Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name."
    cout << "Course C867";
    cout << endl;
    cout << "Language: C++";
    cout << endl;
    cout << "Kaitlynn Abshire";
    cout << endl;
    cout << "Student #: 000970207";
    cout << endl;
    cout << "Gathering data..." << endl;


    const int studentTotal = 5; 



    //Given table data to input into system.

    const string studentData[] = { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kaitlynn,Abshire,kabshi2@wgu.edu,25,11,6,10,SOFTWARE"
    };

    
    //Pointer updates roster to new size.
    Roster* classRoster = new Roster(studentTotal); 

    //Adds new student data into collection.
    for (int k = 0; k < studentTotal; k++)
    { 
        classRoster->stringData(studentData[k]);

    }

    //Title/header format
    cout << "Completed Student Scan" << endl << endl;

    
    classRoster->printAll();


    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->printByDegreeProgram(SECURITY);
    classRoster->printByDegreeProgram(NETWORK);
    classRoster->printByDegreeProgram(UNDECLARED);


    //For loop used to calculate average for all students included in the data instead of stopping at 1. 
    for (int k = 0; k < classRoster->totalStudents; k++)
    {
        classRoster->printAverageDaysInCourse(classRoster->population[k]->getStudentID());
    }


    classRoster->printInvalidEmails();


    //Deletes A3 as requested by instrucitons.
    classRoster->remove("A3");

    //Resets roster data to show no A3.
    classRoster->printAll();

   //Tries to delete A3 again per instructions. 
    classRoster->remove("A3");
    //Expected: the above line should print a message saying such a student with this ID was not found.

    return 0;
}