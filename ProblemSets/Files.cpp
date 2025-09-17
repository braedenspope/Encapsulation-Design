/******************************************
 * Name: Ethan Mangum, Braeden Pope, Aiden Patterson
 * File: balanceFiles.cpp
 * Summary: Reads a balance from a file, displays it, allows
 * the user to add to the balance, then writes the new balance
 * to the same file.
 ***********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/************************************************
 * Function: readBalance()
 * Summary: Reads the balance from data.txt then returns the balance.
 ************************************************/
double readBalance()
{
   double balance = 0.0;
   ifstream fin;

   fin.open("data.txt");

   if (fin.fail())
   {
      cout << "Unable to open data.txt" << endl;
      balance = 0.0;
   }
   else
   {
      fin >> balance;
   }

   fin.close();

   return balance;
}

/*************************************************
 * Function: displayBalance()
 * Summary: Takes the balance and displays it to the user.
 ************************************************/
void displayBalance(double balance)
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "Account balance: $" << balance << endl;
}

/**************************************************
 * Function: updateBalance()
 * Summary: Asks the user for a number, then adds it
 * to the existing balance.
 *************************************************/
void updateBalance(double & balance)
{
   double change;

   cout << "Change: $";
   cin >> change;

   balance += change;
}

/****************************************************
 * Function: writeBalance()
 * Summary: Takes the updated balance and writes it
 * to the data.txt file.
 *****************************************************/
void writeBalance(double& balance)
{
   ofstream fout;

   fout.open("data.txt");

   if (fout.fail())
   {
      cout << "Unable to write balance to data.txt." << endl;
   }
   else
   {
      fout << balance;
      cout << "Balance successfully written to data.txt" << endl;
   }

   fout.close();
}

/*******************************************************
 * Function: main()
 * Summary: Creates the balance object, then runs the program
 ******************************************************/
int main()
{
   double balance = readBalance();

   displayBalance(balance);

   updateBalance(balance);

   displayBalance(balance);

   writeBalance(balance);
}
