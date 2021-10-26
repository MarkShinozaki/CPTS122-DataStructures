#include "Header.h"

/********************************************************
* 
* Programmer: Mark Shinozaki
* Class: CptS 122, FALL 2021
* Programming Assignment #1: Analyze FitBit data from CSV file using struct implementation
* Date: 09/10/2021
* Description: Using structs and other data structures, store & present data from CSV file
* 
**********************************************************/

void main(void)
{ 
	// Open Files to be read 
	FILE* file = NULL, * output = NULL;
	file = fopen("FitbitData.csv", "r");
	output = fopen("Results.csv", "w");

	if (file != NULL)
	{
		printf("\n...File was opened...\n ");
	}

	FitbitData data[SIZE] = { 0 };


	char startMin[9] = "", endMin[9] = "", maxMin[9] = "", targetID[10] = "";

	// Read in data
	readData(data, file, targetID);

	// calculating Values 
	double calories = TotalCal(data, SIZE, targetID);
	double distance = TotalDis(data, SIZE, targetID);
	int floors = TotalFloors(data, SIZE, targetID);
	int steps = TotalSteps(data, SIZE, targetID);
	double heartRate = AvgHeart(data, SIZE, targetID);
	int sleep = PoorSleepRange(data, SIZE, startMin, endMin, targetID);
	int maxSteps = MaxSteps(data, SIZE, maxMin, targetID);

	// outputting to screen
	fprintf(output, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(output, "%lf, %lf, %d, %d, %lf, %d, %s:%s\n", calories, distance, floors, steps, heartRate, maxSteps, startMin, endMin);
	fprintf(output, "\nPatient, minute,calories,distance,floors,heart,steps,sleep_level\n");

	// for loop print out 
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(data[i].patient, targetID) == 0)
		{
			fprintf(output, "%s ,%s, %lf, %lf, %d, %d, %d, %d\n", data[i].patient, data[i].minute, data[i].calories, data[i].distance, data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);
		}

	}
	printf("\n...Data was Successfully sorted and inserted ....\n");

	fclose(file);
	fclose(output);
	printf("\n...File Closed....\n");

}#include "Header.h"

/********************************************************
* 
* Programmer: Mark Shinozaki
* Class: CptS 122, FALL 2021
* Programming Assignment #1: Analyze FitBit data from CSV file using struct implementation
* Date: 09/10/2021
* Description: Using structs and other data structures, store & present data from CSV file
* 
**********************************************************/

void main(void)
{ 
	// Open Files to be read 
	FILE* file = NULL, * output = NULL;
	file = fopen("FitbitData.csv", "r");
	output = fopen("Results.csv", "w");

	if (file != NULL)
	{
		printf("\n...File was opened...\n ");
	}

	FitbitData data[SIZE] = { 0 };


	char startMin[9] = "", endMin[9] = "", maxMin[9] = "", targetID[10] = "";

	// Read in data
	readData(data, file, targetID);

	// calculating Values 
	double calories = TotalCal(data, SIZE, targetID);
	double distance = TotalDis(data, SIZE, targetID);
	int floors = TotalFloors(data, SIZE, targetID);
	int steps = TotalSteps(data, SIZE, targetID);
	double heartRate = AvgHeart(data, SIZE, targetID);
	int sleep = PoorSleepRange(data, SIZE, startMin, endMin, targetID);
	int maxSteps = MaxSteps(data, SIZE, maxMin, targetID);

	// outputting to screen
	fprintf(output, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(output, "%lf, %lf, %d, %d, %lf, %d, %s:%s\n", calories, distance, floors, steps, heartRate, maxSteps, startMin, endMin);
	fprintf(output, "\nPatient, minute,calories,distance,floors,heart,steps,sleep_level\n");

	// for loop print out 
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(data[i].patient, targetID) == 0)
		{
			fprintf(output, "%s ,%s, %lf, %lf, %d, %d, %d, %d\n", data[i].patient, data[i].minute, data[i].calories, data[i].distance, data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);
		}

	}
	printf("\n...Data was Successfully sorted and inserted ....\n");

	fclose(file);
	fclose(output);
	printf("\n...File Closed....\n");

}
