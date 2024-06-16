#ifndef MUSIC_MANAGER
#define MUSIC_MANAGER 
#define _CRT_SECURE_NO_WARNINGS

#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <time.h>

typedef struct duration {

	int Minutes;
	int Seconds;

}Duration;

typedef struct record {

	char Artist[50];
	char Album_title[50];
	char Song_title[50];
	char Genre[20];
	Duration Length;
	int PlayBack;
	int Rating;
}Record;

typedef struct node {
	Record data;
	struct node* pNext;
	struct node* pPrev;
}Node;

// Menu options 
int Menu(void);

// Creates a Node
Node* MakeNode(Node* pMem);

// reads data from csv into struct nodes and 
int Load(FILE* infile, Node** pList);

// prints the nodes back out to the csv file
void Store(FILE* outfile, Node** pList);

// Displays song and artist
void DisplaySong(Node* pList);

// displays the entire list 
void DisplayL(Node* pList);

// inserts new nodes 
void Insert(Node** pList);

// deletes a node from a certain position 
int Delete(Node** pList, char* Song);

// edits any node in the playlist
int Edit(Node** pList, char* Artist);

// searches for certain artist in playlist 
int ArtistSearch(Node** pList, char* Artist, Node MultiAlbum[]);

// searches for certain song in playlist
Node* SongSearch(Node** pList, char* Tsong);

// displays only one song/ record
void DisplayR(Node* pCur);

// allows user to change rating 
void Rate(Node** pList);

// plays the songs starting from one node 
void Selection(Node** pList);

// plays the songs from first entry in the list
void Order(Node** pList);

// Gets the size of the list 
int NodeSize(Node* pList, Node* pCur, int length);

// sorts by artist
void SortByArtist(Node** pList);

// sorts by albumtitle
void SortByAlbum(Node** pList);

// sorts by rating 
void SortByRating(Node** pList);

// sorts by playbacks
void SortByPlayback(Node** pList);

// shuffles the playlist
void Shuffle(Node** pList);

#endif
