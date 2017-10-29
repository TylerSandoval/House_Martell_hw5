#include <iostream>
#include <string>

#include "Roman.h"

using namespace std;

// Testing Function Prototypes
void testConstructor();
//void testOperatorPlus();
//void testOperatorPlusEqual();
//void testOperatorIncrement();
//void testConsoleIO();

/* Main Function */
int main()
{
    testConstructor();
    //testOperatorPlus();
    //testOperatorPlusEqual();
    //testOperatorIncrement();
    //testOutput();
    return 0;
};

//testConsoleIO();

/* This MAY be in a different source and header file */

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);

}
/*
void testOperatorPlus()
{
	//Test adding two roman objects
	Roman a("XVI");
	Roman b("MDCLXVI");
	Roman c = a + b;
	checkTest("testOperatorPlus #1", 1682, c);
	//make sure the left and right operands weren't modified
	checkTest("testOperatorPlus #2", 16, a);
	checkTest("testOperatorPlus #3", 1666, b);

	//Test adding an object with an int
	c = a + 52;
	checkTest("testOperatorPlus #4", 68, c);
	//make sure the left operand wasn't modified
	checkTest("testOperatorPlus #5", 16, a);

	//Test adding an int with an object
	c = 578 + a;
	checkTest("testOperatorPlus #6", 594, c);
	//make sure the right operand wasn't modified
	checkTest("testOperatorPlus #7", 16, a);

}

void testOperatorPlusEqual()
{
	//Test adding two roman objects
	Roman a("MLII");
	Roman b("DDCCI");
	a += b;
	checkTest("testOperatorPlusEqual #1", 2253, a);
	//make sure the right operand wasn't modified
	checkTest("testOperatorPlusEqual #2", 1201, b);

	//Test adding on an integer
	b += 17;
	checkTest("testOperatorPlusEqual #3", 1218, b);
}

void testOperatorIncrement()
{
	//Test prefix increment
	Roman a("MLII");
	Roman b("DDCCI");
	b = ++a;
	checkTest("testOperatorIncrement #1", 1053, a);
	checkTest("testOperatorIncrement #2", 1053, b);
}

void testConsoleIO()
{
	//Test reading in the data using the extraction operator >>
	cout << "Enter the text CCLX: ";
	Roman a;
	cin >> a;
	checkTest("testConsoleIO #1", 260, a);

	//Test outputting data using the insertion operator <<
	cout << "testConsoleIO #2" << endl << "If this says 260, this test passed: " << a << endl;

}
*/