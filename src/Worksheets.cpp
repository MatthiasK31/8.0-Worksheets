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
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    
    //1
    //was a response to written code


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
    string daysOfTheWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    vector<double> dailySales;
    double salesForDay = 0;
    int response; string advance = ""; string temp;

    for (int i = 0; i < size(daysOfTheWeek); i++) {
        cout << "Enter the total sales for " << daysOfTheWeek[i] <<": ";
        cin >> salesForDay;
        dailySales.push_back(salesForDay);
        cout << "There was a total of $" << salesForDay << " on " << daysOfTheWeek[i] << "!" << endl;
    }

    do {
        cout << "Choose a day of the week to view its total sales:  ";
        cin >> response;
        yesOrNo = checkValidWeekInput(to_string(response));

        if (yesOrNo == true) {
            while (yesOrNo) {
                cout << "\tEnter a valid number:\t";
                cin.clear();
                cin >> response;
                yesOrNo = checkValidWeekInput(to_string(response));
            }
        }

        cout << "There was a total of $" << dailySales.at(response) << " on " << daysOfTheWeek[response] << "!" << endl;


        cout << "Would you like to continue? ";
        cin >> advance;
        for (int i = 0; i < advance.length(); i++) {
            temp += tolower(advance.at(i));
        }
        advance = temp;

    } while (advance != "no");


}

void worksheet2(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    
    //1
    vector<int> numbers;
    int num, fav, timesFound; 
    bool yesOrNo;

    for (int i = 0; i < 10; i++) {
        cout << "Enter a number: ";
        cin >> num;
        //error trap invalid inputs
        yesOrNo = checkValidNumInput(to_string(num));

        if (yesOrNo == true) {
            while (yesOrNo) {
                cout << "\tEnter a valid number:\t";
                cin.clear();
                cin >> num;
                yesOrNo = checkValidNumInput(to_string(num));
            }
        }
        numbers.push_back(num);
    }

    //ask user to enter his/her favorite number
    cout << "Additionally, please enter your favorite number: ";
    cin >> fav;
    yesOrNo = checkValidWeekInput(to_string(fav));

    if (yesOrNo == true) {
        while (yesOrNo) {
            cout << "\tEnter a valid number:\t";
            cin.clear();
            cin >> fav;
            yesOrNo = checkValidWeekInput(to_string(fav));
        }
    }

    //call function, get the returned value, then print out a final message
    timesFound = favorite(numbers, fav);
    cout << "In your 10 numbers that you entered, your favorite number " << fav << " was found a total of " << timesFound << " times." << endl;


    //2
    vector<string> words;
    words.push_back("radar");
    words.push_back("warts");
    words.push_back("evil");
    words.push_back("racecar");
    words.push_back("toot");
    string compare, isAPalindrome;

    printf("%-15s %-25s %-20s\n", "Word", "Reversed", "Palindrome?");
    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < words.size(); i++) {
        compare = isPalindrome(words.at(i).c_str());
        if (compare == words.at(i)) {
            isAPalindrome = "Yes";
        }
        else {
            isAPalindrome = "No";
        }
        printf("%-15s %-15s %-15s\n", words.at(i).c_str(), compare.c_str(), isAPalindrome.c_str());
    }

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