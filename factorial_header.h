#ifndef HELPER_H
#define HELPER_H

// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 3/17/2020
// File: factorial_header.h
// Purpose: Function prototypes

#include <iostream>
using namespace std;

// The greeting() presents a greeting message
// Pre: None
// Post: Outputs a greeting
void greeting();

// The menu() presents the menu of options and prompts for an option
// Pre: The user's menu input of 1 to 5
// Post: Returns the menu input value
int menu();

// The realNumber() prompts for and reads in for a real number
// Pre: None
// Post: Returns the number
double realNumber();

// The realInteger() prompts for and reads in for a real integer
// Pre: None
// Post: Returns the integer
int realInteger();

// The positiveVal() reads in a value and checks whether it's positive or not
// Pre: The user's input number in realNumber()
// Post: Returns true or false depending on whether it's positive or not
bool positiveVal(double value);

// The variableExponent() reads in a value and prompts for an integer
// power to raise that value to
// Pre: The user's input number in realNumber()
// Post: Returns a number based on the value raised to the power
double variableExponent(const double user_num);

// The variableRoot() reads in a value and prompts for an integer root to take
// the value by
// Pre: The user's input number in realNumber()
// Post: Returns the root of the original value based on the integer root
double variableRoot(const double total_root);

// The exponentialFunction() reads in a value and determines e to that value
// power
// Pre: The user's input number in realNumber()
// Post: Returns the e^x based on the value power
double exponentialFunction(const double exponent_val);

// The quit() reads in a value and determines whether to quit the program or
// not
// Pre: None
// Post: Returns the value necessary to quit the program
bool quit();

// The cases() calls functions based on their correlation to the menu options
// Pre: None
// Post: Outputs other functions and their respective parameters/calculations
void cases();

// The closing() presents a closing message
// Pre: None
// Post: Outputs a closing message
void closing();

#include "factorial_functions.hpp"
#endif