#include <iostream>


#include"Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = 0;
	head = 0;
	tail = 0;
}

PlaylistNode::PlaylistNode(string ID, string sname, string aname, int length) {
	uniqueID = ID;
	songName = sname;
	artistName = aname;
	songLength = length;
	nextNodePtr = 0;
	head = 0;
	tail = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* ptr) {
		// I have  no clue what we're doing here.
		ptr->SetNext(this->GetNext());
		this->SetNext(ptr);
}

void PlaylistNode::SetNext(PlaylistNode* ptr) {
	nextNodePtr = ptr;
}

string PlaylistNode::GetID() const {
	return uniqueID;
}

string PlaylistNode::GetSongName() const {
	return songName;
}

string PlaylistNode::GetArtistName() const {
	return artistName;
}

int PlaylistNode::GetSongLength() const {
	return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;

}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl;
	cout << "Song Length (in seconds): " << songLength << endl;

}

void PlaylistNode::outputFullPL() {

	if (head == nullptr) {
		cout << "Playlist is empty" << endl << endl;
	}

	else {
		PlaylistNode* newNode = head;
		unsigned int i = 1;
		
		for (newNode = head; newNode != nullptr; newNode = newNode->GetNext()) {
			cout << i << "." << endl;
			newNode->PrintPlaylistNode();
			cout << endl;
			++i;
		}
		
	}
}

void PlaylistNode::AddSong(string ID, string sname, string aname, int length) {
	
	PlaylistNode* newNode = new PlaylistNode(ID, sname, aname, length);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}

	else {
		tail->InsertAfter(newNode);
		tail = newNode;
	}
	
}

void PlaylistNode::RemoveSong(string id){
	PlaylistNode* prevNode = nullptr;
	PlaylistNode* currNode = head;
	PlaylistNode* temp;

	for (currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
		if (currNode->GetID() == id) {
			if (prevNode != nullptr) {
				// cout << "FIXME: HERE!1\n";
				// temp = prevNode;
				prevNode->SetNext(currNode->GetNext());
				// delete temp;
				break;
			}

			else if (currNode == head) {
				temp = currNode;
				// cout << "FIXME: HERE!2\n";
				head = currNode->GetNext();
				delete temp;
				break;
			}

			else if (currNode == tail) {
				// cout << "FIXME: HERE!3\n";
				delete currNode;
				tail = nullptr;
				break;
			}

		}

		prevNode = currNode;
	
	}

	cout << "\"" << currNode->GetSongName() << "\"" << " removed." << endl << endl;
	delete currNode;
	currNode = nullptr;
}

void PlaylistNode::ChangePOS (int pos, int newPos) {
	int totalNodes = 0;
	int i = 1;
	PlaylistNode* counter = head;
	PlaylistNode* newNode = head;
	PlaylistNode* currNode = head;
	PlaylistNode* prevNode = nullptr;

	for (counter = head; counter != nullptr; counter = counter->GetNext()){
		totalNodes++;
	}

	for (i = 1; i < pos; ++i) {
		prevNode = currNode;
		currNode = currNode->GetNext();
	}

	if (newPos > totalNodes) {
		if (prevNode == nullptr) {
			head = currNode->GetNext();
		}
		else {
			prevNode->SetNext(currNode->GetNext());
		}
		AddSong(currNode->GetID(), currNode->GetSongName(), currNode->GetArtistName(), currNode->GetSongLength());
	}

	else if (newPos <= 1){
		prevNode->SetNext(currNode->GetNext());
		currNode->SetNext(head);
		head = currNode;
	}

	else {
		if (prevNode == nullptr) {
			head = currNode->GetNext();
			for (i = 1; i < newPos; ++i) {
			newNode = newNode->GetNext();
		}

		newNode->InsertAfter(currNode);

		}

		else {
			prevNode->SetNext(currNode->GetNext());
			for (i = 1; i < newPos-1; ++i) {
			newNode = newNode->GetNext();
		}

		newNode->InsertAfter(currNode);
		}
	}
	if (newPos > totalNodes) {
		newPos = totalNodes;
	}

	if (newPos < 1) {
		newPos = 1;
	}

	cout << "\"" << currNode->GetSongName() << "\" moved to position " << newPos << endl;

}

void PlaylistNode::OutputSA() {
	string name;
	int i = 1;
	PlaylistNode* newNode = head;

	cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
	cout << "Enter artist's name:" <<endl;
	getline(cin, name);

	cout << endl;

	for (newNode = head; newNode != nullptr; newNode = newNode->GetNext()){
		if (newNode->GetArtistName() == name){
			cout << i << "." << endl;
			newNode->PrintPlaylistNode();
			cout << endl;
		}
		++i;
	}


}

void PlaylistNode::TotalTime(){
	int totalTime = 0;
	PlaylistNode* newNode = head;
	for (newNode = head; newNode != nullptr; newNode = newNode->GetNext()){
		totalTime += newNode->GetSongLength();
	}

	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
	cout << "Total time: " << totalTime << " seconds" << endl;
	cout << endl;
	
}