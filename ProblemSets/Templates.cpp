/*************************************************************
 * 1. Name:
 *      Braeden Pope, Ethan Mangum, Aiden Patterson
 * 2. Assignment Name:
 *      Practice 07: Templates
 * 3. Assignment Description:
 *      Two templates: one of a function, one of a class
 * 4. What was the hardest part? Be as specific as possible.
 *      Getting the template syntax right
 * 5. How long did it take for you to complete the assignment?
 *      1 hour
 **************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/***************************************
 * PROMPT
 **************************************/
template <class T>
void prompt(T & value, const char* message)
{
   while (true)
   {
      // Instructions
      cout << message << ": ";
      cin >> value;

      // Check for error
      if (cin.fail())
      {
         cerr << "ERROR, try again\n";
         cin.clear();
         cin.ignore(256, '\n');
      }
      else
         return;
   }
}



/***************************************
 * STACK
 **************************************/
template <class T>
class Stack
{
public:
   Stack() : numElements(0) {}

   // Add an element to the stack
   void push(T value);
   

   // Remove an element from the stack
   void pop()
   {
      if (numElements)
         numElements--;
   }

   // Retrieve the top-most element
   T top();

private:
   T data[10];
   int numElements;
};

template <class T>
void Stack <T> :: push(T value) {
      if (numElements < 10)
         data[numElements++] = value;
}

template <class T>
T Stack <T> :: top()
{
   if (numElements)
      return data[numElements - 1];
   return T();
}

/*********************************
 * MAIN
  ********************************/
int main()
{
   //
   // Test prompt
   //

   // prompt for a double
   double valueDouble;
   prompt(valueDouble, "Enter a number");

   // prompt for a string
   string valueString;
   prompt(valueString, "Enter a string");
   // prompt for an integer
   int valueInt;
   prompt(valueInt, "Enter a integer");
   //
   // Test stack
   //

   // a stack of doubles
   Stack <double> stackDoubles;
   stackDoubles.push(1.1);
   stackDoubles.push(2.2);
   stackDoubles.push(3.3);
   stackDoubles.pop();
   stackDoubles.pop();
   cout << "The first element is: "
      << stackDoubles.top() << endl;

   // a stack of strings
   Stack <string> stackStrings;
   stackStrings.push("1.1");
   stackStrings.push("2.2");
   stackStrings.push("3.3");
   stackStrings.pop();
   stackStrings.pop();
   cout << "The first element is: "
      << stackStrings.top() << endl;
   // a stack of integers
   Stack <int> stackInts;
   stackInts.push(1);
   stackInts.push(2);
   stackInts.push(3);
   stackInts.pop();
   stackInts.pop();
   cout << "The first element is: "
      << stackInts.top() << endl;
   return 0;
}
