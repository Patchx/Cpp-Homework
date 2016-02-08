/*
	AUTHOR: Robert Anderson
	CREATED:  06/28/2015
	PURPOSE:  Assignment4 - Determine the user's letter grade, based on a user defined score and grading curve.
	ARGUMENT: None. User enters input manually, using std::cin
	RETURNED VALUES: 0 if successful
*/

#include "stdafx.h"  // standard include for Visual Studio
#include <iostream>  // included for cin and cout

using namespace std;

//	main()
//  ----
int main()
{
	//	main() Variables 
	//  ---------
	int userGrade, userCurve, i;
	char yLoop;
	char letterGrades[5] = { 'A', 'B', 'C', 'D', 'F' };
	int gradeThresholds[5] = {90, 80, 70, 60,0};
	/*
		Note:  
		  I did not use functions within this program, nor did I use symbolic constants for array length.
		Given the limited scope of this program, trying to 'modulize' a short program seemed unnecessary.
		I did not use symbolic constants for array length, since the user should not be able to modify these arrays,
		and there should be no need to change these array lengths in future versions of the program.
	*/

	//	main() Commands 
	//  ---------
	do
	{
		cout << "Enter the student grade (0 - 100): ";
		cin >> userGrade; cin.clear(); 
		// cin.clear() helps prevent infinite loops if the user enters int data here, then enters char data after looping once
		cout << "Enter the curve amount (0 - 30): ";
		cin >> userCurve; cin.clear();
		userGrade = userGrade + userCurve;

		// Linear Search through the numerical thershold array and assigning a letter grade based on the char array.
		for (i = 0; i < 5; i++)
		{
			if (userGrade >= gradeThresholds[i])
			{
				cout << "Student letter grade: " << letterGrades[i] << endl;
				break; // break is added here to stop the for loop once the letter grade is assigned
			}
		}

		cout << "\nEnter Y or y to continue. Anything else to quit: ";
		cin >> yLoop; cin.clear();
		cout << "\n";  // This was added to better match the sample output.
	}
	while (yLoop == 'Y' || yLoop == 'y');
	
	return 0;
}

