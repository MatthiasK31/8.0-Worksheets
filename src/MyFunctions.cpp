//Add any function code goes here
//if you didn't create any functions used exclusively for this worksheet you won't use this file.

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
		if (num < 0) {
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
