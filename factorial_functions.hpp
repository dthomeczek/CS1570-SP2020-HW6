// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 3/17/2020
// File: factorial_functions.hpp
// Purpose: Function definitions

#include <iostream>
using namespace std;

// Brief introductory message
void greeting()
{
  cout << "Welcome to the advanced mathematical calculator!" << endl;
  return;
}

// Prompts user for an input via the menu
int menu()
{
  int menu_input; // User's menu input

  cout << "Please select an option from the menu below. (1-5)" << endl << 
  endl;

  cout << "   === Menu ===   " << endl;
  cout << "   ------------   " << endl;
  cout << "1. Enter a real number" << endl;
  cout << "2. Power the number" << endl;
  cout << "3. Root the number" << endl;
  cout << "4. Exponential function (e^x)" << endl;
  cout << "5. Quit" << endl << endl;
  cin >> menu_input;

  return menu_input;
}

// Checks for a positive real number
double realNumber()
{
  const int NO_NEGATIVE = 0; // Checks to ensure value is positive

  double value; // User's number value
  do
  {
    cout << "Enter a positive number:" << endl;
    cin >> value;
  } while (value <= NO_NEGATIVE);
  
  return value;
}

// Checks for a positive real integer
int realInteger()
{
  const int NO_NEGATIVE = 0; // Checks to ensure value is positive

  int value; // User's number value
  do
  {
    cout << "Enter a positive integer:" << endl;
    cin >> value;
  } while (value <= NO_NEGATIVE);
  
  return value;
}

// Tests to ensure values are positive
bool positiveVal(double value)
{
  const int NO_NEGATIVE = 0; // Used to determine only positive values
  
  bool positive_num; // Tests for a positive base value

  if (value < NO_NEGATIVE)
  {
    positive_num = false;
  }
  else
  {
    positive_num = true;
  }
  
  return positive_num;
}

// Raises the user's value to the user's chosen exponent
double variableExponent(const double user_num)
{
  const int ITERATION_START = 1; // The starting value of i in the for loop

  int power; // The power the base value will be raised to
  double answer; // The outcome after the value has been raised to the power

  power = realInteger();
  answer = user_num;

  for (int i = ITERATION_START; i < power; i++)
  {
    answer *= user_num;
  }
  return answer;
}

// Takes the user's value to thre user's chosen root
double variableRoot(const double total_root)
{
  const int I_START = 0; // Iteration start for i
  const int J_START = 1; // Iteration start for j / used for the subtractor
                         // in the equation
  const int ROOT_ITERATION = 20; // Iteration end for i

  double root_val; // The actual root after calculating the root power
  double root; // The outcome of the value taken to the root
  int num_root; // The root the value will be taken to
  
  num_root = realInteger();
  root = total_root;


  for (int i = I_START; i < ROOT_ITERATION; i++)
  {
    root_val = root;
    for (int j = J_START; j < num_root - J_START; j++)
    {
      root_val = root_val * root;
    }
    
    root = ((num_root - J_START) * root + (total_root) / (root_val)) 
    / num_root;
  }
  return root;
}

// Takes e to the user's value
double exponentialFunction(const double exponent_val)
{
  double sum = 0;

  for (int i = 10; i > 0; --i )  
    sum = 1 + exponent_val * sum / i;

  return sum;
}

// Quits the switch case
bool quit()
{
  bool end;
  return end = true;
}

// The ovarall switch case that determines which functions will be called
// based on menu input
void cases()
{
  bool exit = false; // Presets the user to not immediately quit by default
  bool check_one = false; // Assigns option one initially to not yet chosen
  bool positive_val = false; // Checks whether the value is positive or not
  int menu_val; // Holds the value for the menu option
  double root_val; // Holds the value of the final root
  double user_num; // Used to hold the real positive number
  double exponential; // Holds the value of the final exponential (e^x) value
  double exponent; // Holds the value of the final powered number

  do
  {
    menu_val = menu(); // Assigns the return of menu() to a variable
    switch (menu_val)
    {
      case 1: // Prompts for a real, positive number
        do
        {
          user_num = realNumber(); // Assigns the return of realNumber() to a
                                   // variable
          positive_val = positiveVal(user_num);
        } while (positive_val == false);
        
        check_one = true; // Sets the case of whether the user started with 
                          // option one or not to true since they picked
                          // option one
        break;

      case 2: // Raises the user's number from case 1 to an integer exponent 
              // of their choice
        if (check_one == true)
        {
          exponent = variableExponent(user_num);
          cout << "The value based on your inputs is: " << exponent << endl;
        }
        else
        {
          cout << "Please choose option 1 first!" << endl;
        }
        break;

      case 3: // Takes the user's number from case one to an integer root
              // of their choice
        if (check_one == true)
        {
          root_val = variableRoot(user_num);
          cout << "The root based on your inputs is: " << root_val << endl;
        }
        else
        {
          cout << "Please choose option 1 first!" << endl;
        }
        break;

      case 4: // Takes the user's number from case 1 and raises e to that 
              // value as a power
        if (check_one == true)
        {
          exponential = exponentialFunction(user_num);
          cout << "The exponential number based on your input is: " <<
          exponential << endl;
        }
        else
        {
          cout << "Please choose option 1 first!" << endl;
        }
        break;

      case 5: // Quits the switch case by setting exit to true
        exit = quit();
        break;

      default: // Reprompts the menu in the case of an invalid input
        menu();
        break;
    }
  } while (exit != true);
  
  return;
}

// A brief conclusory message
void closing()
{
  cout << "Thank you for using the mathematical functions calculator!" <<
  endl;
  return;
}