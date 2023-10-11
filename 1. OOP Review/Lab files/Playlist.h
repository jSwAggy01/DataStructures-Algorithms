#ifndef PLAYLIST_H
#define PLAYLIST_H

#include<iostream>
#include<string>

using namespace std;

class PlaylistNode{
	public:
		PlaylistNode();
		PlaylistNode(string ID, string sname,string aname,int length);
		void InsertAfter(PlaylistNode* ptr);
		void SetNext(PlaylistNode* ptr);
		string GetID() const;
		string GetSongName() const;
		string GetArtistName() const;
		int GetSongLength() const;
		PlaylistNode* GetNext();
		void PrintPlaylistNode();
		void outputFullPL();
		void AddSong(string ID, string sname, string aname, int length);
		void RemoveSong(string id);
		void ChangePOS(int pos, int newPos);
		void OutputSA();
		void TotalTime();
	private:
		string uniqueID;
		string songName;
		string artistName;
		int songLength;
		PlaylistNode* nextNodePtr;
		//
		PlaylistNode *head;
		PlaylistNode *tail;
};

#endif