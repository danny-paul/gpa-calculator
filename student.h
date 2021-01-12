/*

CONSTRUCTORS, Person Class

Person ()
**Description: Will initialize Person objects
*Precondition: None
Postcondition: Assings "null" and -1 to string and numerical attributes, respectively

CONSTANT MEMBER FUNCTIONS, Person Class

string getFirstName(void) const
**Description: Retrieves firstName of Person
*Precondition: None
Postcondition: Returns firstName of Person

string getLastName(void) const;
**Description: Retrieves lastName of Person
*Precondition: None
Postcondition: Returns lastName of Person

string getAddress(void) const
**Description: Retrieves address of Person
*Precondition: None
Postcondition: Returns address of Person

void Person::display(void)
**Description: Outputs fullName and address to console
*Precondition: Non-default values for firstName, lastName, and address
Postcondition: Console displays fullName and address to console 

string inputCheckName(string) const
***PRIVATE***
**Description: Checks first and lastName for whitespace, length, and numerical characters
*Precondition: string without whitespace, numbers, and between 1-15 characters in length
Postcondition: returns passed string if acceptable, "null" if not

string getFullName(void) const
**Description: Retrieves fullName in the form, "lastname, firstname"
*Precondition: None
Postcondition: Returns fullName of Person

MODIFICATION MEMBER FUNCTIONS, Person class

void setFirstName(const string)
**Description: Assigns a passed string to firstName of Person
*Precondition: string between 1-15 without whitespace
Postcondition: firstName assigned string or does nothing if preconditions not met

void setLastName(const string)
**Description: Assigns a passed string to lastname of Person
*Precondition: string between 1-15 without whitespace
Postcondition: firstName assigned string or does nothing if preconditions not met

void setAddress(string)
**Description: Assigns a passed string to address of Person
*Precondition: string between 1-20
Postcondition: address assigned string or does nothing if preconditions not met

void bool concatName()
***PRIVATE***
**Description: Concatinates lastName & firstName
*Precondition: First and last name must be assigned before using
Postcondition: returns true if successful, false if not.

*/

/*

CONSTRUCTORS, Student Class (Base: Person)
Student()
**Description: Will initialize objects of Student
*Precondition: None
Postcondition: Default values are -1 for numerical attributes, "null" for string 

CONSTANT MEMBER FUNCTIONS, Student Class (Base Class: Person)

		
int getCredits(void) const;
**Description: Retrieves number of credits of Student
*Precondition: None
Postcondition: Returns creditsComplete 

int getQP(void) const;
**Description: Retrieves number of credits of Student
*Precondition: None
Postcondition: Returns QP (Qualifying Points)

int getID(void) const;
**Description: Retrieves ID Number of Student
*Precondition: None
Postcondition: Returns ID number (as integer)

void Student::display(void);
**Description: Outputs ID Number, fullName, and GPA to console
*Precondition: Must have non-default values for ID Number, firstName, lastName, and GPA
Postcondition: Outputs IDNumber, fullName, and GPA of Student. Does nothing if preconditions not met


MODIFICATION MEMBER FUNCTIONS, Student Class (Base Class: Person)

float getGPA(void);
**Description: (Re)Calculates GPA and returns as float
*Precondition: Qualifying points and creditsComplete must be non-default and non-negative (>0 for QP).
Postcondition: returns GPA, returns -1 (default) if preconditions not met

void setCredits(int const);
**Description: Assigns integer value to creditsComplete of Student
*Precondition: Integer value 0-199, inclusive
Postcondition: Assigns passed integer to creditsComplete or does nothing if preconditions unmet

void setQP(int const);
**Description: Assigns integer value to qualifying points for Student
*Precondition: Integer value 0-796, inclusive
Postcondition: Assigns passed integer to QP or does nothing if preconditoins not met

void setID(int const);
**Description: Assigns integer value to IDNumber for Student
*Precondition: Integer value 0-9999, inclusive
Postcondition: Assigns passed integer to IDNumber or does nothing if preconditions not met

*/


#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Person
{
	
	public:
		Person(); //constructor
		//constant member functions
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getAddress(void) const;
		std::string getFullName(void) const;
		void display(void); //over-riden function (see Student class).
		//modification member functions
		void setFirstName(const std::string);
		void setLastName(const std::string);
		void setAddress(std::string);
		bool concatName(void);
	private:
		std::string firstName;
		std::string lastName;
		std::string fullName;
		std::string address;
		//Constant Member Functions
		std::string inputCheckName(const std::string) const;



};

class Student : public Person
{
	public:
		Student(); //constructor
		//Constant Member Functions
		void display(void); //over-ridden function (see Person class)
		int getCredits(void) const;
		int getQP(void) const;
		int getID(void) const;

		//Modification Member Functions
		float getGPA(void); //modification since it calls calcGPA which modifies private data
		void setCredits(int const);
		void setQP(int const);
		void setID(int const);
		
	private:
		int idNumber;
		int creditsComplete;
		int QP; //Quality points
		float GPA;
		//Modification Member Functions, Private
		void calcGPA(void);
};


#endif
