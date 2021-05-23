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
#include <regex>

using std::cin;
using std::cout;

using namespace std;
bool checkValidDistance(int& t_int)
{
	std::string intScratch = "";
	bool isValid = true;


	getline(cin, intScratch);
	//remove all whitespace
	std::regex r("\\s+");
	intScratch = std::regex_replace(intScratch, r, "");
	//rev 2 make sure only valid characters for an integer number are in the string
	isValid = intScratch.find_first_not_of("-0123456789") == std::string::npos;
	//Only 1 '-' allowed
	if (std::count(intScratch.begin(), intScratch.end(), '-') > 1) {
		isValid = false;
	}
	//make sure '-' is first char only
	else if (std::count(intScratch.begin(), intScratch.end(), '-') > 0) {
		if (intScratch.at(0) != '-') {
			isValid = false;
		}
	}
	//convert ONLY if string is contains valid integer characters
	//all errors caught 
	if (isValid) {
		try {
			t_int = stoi(intScratch);
		}
		catch (...) { //<---catches ALL errors - may want to give the user a more specific message.  Shown in next function
			//bad user entry - don't care what it is, return invalid
			isValid = false;
		}
	}
	if (t_int == 50 || t_int == 100 || t_int == 200 || t_int == 400 || t_int == 800 || t_int == 1000)
		isValid = true;
	else
		isValid = false;

	return isValid;
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

void binarySearch(vector<int> &array, int lowerbound, int upperbound, int key)
{
	int position;
	int comparisonCount = 1;  // counting number of comparisons (optional)
	// To start, find the subscript of the middle position.
	position = (lowerbound + upperbound) / 2;
	while ((array[position] != key) && (lowerbound <= upperbound))
	{
		comparisonCount++;
		if (array[position] > key)  // If thenumber is &gt; key,
		{  // decrease position by one.
			upperbound = position - 1;
		}
		else
		{ // Else, increase position by one.
			lowerbound = position + 1;
		}
		position = (lowerbound + upperbound) / 2;
	}
	if (lowerbound <= upperbound)
	{
		cout << "Number: " << key << endl;
		cout << "The number was found in array subscript " << position << endl;
		cout << "The binary search found the number after " << comparisonCount << " comparisons.\n";

	}
	else {
		cout << "Number: " << key << endl;
		cout << "Sorry, the number is not in this array.\nThe binary search made " << comparisonCount << " comparisons.\n";
	}
	return;
}

bool guesses(int& t_int) 
{
	std::string intScratch = "";
	bool isValid = true;


	getline(cin, intScratch);
	//remove all whitespace
	std::regex r("\\s+");
	intScratch = std::regex_replace(intScratch, r, "");
	//rev 2 make sure only valid characters for an integer number are in the string
	isValid = intScratch.find_first_not_of("-0123456789") == std::string::npos;
	//Only 1 '-' allowed
	if (std::count(intScratch.begin(), intScratch.end(), '-') > 1) {
		isValid = false;
		return isValid;
	}
	//make sure '-' is first char only
	else if (std::count(intScratch.begin(), intScratch.end(), '-') > 0) {
		if (intScratch.at(0) != '-') {
			isValid = false;
			return isValid;
		}
	}
	//convert ONLY if string is contains valid integer characters
	//all errors caught 
	if (isValid) {
		try {
			t_int = stoi(intScratch);
		}
		catch (...) { //<---catches ALL errors - may want to give the user a more specific message.  Shown in next function
			//bad user entry - don't care what it is, return invalid
			isValid = false;
		}
	}
	if (t_int > 22)
		isValid = false;
	else
		isValid = true;

	return isValid;
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
