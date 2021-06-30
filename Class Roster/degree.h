#pragma once
using namespace std;

//Enum created for the degree program data since only specific degree programs can be assigned. 

enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, UNDECLARED};

//Static string used to check with output to use based on exact match.
static const string degreeProgramOptions[] = {"SECURITY", "NETWORK", "SOFTWARE", "UNDECLARED"};
