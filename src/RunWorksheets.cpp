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

#include <iostream>
#include "Worksheets.h"
#include "GetData.h"
#include "MyFunctions.h"


using namespace std;

int main()
{
    bool runAgain = false;
    string answer = "n";

    string name1 = "Working with Logical Operators";
    string name2 = "Working with if Statements";
    string name3 = "Worksheet If - Else statements";
    string name4 = "Worksheet More work with if - else";
    string name5 = "Worksheet Functions Q2";
    
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