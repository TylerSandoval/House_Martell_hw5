//
// Created by Tyler on 10/28/2017.
//

#include "Roman.h"

void Roman::convertFromRoman(const string roman)
{
    string romanValue;
    int number = 0;

    for(int count = (roman.length()-1); count >=0; count--)
    {
        if(roman.at(count) == 'I')
        {
            number = number +1;
        }
        else if(roman.at(count) == 'V')
        {
            if(roman.at(count-1) == 'I')
            {
                number = number + 4;
                count = count - 1;
            }
            else
            {
                number = number + 5;
            }
        }
        else if(roman.at(count) == 'X')
        {
            number = number +10;
        }
        else if(roman.at(count) == 'L')
        {
            if(count > 0)
            {
                if(roman.at(count-1) == 'X')
                {
                    number = number + 40;
                    count = count - 1;
                }
                else
                {
                    number = number + 50;
                }
            }
            else
            {
                number = number + 50;
            }
        }
        else if(roman.at(count) == 'C')
        {
            number = number +100;
        }
        else if(roman.at(count) == 'D')
        {
            if(count > 0)
            {
                if(roman.at(count-1) == 'X')
                {
                    number = number + 400;
                    count = count - 1;
                }
                else
                {
                    number = number + 500;
                }
            }
            else
            {
                number = number + 500;
            }
        }

        else if(roman.at(count) == 'M')
        {
            number = number +1000;
        }
        else
        {
            cout << roman.at(count)<< " is not a roman number "<< endl;
        }
    }
    value = number;
    cout << "\tRoman number " << roman << " length  " << roman.length() << endl;
    cout << "\tDecimal Value: " << value << endl;
}

string Roman::convertToRoman() const {
    string number = "";
    int decimal = value;
    while(decimal > 0)
    {//
        if(decimal >= 1000)
        {
            number = number + 'M';
            decimal = decimal - 1000;
        }
        else if(decimal >= 500)
        {
            number = number + 'D';
            decimal = decimal - 500;
        }
        else if(decimal >= 100)
        {
            number = number + 'C';
            decimal = decimal - 100;
        }
        else if(decimal >= 50)
        {
            number = number + 'L';
            decimal = decimal - 50;
        }
        else if(decimal >= 10)
        {
            number = number + 'X';
            decimal = decimal - 10;

        }
        else if(decimal >= 5)
        {
            number = number + 'V';
            decimal = decimal - 5;

        }
        else if(decimal >= 1)
        {
            number = number + 'I';
            decimal = decimal - 1;

        }
    }
    return number;
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
//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs )
{
    if (whatItShouldBe == whatItIs)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< whatItIs << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

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

Roman operator+(const int v, const Roman& r1)
{
    Roman r;
    r.setValue(v + r1.getValue());
    return r;
}


Roman Roman::operator+(const Roman &obj) const
{
    Roman r;
    r.value = this->value + obj.value;
    return r;
}

Roman Roman::operator+(const int num) const
{
    Roman r;
    r.value = this->value + num;
    return r;
}


void Roman::operator+=(const Roman &obj)
{
    this->value += obj.value;

}

void Roman::operator+=(const int number)
{
    this->value+=number;
}

Roman Roman::operator++()
{
    value++;
    Roman r;
    r.value = value;
    return r;
}

Roman::Roman(const string romanValue)
{
        convertFromRoman(romanValue);        //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()
}

Roman::Roman()
{
    value = 0;
}

unsigned int Roman::getValue() const {
    return value;
}

void Roman::setValue(unsigned int value) {
    Roman::value = value;
}







