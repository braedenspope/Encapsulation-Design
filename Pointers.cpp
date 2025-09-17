/*
* Names: Braeden Pope, Ethan Mangum, and Aiden Patterson
* Assignment: Pointer Problem Set
*/


#include <iostream>
#include <cassert>

using namespace std;

int main()
{
   double accountSam;
   double accountSue;
   cout << "What is Sam's account balance? $";
   cin >> accountSam;
   cout << "What is Sue's account balance? $";
   cin >> accountSue;

   double* pAccount = nullptr;

   if (accountSam > accountSue) {
      pAccount = &accountSam;
   }
   else {
      pAccount = &accountSue;
   }

   double dinner;
   double movie;
   double iceCream;
   cout << "\nCost of the date:" << endl;
   cout << "\tDinner:    $";
   cin >> dinner;
   cout << "\tMovie:     $";
   cin >> movie;
   cout << "\tIce Cream: $";
   cin >> iceCream;
   
   assert(pAccount != nullptr);

   double balance = *pAccount;
   balance -= dinner;
   balance -= movie;
   balance -= iceCream;

   *pAccount = balance;

   cout << "\nSam's balance: $" << accountSam;
   cout << "\nSue's balance: $" << accountSue;
}
