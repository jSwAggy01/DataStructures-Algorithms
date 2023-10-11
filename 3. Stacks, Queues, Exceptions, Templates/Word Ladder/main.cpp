// Collaborated with demo partner Peter Chu
#include "WordLadder.h"

#include <iostream>
// Compile with: g++ WordLadder.cpp main.cpp -Wall -Werror -Wuninitialized -o ./a.exe

using std::cin;
using std::cout;
using std::string;
using std::endl;

// bool ValidFile (string fileName) {
//    ifstream inFS(fileName);
//    if (inFS.is_open() && (fileName.substr(fileName.length() - 3) == "txt")) {
//       inFS.close();
//       return true;
//    }
//    return false;
// }

int main() {
   string dictFile, wordBegin, wordEnd, outFile;

   cout << "Enter the name of the dictionary file: ";
   cin >> dictFile;
   cout << endl;

   cout << "Enter the name of the output file: ";
   cin >> outFile;
   cout << endl;

   cout << "Enter the first word: ";
   cin >> wordBegin;
   cout << endl;
   while (wordBegin.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
      cin >> wordBegin;
      cout << endl;
   }
   cout << "Enter the last word: ";
   cin >> wordEnd;
   cout << endl;
   while (wordEnd.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
      cin >> wordEnd;
      cout << endl;
   }
   
	WordLadder wl(dictFile);
	
	wl.outputLadder(wordBegin, wordEnd, outFile);

   return 0;
}