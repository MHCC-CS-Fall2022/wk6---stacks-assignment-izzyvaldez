/*
 wk6_stacks_ivaldez.cxx

 Filename:       testDriver.cpp
 Summary:        This program will execute two functions in a driver file that use the static array implementation of the stack to
                 print out the values in the stack from bottom to top and return true if the two stacks have the same values in the same order.

 Specifications: Design, define, implement and test 2 int functions: showBottomToTop( ), compareStacks(stack, stack).

 Test cases:     10 integers entered by the user for the first stack and 10 integers entered by the user for the linked list.

 Author:         Isaias Valdez
 Created:        November 10, 2022
 Summary of Modifications:
 */

#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS and rand()
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include <stack>      // Provides the stack template class
#include "stack1.h"
using namespace std;

void showBottomToTop(stack<int>&, stack<int>&); // prints out the values in the stack from bottom to top

bool compareStacks(stack<int>&, stack<int>&); // returns true if the two stacks have the same values in the same order

int main( )
{
        stack<int> s1;
        stack<int> s2;
        bool stacksMatch;

    cout << "**********STACKS PROGRAM**********\n"
         << "This program will ask the user to enter 10 integers that will be put into a stack and print\n"
         << "them out to the console. The program will then have the user enter 10 more integers and\n"
         << "compare them with the first stack.\n\n\n";

    showBottomToTop(s1, s2);
    stacksMatch = compareStacks(s1, s2);
    if (stacksMatch)
        cout << "Both stacks are a perfect match." << endl;
    else
        cout << "Both stacks DO NOT match." << endl;

    return EXIT_SUCCESS;
}

void showBottomToTop(stack<int>& s1, stack<int>& s2)
{

    int userInput;

cout << "Please enter 10 integers:\n";
//fills the stack s1
for (int i = 0; i < 10; i++)
{
    cin >> userInput;
	s1.push(userInput);
}

// puts the values from the first stack into a second stack in order to
// have the bottom value of s1 be at the top of the stack s2.
for (int i = s1.size() - 1; i >= 0 ; i--)
{
    s2.push(s1.top());
    s1.pop();
}
cout << "Here are the values of the stack from bottom to top:.\n";
while (!s2.empty())
{
	cout << s2.top() << endl;
	s1.push(s2.top());
	s2.pop();
}
}

bool compareStacks(stack<int>& s1, stack<int>& s2)
{
int userInput;
bool isMatch = false;

cout << "Please enter 10 integers and the program will compare it to the first stack:\n";

//fills the stack s1
for (int i = 0; i < 10; i++)
{
    cin >> userInput;
	s2.push(userInput);
}

while(!s1.empty() && !s2.empty())
    {
        if(s1.top() == s2.top())
        {
            isMatch = true;
            s1.pop();
            s2.pop();
        }
        else
        {
            isMatch = false;
            break;
        }
    }
    return isMatch;
}
