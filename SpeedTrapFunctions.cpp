/*
	AUTHOR: Robert Anderson
	CREATED:  06/20/2015
	PURPOSE:  Assignment3 - Update the SpeedTrap program to include two functions and a random number for the speed limit. 
	ARGUMENT: None. User enters input manually, using std::cin
	RETURNED VALUES: 0 if successful.
*/

#include "stdafx.h"  // standard include for Visual Studio
#include <iostream>  // included for cin and cout
#include <iomanip>   // included for formatted outputs and setprecision()
#include <cstdlib>   // included for rand() and srand(), psuedo random number functions
#include <ctime>     // included for time(), a CPU time extracting function

using namespace std;


//	Function Protoypes
//  ------------------
int speedRNG();  // Reseed the random number generator and generate a number for the speed limit
void ticketCost(int);  // Acquire user speed and speed limit, then notify the user of any speeding charges
	/* NOTE:
		I chose to declare void for ticketCost() and separated this function from the loop exit boolean. I did this 
		so that this function does not necessarily have to be the ending point of the main loop in future modifications 
	*/


//	Global Constants
//  ----------------
const float baseRate = 60.25;  // Double precision is unnecessary here.
    // I almost used the 'register' storage category for baseRate, but I didn't to avoid potential cross platform bugs.


//	main()
//  ----
int main()
{
	//	main() Variables 
	//  ---------
	char yLoop;

	//	main() Commands 
	//  ---------
	do 
	{
		ticketCost(speedRNG());
		cout << "\nEnter Y to continue anything else to stop: ";
		cin >> yLoop;
	}
	while (yLoop == 'Y' || yLoop == 'y');

	return 0;
}

// Function Definitions
// --------------------

// speedRNG() - Random Number Generator for the speed limit
// AUTHOR: Robert Anderson
// CREATED : 06 / 20 / 2015
int speedRNG()
{
	srand(time(NULL));  // Setting the random seed based on the CPU time

	return 25 + rand() % (65 + 1 - 25);  // returng a random number between 25 and 65 (inclusive)
}

// ticketCost() - Calculates and outputs the ticket cost, based on speed limit and user defined driving speed
// AUTHOR: Robert Anderson
// CREATED : 06 / 20 / 2015
void ticketCost(int speedLimit)
{
	//	ticketCost() Variables 
	//  ----------------------
	// Declaring the driver's speed and the difference in speed as long integers to deal with large input values.
	// Declared signed because unsigned negative inputs are converted to various positive numbers.
	long speedInput, speedSubtract;
	float ticketCost;  // Double precision is unnecessary here

	//	ticketCost() Commands 
	//  ---------------------
	cout << "\nThe speed limit is " << speedLimit;
	cout << "\nEnter the driver's speed: ";
	cin >> speedInput;
	cin.clear();
	/* NOTE:
		I found a reference to cin.clear() online. This was a useful bug fix for the infinite loop caused by cin
		failing to coerce character data into a int variable.
	*/

	// Convert negative input to zero:
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
			ticketCost = baseRate + (baseRate * 0.20);
		}
		else if (speedSubtract > 10)  // Made sure to fix my previous error here. Definitely a 'D'oh!' moment..
		{
			ticketCost = baseRate + (baseRate * 0.10);
		}
		else if (speedSubtract > 5)
		{
			ticketCost = baseRate + (baseRate * 0.05);
		}
		else
		{
			ticketCost = baseRate;
		}
		cout << fixed << setprecision(2) << "Your fine is: " << "$" << ticketCost << endl;
	}
	else cout << "You were driving at a legal speed. No fines will be charged." << endl;

	// Declared as void, so the function returns nothing.
	return;
}
