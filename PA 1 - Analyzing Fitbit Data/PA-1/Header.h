#define _CRT_SECURE_NO_WARNINGS
#ifndef FITBIT
#define FITBIT

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define SIZE 1450 // setting size of data

// type enum for sleep
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;


// Struct of information being data being read in
typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


// read data
void readData(FitbitData data[], FILE* infile, char target[]); 
															 
// calculate total calories
double TotalCal(FitbitData data[], int size, char target[]); 

// calculate total distance
double TotalDis(FitbitData data[], int size, char target[]); 

// calculate total floors walked
int TotalFloors(FitbitData data[], int size, char target[]); 

// calculate total steps
int TotalSteps(FitbitData data[], int size, char target[]); 

// calculate average heart
double AvgHeart(FitbitData data[], int size, char target[]); 

// calculate poor sleep range
int PoorSleepRange(FitbitData data[], int size, char startingMin[], char endingMin[], char target[]); 

// calculate max steps
int MaxSteps(FitbitData data[], int size, char minute[], char target[]); 



#endif