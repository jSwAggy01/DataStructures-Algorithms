// Collaborated with demo partner Peter Chu
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string payload;
    Node* next;

};

Node* newNode(string payload) {
	Node* nNode = new Node;
	nNode->next = nullptr;
	nNode->payload = payload;

	return nNode;

}

Node* loadGame(int n, vector<string> names) {
    Node* head = nullptr;
    Node* prev = nullptr;
    string name;

    for (int i = 0; i < n; ++i) {
        name = names.at(i);
        if (head == nullptr) {
            head = newNode(name); // initialize head specially
            prev = head;
        } else {
            prev->next = newNode(name);
            prev = prev->next;
        }
    }

    if (prev != nullptr) {
        prev->next = head;
    }
    return head;
}

void print(Node* start) { // prints list
    Node* curr = start;
    while (curr != nullptr) {
        cout << curr->payload << endl;
        curr = curr->next;
        if (curr == start) {
            break; // exit circular list
        }
    }
}


Node* runGame(Node* start, int k) { // josephus w circular list, k = num skips
    Node* curr = start;
    Node* prev = curr;
    while (curr->next != curr) { // exit condition, last person standing
        for (int i = 0; i < k; ++i) { // find kth node
          prev = curr;
		  curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;
        curr = prev->next;
    }

    return curr; // last person standing
} 


/* Driver program to test above functions */
int main() {
    int n=1, k=1; // n = num names; k = num skips (minus 1)
    string name;
    vector<string> names;

    // get inputs
    cin >> n >> k;
    while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input

    // initialize and run game
    Node* startPerson = loadGame(n, names);
    Node* lastPerson = runGame(startPerson, k);

    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    } else {
        cout << "error: null game" << endl;
    }

	/*string name;
    vector<string> names;
	int n = 0, k = 0;
	cin >> n >> k;
	while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input
	Node* startPerson = loadGame(n, names);
	print(startPerson);*/



    return 0;
}