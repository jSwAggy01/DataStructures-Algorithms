#include <iostream>
#include <list>
#include <fstream>
#include <ostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <deque>

#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &name){

	ifstream inFS;
	string word;

	// cout << "Opening file" << endl;
	inFS.open(name.c_str());

	if(!inFS.is_open()) {
		cout << "Error opening file";
		// inFS.close();
		return;
	}

	while(inFS >> word){
		if(word.size() != 5){
			cout << "error worder longer than 5 letters";
			// inFS.close();
			return;
		}

		else{
			dict.push_back(word);
		}
	}

	// cout << "Closing file" << endl;
	inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){
	ofstream outFS;
	
	outFS.open(outputFile.c_str());

	if(!outFS.is_open() || (outputFile.substr(outputFile.length() - 3) != "txt")){
		cout << "Invalid output file";
		outFS.close();
		return;
	}
	
	stack<string> words;
	words.push(start);

	queue<stack<string>> ladder;
	ladder.push(words);

	string word;
	list<string>::iterator nextWord;

	int counter = 0;

	for(nextWord = dict.begin(); nextWord != dict.end(); ++nextWord){
		if(*nextWord == start){
			counter++;
		}

		if(*nextWord == end){
			counter++;
		}
	}

	if(counter != 2){
		cout << "error";
		return;
	}

	if(start == end){
		outFS << start;
		outFS.close();
		return;
	}

	while(ladder.empty() == false){
		word = ladder.front().top();
		for(nextWord = dict.begin(); nextWord != dict.end(); ++nextWord){
			if(checker(word, *nextWord) == true){
				stack<string>copy = ladder.front();
				copy.push(*nextWord);

				if(*nextWord == end){
					outputLadder2(copy, outFS);
					return;
				}

				ladder.push(copy);
				nextWord = dict.erase(nextWord);

				nextWord--;

			}
		}
		ladder.pop();
	}

	if(ladder.empty() == true){
		outFS << "No Word Ladder Found.";
	}
	
}

bool WordLadder::checker(string word, string nextWord){
	int i = 0;
	int x = 0;

	for(i = 0; i < 5; ++i){
		if(word.at(i) ==  nextWord.at(i)){
			x++;
		}
	}

	if(x == 4){
		return true;
	}

	else{
		return false;
	}
}

void WordLadder::outputLadder2(stack<string> stack, ofstream &outFS){
	int i = 0;
	int counter = 0;
	vector<string> ladder;

	while(stack.empty() == false){
		ladder.push_back(stack.top());
		stack.pop();
		counter++;
	}

	for(i = counter-1; i >= 0; --i){
		outFS << ladder.at(i);
		
		if(i != 0){
			outFS << " ";
		}
	}
}