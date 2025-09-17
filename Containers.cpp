
#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    // Create the empty list
    list<string> listData;
    
    // Ask user for 10 words which will be put in the list
    cout << "Please enter 10 words:" << endl;

    for (int i = 0; i < 10; i++)
    {
        string word;
        cout << "> ";
        cin >> word;

        listData.push_back(word);
    }

    // Display all words in the list using an iterator from the beginning
    cout << "The data in listData displayed forwards is:" << endl;

    for (auto it = listData.begin(); it != listData.end(); it++)
    {
        cout << "\t" << * it << endl;
    }

    // Create the vector and populate it with items in the list
    vector<string> vectorData;

    for (auto it = listData.begin(); it != listData.end(); it++)
    {
        vectorData.push_back(*it);
    }

    // Display items in the vector starting from the back and going to the front
    cout << "The data in vectorData displayed backwards is:" << endl;

    for (int i = vectorData.size() - 1; i >= 0; i--)
    {
        cout << "\t" << vectorData[i] << endl;
    }
}