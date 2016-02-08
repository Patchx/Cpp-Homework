// AUTHOR: Robert Anderson
// CREATED:  05/31/2015
// PURPOSE:  Assignment2 - Calculate the cost of a speeding ticket based on user speed and the speed limit.
// ARGUMENT: None. User enters input manually, using std::cin
// RETURNED VALUES: 0 if successful.

//#include "stdafx.h"  // standard include for Visual Studio.
#include <iostream> // included for cin and cout.
#include <iomanip>  // included for formatted outputs.

using namespace std;

// ----- Constants -----
// base fine rate set as a constant float.
const float baseRate = 60.25;

// ----- Variables -----
// Declaring the while loop exit variable to a character, since the 'Y' input character is necessary to maintain the loop.
char yLoop;
// Declaring speed limit and driver's speed as long integers to deal with large input values.
// Declared signed because negative inputs are converted to various positive numbers. This conversion was hard to trace/fix.
long speedLimit, speedInput;
// Declaring the difference between the speed limit and the driver's speed as signed long int.
long speedSubtract;
// Declaring ticket cost as a float.
// Double precision is unnecessary, since the only values that the user inputs are integers.
float ticketCost;

int main()
{
	do {
		// Reseting user inputs to zero at the start of the loop.
		// This is used in combination with cin.clear() to display zeros for speed when the user inputs character data.
		speedLimit = speedInput = speedSubtract = yLoop = 0;
		// Resetting the ticket cost at the start of the loop.
		ticketCost = baseRate;
		// I added a newline escape character at the beginning of the loop instead of the end.
		// I believe this matches the sample output more than the alternative.
		cout << "\nEnter the speed limit: ";
		cin >> speedLimit;
		// NOTE: I found a reference to cin.clear() online.
		// This was a useful bug fix for the infinite loop caused by cin failing to coerce character data into a int variable
		cin.clear();
		cout << "Enter the driver's speed: ";
		cin >> speedInput;
		cin.clear();

		// Convert negative values to zeros:
		if (speedLimit < 0)
		{
			speedLimit = 0;
		}
		if (speedInput < 0)
		{
			speedInput = 0;
		}

		cout << "You were driving " << speedInput << " in a " << speedLimit << " mph zone." << endl;

		// Test if user was speeding
		speedSubtract = speedInput - speedLimit;

		if (speedSubtract > 0)
		{
			// Nested Relational Statement.  Determine the fine based on how fast the user was speeding.
			if (speedSubtract >= 20)
			{
				ticketCost = ticketCost + (ticketCost * 0.20);
			}
			else if (speedSubtract >= 10)
			{
				ticketCost = ticketCost + (ticketCost * 0.10);
			}
			else if (speedSubtract > 5)
			{
				ticketCost = ticketCost + (ticketCost * 0.05);
			}

			cout << fixed << setprecision(2) << "Your fine is: " << "$" << ticketCost << endl;

		}
		else cout << "You were driving at a legal speed. No fines will be charged." << endl;

		cout << "\nEnter Y to continue anything else to stop: ";
		cin >> yLoop;
	}
	while (yLoop == 'Y' || yLoop == 'y');

	return 0;
}
