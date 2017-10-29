//
// Created by Tyler on 10/28/2017.
//

#include "Roman.h"

unsigned int Roman::convertFromRoman(const string romanValue)
{
    unsigned int sum = 0;

    for (int i = 0; i < romanValue.length(); i++)
    {
        switch(romanValue.at(i))
        {
            case 'M':
                sum += 1000;
                break;

            case 'D':
                sum += 500;
                break;

            case 'C':
                sum += 100;
                break;

            case 'L':
                sum += 50;
                break;

            case 'X':
                sum += 10;
                break;

            case 'V':
                sum += 5;
                break;

            case 'I':
                sum += 1;
                break;

            default:
                cout << romanValue.at(i) << " is not a Roman Numeral!" << endl;
                sum = 0;
                break;

        }//switch
    }
    return sum;
}


//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, const Roman& obj)
{
    if (whatItShouldBe == obj.value)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< obj.value << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

/*
void testOutput()
{
    Roman a("MDCLXVI");
    string b = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", b);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    b = c.convertToRoman();
    checkTest("testOutput #2", "VII", b);

}
 */
