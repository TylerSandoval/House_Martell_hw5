//
// Created by Tyler on 10/28/2017.
//
#include<iostream>
#include<string>

#ifndef HOUSE_MARTELL_HW5_ROMAN_H
#define HOUSE_MARTELL_HW5_ROMAN_H

using namespace std;

/* This MUST be in a different source and header file */
class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
    string convertToRoman() const;//The method that helps us take an integer and turn it into a roman numeral
    void convertFromRoman(const string romanValue);  //The method that helps us take an roman numeral in a string and convert it into the integer.
public:
    Roman(); //The default constructor that allows us to make empty objects.

    Roman(const string romanValue); //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()

    Roman operator+(const Roman&) const;  //The left and right operands are Roman objects
    Roman operator+(const int) const; //The left operand is a Roman object, the right is an int number.
    //friend Roman operator+(int num, Roman &x);

    void operator +=(const Roman&);

    unsigned int getValue() const;
    void setValue(unsigned int value);

    //The left and right operands are Roman objects, but the left operand can change.
    void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    Roman operator++();  //The prefix ++ operator

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int , const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};
Roman operator+(const int v, const Roman &r1);

#endif //HOUSE_MARTELL_HW5_ROMAN_H
