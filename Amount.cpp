// AUTHOR: Robert Anderson
// CREATED:  05/22/2015
// PURPOSE:  Assignment1 - Calculate the smallest combination of USD currency pieces from any valid US monetary input
// ARGUMENT: None. User enters in the monetary input manually, using std::cin
// RETURNED VALUES: 0 if successful

#include "stdafx.h"  // standard include for Visual Studio
#include <iostream> // included for cin and cout
#include <iomanip>  // included for formatted outputs
#include <math.h>  // included for the abs(), floor() and log10() functions

using namespace std;

// Declaring user input variable as a long double float.  
// I made this choice to account for the fact that the floor() function seemed to not work for values such as 0.9999
long double userInput;
// Used long int for dollars instead int to account for large dollar values. 
// Used unsigned, since negative values are nonsensical anyways.
unsigned long dollars, spacing;
// Used short int instead of int for the change currency.  These values should never be large enough to warrant using int.
short quarters, dimes, nickels, remaining;


int main()
{
	cout << "Please enter the dollar amount: ";
	cin >> userInput;
	// Added a pseudo user validation step here.
	// This was originally a while loop, but it produced a bug when entering a negative number and then a character with cin.
	userInput = abs(userInput);  // Absolute value of userInput
	// Below displays userInput in the proper formating. 
	// Used multiplication and the floor() function to round down to the hundreths decimal place.
	userInput *= 100; 
	userInput = floor(userInput); 
	userInput /= 100;
	cout << "\n \n" << "The dollar amount input is: ";
	cout << fixed << setprecision(2) << " $" << userInput << endl;
	// set dollars to zero initially, since large values of userInput led to dollars keeping their default runtime values.
	dollars = 0;
	// Storing the whole number portion of userInput as the dollars variable while also coercing to the long int datatype.
	dollars = userInput;
	spacing = log10(dollars) + 1;
	// Extracted the change portion of the currency via subtraction of the whole number portion from the total currency input.
	// Multiplied by 100 in order to use the modulus division operator % and to display currency in integer units.
	// The subtraction must be performed after the multiplication, or else there is a rounding error.
	remaining = (userInput * 100) - (dollars * 100);
	quarters = remaining / 25; remaining %= 25;
	dimes = remaining / 10; remaining %= 10;
	nickels = remaining / 5; remaining %= 5;
	// Omitted the semicolon here on purpose. This is actually one large cout command, broken up for readability.
	cout << setiosflags(ios::right) 
	<< "\t" << "Dollars:     " << dollars << "\n"
	<< "\t" << "Quarters:    " << setw(spacing) << quarters << "\n"
	<< "\t" << "Dimes:       " << setw(spacing) << dimes << "\n"
	<< "\t" << "Nickels:     " << setw(spacing) << nickels << "\n"
	<< "\t" << "Pennies:     " << setw(spacing) << remaining << endl;

	return 0;
}
