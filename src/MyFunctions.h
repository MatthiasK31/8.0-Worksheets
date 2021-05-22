#pragma once
//Add any prototypes here
//if you didn't create any functions used exclusively for this worksheet, you won't use this file.
#include <string>
#include <vector>

//SAMPLE - if you delete this also delete the code in MyFunctions.cpp
void MySampleFunction(void);
bool checkValidNumInput(std::string);
bool checkValidWeekInput(std::string);
bool checkValidDistance(std::string);
int favorite(std::vector<int>&, int);
std::string isPalindrome(std::string);
void printStudents(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);
void binarySearch(std::vector<int>, int, int, int);
void BubbleSortDescend(std::vector<int>&);
void BubbleSortAscend(std::vector<int>&);

