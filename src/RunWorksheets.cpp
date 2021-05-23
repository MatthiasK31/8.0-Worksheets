/*
Matthias Kim
Lab 8.0
21 May 2021

WKST 1 Extra: allow user to choose how many people ages should be entered for
WKST 2 Extra: added some extra words to have the program check for palindromes
WKST 3 Extra: allow user to see info for a certain person
WKST 4 Extra: allow user to keep trying to get ticket num
WKST 5 Extra: prints the number of times that the number appeared in the array of randomly generated numbers
*/

#include <iostream>
#include "Worksheets.h"
#include "GetData.h"
#include "MyFunctions.h"


using namespace std;

int main()
{
    bool runAgain = false;
    string answer = "n";

    string name1 = "Working with and Creating Arrays and Vectors";
    string name2 = "Working with Functions and Arrays";
    string name3 = "Working with Parallel Arrays";
    string name4 = "Working with Searching Arrays";
    string name5 = "Searching and Sorting Arrays";
    
    do {
        worksheet1(name1);
        cout << "Press y/Y to run again. Any other character to proceed: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            runAgain = true;
        }
        else {
            runAgain = false;
        }
    } while (runAgain);
    
    do {
        cin.ignore(INT_MAX, '\n');
        worksheet2(name2);
        cout << "Press y/Y to run again. Any other character to proceed: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            cin.ignore(INT_MAX, '\n');
            runAgain = true;
        }
        else {
            runAgain = false;
        }
    } while (runAgain);
    
    do {
        cin.ignore(INT_MAX, '\n');
        worksheet3(name3);
        cout << "Press y/Y to run again. Any other character to proceed: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            runAgain = true;
        }
        else {
            runAgain = false;
        }
    } while (runAgain);
    
    
    do {
        cin.ignore(INT_MAX, '\n');
        worksheet4(name4);
        cout << "Press y/Y to run again. Any other character to proceed: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            runAgain = true;
        }
        else {
            runAgain = false;
        }
    } while (runAgain);
    
    do {
        worksheet5(name5);
        cout << "Press y/Y to run again. Any other character to proceed: ";
        cin >> answer;
        if (answer == "y" || answer == "Y") {
            runAgain = true;
        }
        else {
            runAgain = false;
        }
    } while (runAgain);
}