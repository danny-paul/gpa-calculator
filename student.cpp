#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "student.h"

using namespace std;

//Person Constructor
Person::Person() //default values "null" string
{
	address = "null";
	firstName = "null";
	lastName = "null";
	fullName = "null";
}

//CONSTANT Person Member Functions

string Person::getFirstName(void) const
{
	return firstName; //returns null if not assigned a value
}

string Person::getLastName(void) const
{
	return lastName; //returns null if no assigned value
}

string Person::getFullName(void) const
{
	return fullName; //returns null if no assigned value
}

string Person::getAddress(void) const
{
	return address; //returns null if not assigned
}

void Person::display()
{
	
	bool flag = concatName(); //if first and last name are not 'null', return true

	if (flag && address != "null") //if all values assigned a value, does nothing if incorrect
	{
		//max length for fullName is 30. Plus 2 more for the whitespace and comma. Address is added onto end
		cout << left << setw(32); //text on left, whitespace on right. 
		cout << fullName << " " << address << "\n";
	}
}

string Person::inputCheckName(const string value) const
{
	int isWhiteSpace, isNumber = -1;
	isWhiteSpace = value.find(' '); //holds integer position for whitespace or -1 for no whitespace
	isNumber = value.find_first_of("0123456789 "); //checks for numbers and whitespace

	if (value.length() >= 1 && value.length() <= 15 && isNumber == -1) //checks if passed input is valid
		return value; //passed string is valid, returns it
	else
		return "null"; //ensures default value of "null" is assigned since input was invalid
}




//MODIFICATION Person Member Functions

void Person::setFirstName(const string value)
{
	firstName = inputCheckName(value); //error checks before assigning to firstName. 
}

void Person::setLastName(const string value)
{
	lastName = inputCheckName(value); //error checks before assigning to lastName
}

void Person::setAddress(string value)
{
	if (value.length() >= 1 && value.length() <= 20) //checks if passed input is valid, if not does nothing
		address = value; //passed string is valid, returns it. 
}

bool Person::concatName(void)
{
	if (firstName != "null" && lastName != "null")
	{
		fullName = lastName + ", " + firstName; //fullName created via concatination 
		return true; //main set a firstName and lastName
	}
	return false; //some default value exists in firstName or lastName
}

//Student class constructor
Student::Student()
{
	creditsComplete = -1;
	QP = -1;
	GPA = -1;
	idNumber = -1;
	//idNumberStr = "null";
}

//CONSTANT Student Member Functions

void Student::display(void)
{
	bool flagName = Person::concatName(); //sets true if successful

	if (flagName) //if strings are non-default and proper format will enter
	{	
		if(idNumber < 10)
   			cout << "000" << idNumber;
		else if (idNumber < 100)
    		cout << "00" << idNumber;
		else if (idNumber < 1000)
  			cout << "0" << idNumber;
		else
    		cout << idNumber;
		string temp = " " + getFullName(); //assigns first chunk to string for easy formatting
		cout << left << setw(33);
		//max length for fullName is 33 (including whitespace and comma)
		//text on left, whitespace on right
		cout << temp << + " " << fixed << setprecision(1) << getGPA(); 
	}
	//does nothing if incorrect data or default data
}

float Student::getGPA(void)
{
	calcGPA(); //prevents stale data and calculates GPA prior to returning
	return GPA;
}

int Student::getCredits(void) const
{
	return creditsComplete; //returns credits
}

int Student::getQP(void) const
{
	return QP; //returns qualifying points
}

int Student::getID(void) const
{
	return idNumber; //returns idNumber
}

//MODIFICATION Student Member Functions

void Student::calcGPA(void)
{
	if (creditsComplete > 0 && QP >= 0) //prevents divided by zero error and ensures main assignes values
		GPA = static_cast<float> (QP) / creditsComplete; //assigns GPA with correct values, forces float type 
	else
		GPA = -1; //(re)sets GPA to default value (-1) when QP and credits are negative/default/zero
}

void Student::setCredits(int const value)
{
	if (value >= 0 && value <= 199)
		creditsComplete = value; //sets passed value if within credit range
	else
		creditsComplete = -1; //(re)sets credits to -1 when credits are negative/default
}

void Student::setQP(int const value)
{
	if (value >= 0 && value <= 796)
		QP = value; //assigns if within QP range
	else
		QP = -1; //(re)sets to -1 when QP are negative/default or preconditions not met
}

void Student::setID(const int value)
{
	if (value >= 0 && value <= 9999)
		idNumber = value;
	else
		idNumber = -1; //sets to -1 when ID is negative/default or preconditions not met
}


