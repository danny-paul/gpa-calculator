#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "student.h"

using namespace std;

int main(void)
{
    Student stu[20]; //creates an array to hold up to 20 Student objects

    ifstream inp; //creating object to handle existing file for input
    string firstName, lastName, address; //holds value until assignment to student object
    string tempID, tempCredits, tempQP; //holds value until processing and finally assignment to student object
    int idNumber = -1, creditsCom = -1, QP = -1; //holds value until assignment to student object, -1 indicates bad data/unchanged
    int count = 0; //counts number of loops in input text file
    char tempChar[256] = { ' ' }; //C-Style string necessary to use 'atoi' to get integers of idNumber, creditsCom, QP
    int badDataID = -1, badDataCred = -1, badDataQP = -1; //-1 indicates good data, >=0 is bad data. Cred = credits (Cred), Quality points (QP)

    inp.open("input.txt"); //creates ifstream (input file stream) object inp to handle existing file, input.txt

    while (!inp.eof()) //while the 'End of File' (EOF) flag is not raised
    {
        //gets the first six lines
        getline(inp, firstName); //firstname
        getline(inp, lastName); //lastname
        getline(inp, address); //address
        getline(inp, tempID); //id number
        getline(inp, tempCredits); //credits complete
        getline(inp, tempQP); //quality points

        //Necessary since 'atoi' funciton will include integer values UNTIL a non-numerical character is reached, Leads to truncating bad data into good data in certain situations
        badDataID = tempID.find_first_not_of("0123456789 "); //find first character from parameter that is not also in tempID. Returns array position of tempID bad data or does nothing
        badDataCred = tempCredits.find_first_not_of("0123456789 "); //find first character from parameter that is not also in tempCredits. Returns array position of tempCredits bad data or does nothin
        badDataQP = tempQP.find_first_not_of("0123456789 "); //find first character from parameter that is not also in tempCredits. Returns array position of tempCredits bad data or does nothin

        //tempID (string)-->IDNumber (int)
        for (int i = 0; i < tempID.length(); i++) //changes ID string into ID integer
            tempChar[i] = tempID[i]; //assigns character from string into char array
        idNumber = atoi(tempChar); //atoi converts C-style string into integer. If non-convertable character is hit, it will stop at that character and thus truncate the value
        for (int i = 0; i < 256; i++) //clears character array for next loop
            tempChar[i] = ' ';


        //tempCredits (string) --> creditsComplete (int)
        for (int i = 0; i < tempCredits.length(); i++) //changes credits string into credits integer
            tempChar[i] = tempCredits[i]; //assigns character from string into char array
        creditsCom = atoi(tempChar); //atoi converts C-style string into integer. If non-convertable character is hit, it will stop at that character and thus truncate the value
        for (int i = 0; i < 256; i++) //clears character array for next loop
            tempChar[i] = ' ';


        //tempQP (string) --> QP (int)
        for (int i = 0; i < tempQP.length(); i++) //changes QP string into QP integer
            tempChar[i] = tempQP[i]; //assigns character from string into char array
        QP = atoi(tempChar); //atoi converts C-style string into integer. If non-convertable character is hit, it will stop at that character and thus truncate the value
        for (int i = 0; i < 256; i++) //clears character array for next loop
            tempChar[i] = ' ';


        //assigns each value to the appropriate object data. 
        stu[count].setFirstName(firstName);
        stu[count].setLastName(lastName);
        stu[count].setAddress(address);
        if (badDataID == -1) //-1 indicates no non-numerical characters were found in the text file on ID line
            stu[count].setID(idNumber); //assigns ID to student object in position 'i' of array
        if (badDataCred == -1)
            stu[count].setCredits(creditsCom); //assigns credits to student object in position 'i' of array
        if (badDataQP == -1)
            stu[count].setQP(QP); //assigns quality points to student object in position 'i' of array

        count++; //increments and count loops
    }

    for (int i = 0; i < count; i++) //less than and not <= since count is incremented one more time at loop end
    {
        if (stu[i].getFirstName() != "null" && stu[i].getLastName() != "null" && stu[i].getID() != -1 && stu[i].getQP() != -1 && stu[i].getCredits() != -1)
        {
            cout << "Student " << i + 1 << "\n";
            stu[i].display(); //calls display function if text file had acceptable data
            cout << "\n\n";
        }
        else
            cout << "Student " << i + 1 << ": Error\n\n"; //print error if bad data in a particular student
    }


    system("PAUSE"); //Pauses to view data prior to closing
    inp.close();

    return 0; //exit
}
