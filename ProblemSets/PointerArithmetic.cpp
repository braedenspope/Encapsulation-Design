//Pointer Arithmetic Problem Set
//Braeden Pope, Ethan Mangum, Aiden Patterson

#include <iostream>

using namespace std;

void getText(char* text)
{
   cout << "Enter text: ";
   cin.getline(text, 256);
}

char getLetter()
{
   char text;
   cout << "Enter a letter: ";
   cin >> text;
   return text;
}

int countInstancesArray(char* text, char letter) {
   int count = 0;
   int length = strlen(text);
   for (int i = 0; i < length; i++) {
      if (text[i] == letter) {
         count++;
      }
   }
   return count;
}

int countInstancesPointer(char* text, char letter) {
   int count = 0;
   for (char* p = text; *p; p++) {
      if (*p == letter) {
         count++;
      }
   }
   return count;
}

int main()
{
   char text[256];
   getText(text);
   char letter = getLetter();
   int count = countInstancesArray(text,letter);
   int count2 = countInstancesPointer(text,letter);
   cout << "Count using an array loop: " << count << endl;
   cout << "Count using a pointer loop: " << count2 << endl;
}

