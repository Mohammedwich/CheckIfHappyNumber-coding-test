// Data structures practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int checkIfHappy(int theNumber)
{
	int digitSquaredSum = 0;
	int currentNumber = theNumber;
	static int iterations = 0; //To stop endless recursion

	while (theNumber != 0 && iterations < 25)
	{
		int digit = theNumber % 10;
		theNumber = theNumber / 10;
		digitSquaredSum += (digit * digit);
	}

	currentNumber = digitSquaredSum;
	++iterations;

	if (iterations > 24)
	{
		iterations = 0;
		return 0;
	}
	else if (currentNumber > 1)
	{
		checkIfHappy(currentNumber);
	}
	else if (currentNumber == 1)
	{
		iterations = 0;
		return 1;
	}
	else
	{
		iterations = 0;
		return 0;
	}
}


int main()
{

	string line;

	cout << "Input a number to find out if it is a happy number(1) or not a happy number(0) : " << endl;

	while (getline(cin, line))
	{
		int input = stoi(line);
		int result = checkIfHappy(input);
		cout << result << endl;
	}

	/*
	std::cout << std::endl << std::endl;
	int leaveProgram;
	std::cout << "enter anything to exit: ";
	std::cin >> leaveProgram;
	*/
	return 0;
}

