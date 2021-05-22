/*
Matthias Kim
Lab 8.0
21 May 2021

WKST 1 Extra: allow user to choose how many people ages should be entered for
WKST 2 Extra: added some extra words to have the program check for palindromes
WKST 3 Extra: allow user to see info for a certain person
WKST 4 Extra: allow user to make 5 guesses for numbers in the array
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
    double total = 0, average = 0;

    //add values to the vector variable
    vector<double> finalGrade;
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
    int age, nPpl = 0;
    int moreThan = 0; int lessThan = 0;
    bool yesOrNo = false;

    //extra: allow user to choose how many people ages should be entered for
    cout << "How many people would you like to enter ages for? ";
    while (!getValidInt(nPpl)) {
        cout << "\tEnter a valid number:\t";
    }

    for (int i = 0; i < nPpl; i++) {
        do {
            cout << "Enter age #" << i + 1 << ":  ";
        } while (!(getValidInt(age)) || age < 0);
        
        pAges.push_back(age);

        if (age > 15)
            moreThan++;
        else if (age < 15)
            lessThan++;

        yesOrNo = false;
    }

    cout << "There are " << moreThan << " people who are older than 15.\n" << endl;




    //5
    string daysOfTheWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    vector<double> dailySales;
    double salesForDay = 0;
    int response; string answer = ""; string temp = "";

    for (int i = 0; i < size(daysOfTheWeek); i++) {
        cout << "Enter the total sales for " << daysOfTheWeek[i] <<": ";
        cin >> salesForDay;
        dailySales.push_back(salesForDay);
        cout << "There was a total of $" << salesForDay << " on " << daysOfTheWeek[i] << "!" << endl;
    }

    while (true) {
        cin.ignore(INT_MAX, '\n');
        cout << "Choose a day of the week to view its total sales:  ";
        while (!getValidInt(response) || response < 0 || response > 5) {
            cout << "\tEnter a valid number:\t";
        }

        int temp = response - 1;
        cout << "There was a total of $" << dailySales.at(temp) << " on " << daysOfTheWeek[temp] << "!" << endl;


        cout << "Would you like to continue? ";
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        if (answer == "no")
            break;
    } 


}

void worksheet2(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    
    //1
    vector<int> numbers;
    int num, fav, timesFound; 
    bool yesOrNo;

    for (int i = 0; i < 10; i++) {
        cout << "Enter number #" << i + 1 << ": ";
        while (!getValidInt(num)) {
            cin.ignore(INT_MAX, '\n');
            cout << "\tEnter a valid number:\t";
        }
        
        numbers.push_back(num);
    }

    //ask user to enter his/her favorite number
    cout << "Additionally, please enter your favorite number: ";
    while (!getValidInt(fav)) {
        cin.ignore(INT_MAX, '\n');
        cout << "\tEnter a valid number:\t";
    }

    //call function, get the returned value, then print out a final message
    timesFound = favorite(numbers, fav);
    cout << "In your 10 numbers that you entered, your favorite number " << fav << " was found a total of " << timesFound << " times." << endl;


    //2
    //added a few extra words to the vector
    vector<string> words = { "radar", "warts", "evil", "racecar", "toot", "cola", "civic" };
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
    int distance = 0;
    bool yesOrNo;

    //ask for distance
    cout << "Which distance would you like to check the time for? ";
    while (!getValidInt(distance)) {
        cin.ignore(INT_MAX, '\n');
        cout << "\tEnter a valid number:\t";
    }
    
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

    cout << studentNames.at(2) << endl << studentAddys.at(2) << endl << studentNumbers.at(2) << endl;

    //extra: allow user to see info for a certain person
    bool exitOrNo = false;
    int chosen;
    while (exitOrNo == false) {
        cout << "Would you like to see the information of a certain person? Select the corresponding number:\n1. Shaiiko Lebleu\n2. John Wick\n3.Tony Stark\n4.Steve Rogers\n5.Peter Parker\nEnter the number 42 to exit.\n";
        while (!getValidInt(chosen) || chosen < 0) {
            cin.ignore(INT_MAX, '\n');
            cout << "\tEnter a valid number:\t";
        }
        cout << studentNames.at(chosen) << endl << studentAddys.at(chosen) << endl << studentNumbers.at(chosen) << endl;
        if (chosen == 42)
            break;
    }

}

void worksheet4(string namedItem) {
    std::cout << endl << "worksheet: " << namedItem << endl << endl;
    //1

    //variables
    int ticket;
    string response = "";
    bool yesOrNo, yep = true, aMatch = false;
    vector<int> winningNumbers = { 307, 521, 416, 154, 243, 89 };

    //ask for a ticket value and error trap input
    cout << "Enter your ticket number!!  ";
    while (!getValidInt(ticket)) {
        cin.ignore(INT_MAX, '\n');
        cout << "\tEnter a valid number:\t";
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
    int key = 0;
    aMatch = false;
    vector<int> numbers = { 5, 6, 10, 14, 15, 16, 18, 22 };
    vector<int> guesses;

    //extra: allow user to make 5 guesses for numbers in the array
    for (int i = 0; i < 5; i++) {
        cout << "Enter a number: ";
        while (!getValidInt(key)) {
            cin.ignore(INT_MAX, '\n');
            cout << "\tEnter a valid number:\t";
        }

        guesses.push_back(key);
    }
    cout << endl;
    //print results
    for (int i = 0; i < guesses.size(); i++) {
        binarySearch(numbers, 0, numbers.size(), guesses.at(i));
        cout << endl;
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

    //ask for number
    cout << "Enter a number: ";
    cin.ignore(INT_MAX, '\n');
    while (!getValidInt(key)) {
        cout << "\tEnter a valid number:\t";
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