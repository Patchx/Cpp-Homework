/*
	AUTHOR: Robert Anderson
	CREATED:  03/31/16
	PURPOSE:  Write a C program to reverse a user input string
	ARGUMENT: None.  String declared within main()
	RETURNED VALUES: 0 if successful
*/

#include <stdio.h>  // For input and output operations
#include <string.h> // Included for calculating string length

int main()
{
	char name[50];

	printf("Please enter a word to reverse:");
  scanf("%s",name);

	char *fwdName = name; // create pointer variable fwdName and use it to point to the address of a C-string
	int cstrLength = strlen(fwdName); // get length of the C-string and store in cstrLength
	
	printf ("\nName backward is:  "); // Separated this from the while-loop on purpose, for formatting reasons.

	while (cstrLength >= 0)
	{
		printf("%c", *(fwdName + --cstrLength)); // decrease string length by 1, push pointer to new length and print that character
	}

	printf("\n");

	return 0;
}

