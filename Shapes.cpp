//File Name: Shapes.cpp
//Created By: Robert Anderson
//Created On: 08/02/2015
//Program Purpose: To demonstrate inheritance and polymorphism by utilizing a class hierarchy of shapes

#include "stdafx.h" // Standard include for Visual Studio
#include <iostream> // included for cin and cout
#include <iomanip> // included for formatted outputs
using namespace std;

/******************Parallelogram Class****************************/
//class declaration section
class Parallelogram
{
private:
	void setAngles(unsigned int, unsigned int); // NOTE: All ints are unsigned, because negatives would make no sense here
protected:
	//data members
	unsigned int angleA;
	unsigned int angleB;
	unsigned int sideA;
	unsigned int sideB;
	
public:
	Parallelogram(unsigned int, unsigned int, unsigned int = 90, unsigned int = 90); //constructor with default arguments for angles A and B
	unsigned int getAngleA(); // Returns protected angle data
	unsigned int getAngleB(); // Returns protected angle data
	void setSideA(unsigned int); // Mutator for protected side data
	void setSideB(unsigned int); // Mutator for protected side data
	unsigned int getSideA(); // Returns protected side data
	unsigned int getSideB(); // Returns protected side data
	unsigned int computePerimeter(); // Returns the perimeter
	unsigned int computeArea(); // Returns the area
};


// Parallelogram method implementations:

unsigned int Parallelogram::getAngleA()
{ 
	return angleA;
}

unsigned int Parallelogram::getAngleB()
{ 
	return angleB; 
}

unsigned int Parallelogram::getSideA()
{ 
	return sideA; 
}

unsigned int Parallelogram::getSideB()
{ 
	return sideB; 
}

void Parallelogram::setSideA( unsigned int inputSideA)
{ 
	sideA = inputSideA; 
}

void Parallelogram::setSideB(unsigned int inputSideB)
{ 
	sideB = inputSideB; 
}

unsigned int Parallelogram::computePerimeter()
{ 
	return 2 * (sideA + sideB); 
}

unsigned int Parallelogram::computeArea()
{ 
	return sideA * sideB; 
}

void Parallelogram::setAngles(unsigned int paraAngleA, unsigned int paraAngleB)
{ 
	if (paraAngleA + paraAngleB != 180)
	{
		paraAngleA = 90;
		paraAngleB = 90;
	}
	angleA = paraAngleA;
	angleB = paraAngleB;
}

Parallelogram::Parallelogram(unsigned int paraSideA, unsigned int paraSideB, unsigned int paraAngleA, unsigned int paraAngleB)
{
	sideA = paraSideA;
	sideB = paraSideB;
	setAngles(paraAngleA, paraAngleB);
}


/******************Rectangle Class****************************/
//class declaration section
class Rectangle : public Parallelogram
{
public:
	Rectangle(unsigned int, unsigned int); //constructor	
};

// Rectangle constructor implementation
Rectangle::Rectangle(unsigned int rectSideA, unsigned int rectSideB) : Parallelogram(rectSideA, rectSideB, 90, 90){}


/******************Square Class****************************/
//class declaration section
class Square : public Rectangle
{
public:
	Square(unsigned int); //constructor
	void setSideA(unsigned int); // Overloaded mutator, modified to set both sideA and sideB to the same value
	void setSideB(unsigned int); // Overloaded mutator, modified to set both sideA and sideB to the same value
};

void Square::setSideA(unsigned int inputSideA)
{
	sideA = inputSideA;
	sideB = inputSideA;
}

void Square::setSideB(unsigned int inputSideB)
{
	sideA = inputSideB;
	sideB = inputSideB;
}

// Square constructor implementation
Square::Square(unsigned int squareSideA) : Rectangle(squareSideA, squareSideA){}

// End Class details *************************************************


void displayData(Parallelogram); // function prototype for displaying Object values in the Parallelogram or derived classes


// Main:
int main()
{
	// Variable Declarations
	unsigned int userSideA; // for user input of side length data
	unsigned int userSideB; // for user input of side length data
	unsigned int userAngleA; // for user input of angle data
	unsigned int userAngleB; // for user input of angle data

	cout << "Testing the Square Class" << endl;
	cout << "Enter length of side: ";
	cin >> userSideA;
	Square squareA(userSideA); // Creates Square object 'A' with sides equal to user input
	displayData(squareA);

	cout << "Testing the Rectangle Class" << endl;
	cout << "Enter length of first side: ";
	cin >> userSideA;
	cout << "Enter length of second side: ";
	cin >> userSideB;
	Rectangle rectA(userSideA, userSideB); // Creates Rectangle object 'A' with sides equal to user input
	displayData(rectA);

	cout << "Testing the Parallelogram Class" << endl;
	cout << "Enter length of first side: ";
	cin >> userSideA;
	cout << "Enter length of second side: ";
	cin >> userSideB;
	cout << "Enter the first angle: ";
	cin >> userAngleA;
	cout << "Enter the second angle: ";
	cin >> userAngleB;
	Parallelogram paraA(userSideA, userSideB, userAngleA, userAngleB); // Creates Parallelogram Object 'A' with user inputs
	displayData(paraA);

	return 0;
}


/****************************************************************************/
/* Because of inheritance and polymorphism the displayData function can be 
   passed either a Parallelogram object,  Rectangle object, or a Square 
   object to display each object's data.                                    */
void displayData(Parallelogram shape) // Calls Parallelogram member functions to output Object data and calculations
{
	cout << "\nThe length of side A is " << shape.getSideA() << endl;
	cout << "The length of side B is " << shape.getSideB() << endl;
	cout << "Angle A is " << shape.getAngleA() << " degrees" << endl;
	cout << "Angle B is " << shape.getAngleB() << " degrees" << endl;
	cout << "The perimeter is " << shape.computePerimeter() << endl;
	cout << "The area is " << shape.computeArea() << endl << endl;
}

