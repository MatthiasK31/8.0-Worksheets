/* Create an empty c++ console project named "YourLastName_WS_Title" For example DiGiovanna_WS_Files
// Copy the Worksheets.h, Worksheets.cpp, runWorkSheets.cpp, GetData.h, GetDataR2.cpp , MyFunctions.cpp, MyFunctions.h
// file to the directory containing your project's *.sln file
// In the solution Explorer window, add the RunWorksheets.cpp file to the project by
//  1) Right clicking on the source files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "RunWorksheets.cpp" file
// In the solution Explorer window, add the Worksheets.h file to the project by
//  1) Right clicking on the header files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "Worksheets.h" file
// In the solution Explorer window, add the Worksheets.cpp file to the project by
//  1) Right clicking on the source files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "Worksheets.cpp" file
// Add your code to the program per the instructions.
// In the solution Explorer window, add the GetDataR2.cpp file to the project by
//  1) Right clicking on the source files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "GetDataR2.cpp" file
// In the solution Explorer window, add the GetData.h file to the project by
//  1) Right clicking on the source files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "GetData.h" file
// Add your code to the program per the instructions.
// In the solution Explorer window, add the MyFunctions.H file to the project by
//  1) Right clicking on the source files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "MyFunctions.h" file
// In the solution Explorer window, add the MyFunctions.cpp file to the project by
//  1) Right clicking on the source files folder, select "add"
//  2) Select "existing item"
//  3) A popup appears. Select the "MyFunctions.cpp" file

// Add your code to the program per the instructions in each of the files.
// Classes can be added freely just as before (Use the Project/add class from the menu.
// You may delete these instructions from your program if you find them intrusive.

//REVISIONS
// 4/17/2021
// Added the data validation routines and the MyFuncion files and updated instructions accordingly
*/

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

    string name1 = "Worksheet 1";
    string name2 = "Worksheet 2";
    string name3 = "Worksheet 3";
    string name4 = "Worksheet 4";
    string name5 = "Worksheet 5";
    
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
        worksheet2(name2);
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