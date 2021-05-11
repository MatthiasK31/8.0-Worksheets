//headers
#include "Worksheets.h"
#include "GetData.h"
#include "MyFunctions.h"

//libraries
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void worksheet1(string namedItem) {

    //2
    //create variables
    vector<double> finalGrade;
    double total = 0, average = 0;

    //add values to the vector variable
    finalGrade.push_back(85.8);
    finalGrade.push_back(93.7);
    finalGrade.push_back(76);
    finalGrade.push_back(88.5);
    finalGrade.push_back(100);
    finalGrade.push_back(91.3);

    //cycle through all values of the vector and add them to a variable containing the sum
    for (int i = 0; i < finalGrade.size(); i++) {
        total += finalGrade.at(i);
    }

    //calculate average and print
    average = total / finalGrade.size();
    printf("%-20.1f\n\n", average);



    //3
    int iRandom;
    vector<int> rNumbers; vector<int> rEven;

    //initialize the random seed
    srand(time(NULL));

    cout << "Original Order:" << endl;
    for (int i = 0; i < 10; i++) {
        //generate the random number and push back to the vector with all the numbers
        iRandom = rand() % 10 + 1;
        rNumbers.push_back(iRandom);

        //only push back the even numbers to a separate vector
        if (iRandom % 2 == 0) {
            rEven.push_back(iRandom);
        }
        cout << iRandom << "\t";
    }

    //backwards
    cout << "\nBackwards:" << endl;
    for (int i = rNumbers.size() - 1; i >= 0; i--) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << "\n\nIn this array of 10 numbers, there are " << rEven.size() << " even numbers.\n" << endl;


    //4
    vector<int> pAges;
    double age;
    int moreThan = 0;
    bool yesOrNo = false;

    for (int i = 0; i < 5; i++) {
        cout << "Enter age #" << i + 1 << ":  ";
        cin >> age;
        yesOrNo = checkValidNumInput(to_string(age));

        if (yesOrNo == true) {
            while (yesOrNo) {
                cout << "\tEnter a valid number:\t";
                cin.clear();
                cin >> age;
                yesOrNo = checkValidNumInput(to_string(age));
            }
        }

        pAges.push_back(age);

        if (age > 15)
            moreThan++;

        yesOrNo = false;
    }

    cout << "There are " << moreThan << " people who are older than 15.\n" << endl;


    //5
    string daysOfTheWeek[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    vector<double> dailySales;
    double salesForDay = 0;

    for (int i = 0; i < size(daysOfTheWeek); i++) {
        cout << "Enter the total sales for today:  ";
    }


}

void worksheet2(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //Put all code for worksheet 2 here
    //SAMPLE should be deleted
    //MySampleFunction();

}

void worksheet3(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //Put all code for worksheet 3 here
}

void worksheet4(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //Put all code for worksheet 4 here
}

void worksheet5(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //Put all code for worksheet 5 here
}