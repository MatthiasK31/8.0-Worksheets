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

#include "MyFunctions.h"
#include "GetData.h"
//Make sure to add any other needed include files
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
//SAMPLE  - if you delete this also delete the code in MyFunctions.h
void MySampleFunction(void) {
	double testMe = 0;
	float testMe2 = 0;
	do {
		cout << "enter a double between -1.2  and 25.5: ";
	} while (!(getValidDouble(testMe)) || (testMe < -1.2) || (testMe > 25.5));

	do {
		cout << "enter a float between 5.2  and 6: ";
	} while (!(getValidFloat(testMe2)) || (testMe2 < 5.2) || (testMe2 > 6));
}

bool checkValidNumInput(std::string tester)
{
	//try-catch to validate input
	try {
		double temp = std::stod(tester);
		int num = std::stoi(tester); // error trap this with a try/catch block

		if (temp != num) {
			return true;
		}
		else if (num < 0) {
			return true;
		}
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}

bool checkValidWeekInput(std::string tester)
{
	//try-catch to validate input
	try {
		int num = std::stoi(tester); // error trap this with a try/catch block

		
		if (num < 0 || num > 4) {
			return true;
		}
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}

bool checkValidDistance(std::string tester)
{
	//try-catch to validate input
	try {
		int num = std::stoi(tester); // error trap this with a try/catch block
		double n = std::stod(tester);

		if (num != n)
			return true;
		else if (num < 0)
			return true;
		else if (num == 50 || num == 100 || num == 200 || num == 400 || num == 800 || num == 1000)
			return false;
		else
			return true;
	}
	catch (std::invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}

int favorite(std::vector<int> &numbers, int fav)
{
	int count = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers.at(i) == fav)
			count+= 1;
	}

	return count;
}

std::string isPalindrome(std::string word)
{
	std::string temp = "";

	for (int j = word.length()-1; j >= 0; j--) {
		temp += word.at(j);
	}
	return temp;
}

void printStudents(vector<string> names, vector<string> addresses, vector<string> numbers) 
{
	//print student names
	cout << "Student Names:" << endl;
	for (int i = 0; i < names.size(); i++) {
		if (i < names.size() - 1)
			cout << names.at(i) << ", ";
		else {
			cout << names.at(i) << endl << endl;
		}
	}

	//print student addresses
	cout << "Student Addresses:" << endl;
	for (int i = 0; i < addresses.size(); i++) {
		if (i < addresses.size() - 1)
			cout << addresses.at(i) << ", ";
		else {
			cout << addresses.at(i) << endl << endl;
		}
	}

	//print student numbers
	cout << "Student Phone #s:" << endl;
	for (int i = 0; i < numbers.size(); i++) {
		if (i < numbers.size() - 1)
			cout << numbers.at(i) << ", ";
		else {
			cout << numbers.at(i) << endl << endl;
		}
	}
}

void BubbleSortDescend(std::vector<int>& num)
{
	int i, j, flag = 1;        // set flag to 1 to start first pass
	int temp;                  // holding variable
	int numLength = num.size();
	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (num[j + 1] > num[j])      // ascending order simply changes to &lt;
			{
				temp = num[j];            // swap elements
				num[j] = num[j + 1];
				num[j + 1] = temp;
				flag = 1;                 // indicates that a swap occurred.
			}
		}
	}
	return;          //arrays are passed to functions by address; nothing is returned
}
void BubbleSortAscend(std::vector<int>& num)
{
	int i, j, flag = 1;        // set flag to 1 to start first pass
	int temp;                  // holding variable
	int numLength = num.size();
	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (num[j + 1] < num[j])      // ascending order simply changes to &lt;
			{
				temp = num[j];            // swap elements
				num[j] = num[j + 1];
				num[j + 1] = temp;
				flag = 1;                 // indicates that a swap occurred.
			}
		}
	}
	return;          //arrays are passed to functions by address; nothing is returned
}
