// Collaborated with DEMO partner Peter Chu - pchu024
#include <iostream>
#include <string>

#include "Playlist.h"
using namespace std;
// Compile with: g++ Playlist.cpp main.cpp -Wall -Werror -Wuninitialized -o ./a.exe

void PrintDefault(string playlistTitle) {
		string choice;
		cout << playlistTitle << " PLAYLIST MENU" << endl;
		cout << "a - Add song" << endl;
		cout << "d - Remove song" << endl;
		cout << "c - Change position of song" << endl;
		cout << "s - Output songs by specific artist" << endl;
		cout << "t - Output total time of playlist (in seconds)" << endl;
		cout << "o - Output full playlist" << endl;
		cout << "q - Quit" << endl;
		cout << endl;
		cout << "Choose an option:";
}

void PrintMenu(string playlistTitle) {
	string choice;
	PlaylistNode list;

	PrintDefault(playlistTitle);
	cout << endl;
	cin >> choice;
	cin.ignore();

	while (choice != "q"){

		if (choice == "q" || choice == "Q") {
			exit(1);
		}

		else if (choice == "o" || choice == "O") {
			cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
			list.outputFullPL();
			PrintDefault(playlistTitle);
		}

		else if (choice == "a" || choice == "A") {
			string ID;
			string sname;
			string aname;
			int length;
			cout << "ADD SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			getline(cin, ID);
			cout << "Enter song's name:" << endl;
			getline(cin, sname);
			cout << "Enter artist's name:" << endl;
			getline(cin, aname);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> length;
			list.AddSong(ID, sname, aname, length);
			cout << endl;
			PrintDefault(playlistTitle);
		}

		else if (choice == "d" || choice == "D") {
			string id;
			cout << "REMOVE SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			getline(cin, id);
			list.RemoveSong(id);
			PrintDefault(playlistTitle);
		}

		else if (choice == "c" || choice == "C") {
			int currPos;
			int newPos;
			cout << "CHANGE POSITION OF SONG" << endl;
			cout << "Enter song's current position:" << endl;
			cin >> currPos;
			cout << "Enter new position for song:" << endl;
			cin >> newPos;
			list.ChangePOS(currPos,newPos);
			cout << endl;
			PrintDefault(playlistTitle);

		}

		else if (choice == "s" || choice == "S") {
			list.OutputSA();
			PrintDefault(playlistTitle);
		}

		else if (choice == "t" || choice == "T") {
			list.TotalTime();
			PrintDefault(playlistTitle);
		}

		cin >> choice;
		cin.ignore();
		cout << endl;

	}


}



int main() {
	string playlistName;


	cout << "Enter playlist's title:" << endl;
	getline(cin, playlistName);
	cout << endl;

	PrintMenu(playlistName);

	return 0;
}

// Compile with: g++ Playlist.cpp main.cpp -Wall -Werror -Wuninitialized -o ./a.exe