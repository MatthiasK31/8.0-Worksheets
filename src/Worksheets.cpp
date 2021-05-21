/*
Matthias Kim
Lab 8.0
21 May 2021

WKST 1 Extra: 
WKST 2 Extra:
WKST 3 Extra:
WKST 4 Extra:
WKST 5 Extra: prints the number of times that the number appeared in the array of randomly generated numbers
*/

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
#include <algorithm>

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
    int age;
    int moreThan = 0;
    bool yesOrNo = false;

    for (int i = 0; i < 5; i++) {
        do {
            cout << "Enter age #" << i + 1 << ":  ";
        } while (!(getValidInt(age)) || age < 0);
        
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
    int response; string advance = ""; string temp = "";

    for (int i = 0; i < size(daysOfTheWeek); i++) {
        cout << "Enter the total sales for " << daysOfTheWeek[i] <<": ";
        cin >> salesForDay;
        dailySales.push_back(salesForDay);
        cout << "There was a total of $" << salesForDay << " on " << daysOfTheWeek[i] << "!" << endl;
    }

    do {
        do {
            cout << "Choose a day of the week to view its total sales:  ";
        } while (!getValidInt(response) || response < 0 || response > 4);

        cout << "There was a total of $" << dailySales.at(response - (int)1) << " on " << daysOfTheWeek[response -  (int)1] << "!" << endl;


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
    
    //1
    //declare arrays
    vector<int> distanceMeters = { 50, 100, 200, 400, 800, 1000 };
    vector<double> timeSeconds = { 7.24, 13,54, 28.03, 71.12, 158.67, 220.15 };
    string entered; int distance = 0;
    bool yesOrNo;

    //ask for distance
    cout << "Which distance would you like to check the time for? ";
    cin >> entered;
    //error trap
    yesOrNo = checkValidDistance(entered);

    if (yesOrNo == true) {
        while (yesOrNo) {
            cout << "\tEnter a valid number:\t";
            cin.clear();
            cin >> entered;
            yesOrNo = checkValidDistance(entered);
        }
    }
    //convert the entered value into an int
    distance = stoi(entered);
    
    //go through the distance vector and once the value is found, print the distance and time, then break out of the loop
    for (int i = 0; i < distanceMeters.size(); i++) {
        if (distance == distanceMeters.at(i)) {
            printf("%-15s %-15s\n", "Distance(m)", "Time(sec)");
            printf("%-15d %-15.2f\n\n", distance, timeSeconds.at(i));
            break;
        }
    }

    //2
    string name, address, number;
    vector<string> studentNames = { "Shaiiko Lebleu", "John Wick", "Tony Stark", "Steve Rogers", "Peter Parker" };
    vector<string> studentAddys;
    vector<string> studentNumbers;
    
    //ask 5 diff people their name/address/number
    cin.ignore(INT_MAX, '\n');
    for (int i = 0; i < 5; i++) {
        cout << "Student #" << i+1 << ":" << endl;

        cout << "What is your address?  ";
        getline(cin, address);
        cout << "What is your phone number?  ";
        getline(cin, number);

        //push back variables
        studentAddys.push_back(address);
        studentNumbers.push_back(number);
        cout << endl;
    }
    printStudents(studentNames, studentAddys, studentNumbers);

}

void worksheet4(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //1

    //variables
    double ticket;
    bool yesOrNo, aMatch = false;
    vector<int> winningNumbers = { 307, 521, 416, 154, 243, 89 };

    //ask for a ticket value and error trap input
    cout << "Enter your ticket number!!  ";
    cin >> ticket;
    yesOrNo = checkValidNumInput(to_string(ticket));

    if (yesOrNo == true) {
        while (yesOrNo) {
            cout << "\tEnter a valid number:\t";
            cin.clear();
            cin >> ticket;
            yesOrNo = checkValidNumInput(to_string(ticket));
        }
    }

    //search through the array and if there is a match, print a corresponding statement
    for (int i = 0; i < winningNumbers.size(); i++) {
        if (ticket == winningNumbers.at(i)) {
            aMatch = true;
        }
    }
    if (aMatch == true) {
        cout << "Congrats! Your ticket #" << ticket << " is a winning number!" << endl;
    }
    else {
        cout << "Sorry, your ticket is not a winning number.\n" << endl;
    }


    //2
    double key = 0;
    aMatch = false;
    vector<int> numbers = { 5, 6, 10, 14, 15, 16, 18, 22 };

    cout << "Enter a number: ";
    cin >> key;
    yesOrNo = checkValidNumInput(to_string(key));

    if (yesOrNo == true) {
        while (yesOrNo) {
            cout << "\tEnter a valid number:\t";
            cin.clear();
            cin >> key;
            yesOrNo = checkValidNumInput(to_string(key));
        }
    }
    //search through the array and if there is a match, print a corresponding statement
    if (binary_search(numbers.begin(), numbers.end(), key)) {
        cout << "The key value " << key << " was found in the array.\n" << endl;
    }
    else {
        cout << "The entered key value was not found in the array.\n" << endl;
    }
}

void worksheet5(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //variables
    int generated, key, timesFound = 0, through = 0;
    bool yesOrNo;
    vector<int> rNumbers;

    cout << "There will be 50 random numbers generated between 1 and 50. " << endl;
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        //generate the random number and push back to the vector with all the numbers
        rNumbers.push_back(rand() % 50 + 1);
    }

    //print 5 rows o
    //print 5 rows of 10 numbers each
    for (int i = 0;  i < 10; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 10; i < 20; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 20; i < 30; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 30; i < 40; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 40; i < 50; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;




    cout << "Enter a number: ";
    cin >> key;
    yesOrNo = checkValidNumInput(to_string(key));

    if (yesOrNo == true) {
        while (yesOrNo) {
            cout << "\tEnter a valid number:\t";
            cin.clear();
            cin >> key;
            yesOrNo = checkValidNumInput(to_string(key));
        }
    }

    //extra: prints the number of times that the number appeared in the array of randomly generated numbers
    while (through < rNumbers.size()) {
        if (rNumbers.at(through) == key)
            ++timesFound;

        through++;
    }
    cout << "Your key number " << key << " was found " << timesFound << " times in the array." << endl << endl;

    cout << "Array Sorted in Descending Order by the Bubble Sort" << endl;
    BubbleSortDescend(rNumbers);
    for (int i = 0; i < 10; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 10; i < 20; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 20; i < 30; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 30; i < 40; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 40; i < 50; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;

    cout << "Array Sorted in Ascending Order by the Bubble Sort" << endl;
    BubbleSortAscend(rNumbers);
    for (int i = 0; i < 10; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 10; i < 20; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 20; i < 30; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 30; i < 40; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;
    for (int i = 40; i < 50; i++) {
        cout << rNumbers.at(i) << "\t";
    }
    cout << endl;




}