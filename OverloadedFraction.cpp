/*
	AUTHOR: Robert Anderson
	CREATED:  07/25/2015
	PURPOSE:  Assignment7 - Modify the Fraction class with overloaded class operators and perform a class to built-in conversion
	ARGUMENT: None
	RETURNED VALUES: 0 if successful
*/

//#include "stdafx.h"  // standard include for Visual Studio
#include <iostream>  // included for cout

using namespace std;

long numerIn; // Input numerator placeholder variable
long denomIn; // Input denominator placeholder variable
bool boolTest;  // Holds the result of a logic test

class Fraction // For creating and manipulating Fractional Number objects
{
	// Class declarations
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int = 1, int = 1); // constructor, sets default values for two integer data members to '1'
		// NOTE: Removed setNumerator() and setDenominator() from the class. I did not need these methods in this assignment
		int getNumerator();
		int getDenominator();
		// Overloaded class operators
		bool operator==(Fraction);  // Checks input fraction for equality with the current Fraction object
		Fraction operator=(const Fraction &);  // Assigns one Fraction object's member data to another Fraction object
		Fraction operator+(Fraction);  // Adds the input object's data to the current object and returns a new Fraction
		operator double();  // Class to built-in conversion, converting the Fraction to a decimal number
};

// class implementations
Fraction::Fraction(int fracNum, int fracDenom) // Constructor, initializes numerator and denominator of the Fraction object
{
	if (fracDenom == 0){ fracDenom = 1; } // Prevents setting denominator to zero
	numerator = fracNum;
	denominator = fracDenom;
	if (fracDenom < 0)
	{
		// This conditional moves the negative sign from the denominator to the numerator
		denominator *= -1;
		numerator *= -1;
	}
}

int Fraction::getNumerator() // Accessor, returns the value of the numerator
{
	return numerator;
}

int Fraction::getDenominator() // Accessor, returns the values of the denominator
{
	return denominator;
}

// Class operator implementations
bool Fraction::operator==(Fraction testEqual)  // Checks input fraction for equality with the current Fraction object
{
	if ( (testEqual.numerator == numerator) && (testEqual.denominator == denominator) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

Fraction Fraction::operator=(const Fraction &setEqual) // Sets current Fraction equal to input, and return a Fraction object
{
	numerator = setEqual.numerator; // Go to setEqual's address and extract the numerator. Assign this value here.
	denominator = setEqual.denominator;
	return *this; // Dereference the *this pointer and return the object *this points to (current object)
}

Fraction Fraction::operator+(Fraction addInput) // Adds the input Fraction to the current Fraction, returning the result
{
	Fraction fracOut(addInput.numerator,addInput.denominator); // creates a Fraction object to output as a summed fraction
	// The following assigns the numerator sum by cross multiplication and addition.
	fracOut.numerator = (fracOut.numerator * denominator) + (fracOut.denominator * numerator);
	fracOut.denominator *= denominator;
	return fracOut;
}

Fraction::operator double() // For converting from a Fraction object to a decimal number (double float)
{
	double decimalOut;
	decimalOut = numerator;
	decimalOut /= denominator; // Performed division after casting in order to capture as many decimal places as possible
	return decimalOut;
}


// Main
int main()
{
	cout << "Enter an integer for the numerator: ";
	cin >> numerIn;
	cout << "Enter an integer for the denominator: ";
	cin >> denomIn;
	Fraction a(numerIn, denomIn);  // Creates a Fraction object based on the user inputs

	cout << "\nEnter an integer for the numerator: ";
	cin >> numerIn;
	cout << "Enter an integer for the denominator: ";
	cin >> denomIn;
	Fraction b(numerIn, denomIn);  // Creates a second Fraction object based on the user inputs

	boolTest = (b.operator==(a));
	if (boolTest == true)
	{
		cout << "\nThe two Fraction objects are equal" << endl << endl;
	}
	else
	{
		cout << "\nThe two Fraction objects are not equal" << endl << endl;
	}

	Fraction c = b.operator+(a);
	cout << "The result of adding the two Fraction objects is: " << c.getNumerator() << '/' << c.getDenominator() << endl;

	cout << "\n*****After using the overloaded assignment operator*****";
	b.operator=(a);
	boolTest = (b.operator==(a));
	if (boolTest == true)
	{
		cout << "\nThe two Fraction objects are equal" << endl << endl;
	}
	else
	{
		cout << "\nThe two Fraction objects are not equal" << endl << endl;
	}

	cout << "\nFraction object using operator double is " << double(a) << endl << endl;

	return 0;
}
