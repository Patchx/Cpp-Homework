/*
	AUTHOR: Robert Anderson
	CREATED:  07/19/2015
	PURPOSE:  Assignment6 - Create a Fraction class and display fractional numbers
	ARGUMENT: None
	RETURNED VALUES: 0 if successful
*/

#include "stdafx.h"  // standard include for Visual Studio
#include <iostream>  // included for cout

using namespace std;

class Fraction // For creating and manipulating Fractional Number objects
{
	// Class declarations
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int = 1, int = 1); // constructor, sets default values for two integer data members to '1'
		void setNumerator(int);
		void setDenominator(int);
		int getNumerator();
		int getDenominator();
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

void Fraction::setNumerator(int setNum) // Mutator, changes the value of the numerator
{
	numerator = setNum;
}

void Fraction::setDenominator(int setDenom) // Mutator, changes the value of the denominator
{
	if (setDenom == 0){ setDenom = 1; } // Prevents setting denominator to zero
	if (setDenom < 0)
	{
		// This conditional moves the negative sign from the denominator to the numerator
		setDenom *= -1;
		numerator *= -1;
	}
	denominator = setDenom;
}

int Fraction::getNumerator() // Accessor, returns the value of the numerator
{
	return numerator;
}

int Fraction::getDenominator() // Accessor, returns the values of the denominator
{
	return denominator;
}

// Main
int main()
{
	Fraction a, b(4, 0); // Instantiates two Fraction objects 'a' and 'b'. The first object uses the default constructor.
	cout << "Value of the first Fraction object is " << a.getNumerator() << '/' << a.getDenominator() << endl;
	cout << "Value of the second Fraction object is " << b.getNumerator() << '/' << b.getDenominator() << endl;

	b.setNumerator(3);
	b.setDenominator(-5);

	cout << "\nAfter changing the values of the second Fraction object" << endl;
	cout << "Value of the second Fraction object is " << b.getNumerator() << '/' << b.getDenominator() << endl;

	return 0;
}

