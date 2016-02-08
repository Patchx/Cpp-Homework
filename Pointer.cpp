/*
	AUTHOR: Robert Anderson
	CREATED:  07/11/2015
	PURPOSE:  Assignment5 - Use pointers to print a string and the reverse order of the string
	ARGUMENT: None.  String declared within main()
	RETURNED VALUES: 0 if successful
*/

#include "stdafx.h"  // standard include for Visual Studio
#include <iostream>  // included for cout
#include <cstring>  // included for strlen(), allowed in assignment details

using namespace std;

int main()
{
	char *fwdName = "John Doe"; // create pointer variable fwdName and use it to point to the address of a C-string
	int cstrLength = strlen(fwdName); // get length of the C-string and store in cstrLength
	
	cout << "Name is: " << fwdName << endl;
	cout << "Name backward is:  "; // Separated this from the while-loop and omitted endl on purpose, for formatting reasons.

	while (cstrLength >= 0)
	{
		cout << *(fwdName + --cstrLength); // decrease string length by 1, push pointer to new length and print that character
	}

	cout << "\nName is: " << fwdName << endl;

	return 0;
}

