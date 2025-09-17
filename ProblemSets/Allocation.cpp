/*******************************************
 * Names: Aiden Patterson, Braedon Pope, Ethan Mangum
 * File: AllocationProblem.cpp
 * Summary: This program is desgined to practice memory
 * allocation, including creation, allocation,
 * data manipulation, and deletion.
 ********************************************/


#include <iostream>
#include <cassert>
using namespace std;

/*******************************************
 * Function: promptSize()
 * Summary: Asks the user for the size of the
 * array then returns the input as an int.
 ********************************************/
int promptSize()
{
   int size;
   cout << "How many items are in the array? ";
   cin >> size;
   return size;
}

/*******************************************
 * Function: allocateArray()
 * Summary: Takes the size of the array and allocates
 * that much space for the array.
 ********************************************/
template <class T>
bool allocateArray(int size, T*& array)
{
   array = new(nothrow) T[size];

   return array != nullptr;
}

/*******************************************
 * Function: prompt()
 * Summary: Fills the elements of the array based
 * on user input.
 ********************************************/
template <class T>
void prompt(int size, T* array)
{
   assert(array != nullptr);
   for (int i = 0; i < size; i++)
   {
      cout << "\t# " << i + 1 << ": ";
      cin >> array[i];
   }
}

/*******************************************
 * Function: display
 * Summary: Takes the array and displays all
 * elements within the array.
 ********************************************/
template <class T>
void display(int size, const T* array)
{
   assert(array != nullptr);
   cout << "The elements in the list:" << endl;
   for (int i = 0; i < size; i++)
   {
      cout << "\t" << array[i] << endl;
   }
}

/*******************************************
 * Function: release
 * Summary: deletes the allocated array
 * and sets the pointer to nullptr.
 ********************************************/
template <class T>
void release(T*& array)
{
   assert(array != nullptr);
   delete[] array;
   array = nullptr;
}

/*******************************************
 * Function: main()
 * Summary: The driver for the program.
 ********************************************/
int main()
{
   int size = promptSize();

   int* array = nullptr;

   if (allocateArray(size, array))
   {
      prompt(size, array);
      display(size, array);
      release(array);
   }
   else
      cout << "Bad" << endl;
}
