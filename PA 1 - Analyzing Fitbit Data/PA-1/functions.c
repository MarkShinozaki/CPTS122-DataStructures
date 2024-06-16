#include "Header.h"


void readData(FitbitData data[], FILE* infile, char target[])
{
	
	// Index1 tracks the index in arr[] 
	// m tracks the lines in the input file
	// index 2 is used to help track the array when shiting it over

	int m = 1;
	int Index1 = 0;
	int index2 = 1;

	while (!feof(infile))
	{
		char line[100] = "";
		fgets(line, 100, infile);
		int index = 0;

		for (int i = 0; i < 100; i++)
		{
			// finds the index of the null character
			if (line[i] == '\0') 
			{
				index = i;
				break;
			}
		}

		//'*' character is a placeholder
		// this shifts the array over by 1 when it finds two commas in a row  
		for (int i = 0; i <= index; i++)
		{
			if (line[i] == ',' && line[1 + i] == ',')
			{
				char templine[100] = "";
				int index2 = 0;
				for (int j = i + 1; j < index; j++)
				{
					templine[index2] = line[j];
					index2++;
				}
				line[i + 1] = '*';
				index2 = 0;
				for (int j = i + 2; j < index; j++)
				{
					line[j] = templine[index2++];
				}
				index++;
			}
		}

		if (line[strlen(line)] == ',')
		{
			line[strlen(line) + 1] = ',';
			line[strlen(line) + 2] = '\0';
			index++;
		}
		if (m == 1) // finds the target patients identification to know whose data to collect
		{
			char* RI;
			RI = strtok(line, ",");
			RI = strtok(NULL, ",");
			strcpy(target, RI);
		}
		m++;

		// parse data at line 3
		if (m > 2) 
		{
			char* RI;
			RI = strtok(line, ",");
			int tempindex = 0; 
			while (RI != NULL)
			{
				if (tempindex == 0)
				{
					if (strcmp(RI, target) == 0)
					{
						strcpy(data[Index1].patient, RI);
					}
				}
				else if (tempindex == 1)
				{
					strcpy(data[Index1].minute, RI);

				}
				else if (tempindex == 2)
				{
					if (RI != '*')
					{
						double value = 0;
						value = atof(RI);
						data[Index1].calories = value;
					}
					else
					{
						data[Index1].calories = 12345.0;
					}
				}

				else if (tempindex == 3)
				{
					if (RI != '*')
					{
						double value = 0;
						value = atof(RI);
						data[Index1].distance = value;
					}
					else
					{
						double d = 12345.0;
						data[Index1].distance = d;
					}
				}
				else if (tempindex == 4)
				{
					if (RI != '*')
					{
						int value = 0;
						value = atoi(RI);
						data[Index1].floors = value;
					}
					else
					{
						unsigned int r = 12345;
						data[Index1].floors = r;
					}
				}
				else if (tempindex == 5)
				{
					if (strcmp(RI, "*") != 0)
					{
						int value = 0;
						value = atoi(RI);
						data[Index1].heartRate = value;
					}
					else
					{

						unsigned int r = 12345;
						data[Index1].heartRate = r;

					}
				}
				else if (tempindex == 6)
				{
					if (strcmp(RI, "*") != 0)
					{
						int value = 0;
						value = atoi(RI);
						data[Index1].steps = value;
					}
					else
					{
						unsigned int r = 12345;
						data[Index1].steps = r;
					}
				}
				else if (tempindex == 7)
				{
					if (strcmp(RI, "*") != 0)
					{
						int value = 0;
						value = atoi(RI);
						data[Index1].sleepLevel = value;
					}
					else
					{
						Sleep s = 12345;
						data[Index1].sleepLevel = s;
					}
				}

				tempindex++;
				RI = strtok(NULL, ",");
			}

			Index1++;
		}

	}

}



double TotalCal(FitbitData data[], int size, char target[]) 
{
	double calories = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (data[i].calories != 12345.0 && strcmp(data[i].patient, target) == 0) 
		{
			double temp = data[i].calories;
			calories += temp;
		}

	}
	return calories;
}



double TotalDis(FitbitData data[], int size, char target[]) 
{
	double distance = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (data[i].distance != 12345.0 && strcmp(data[i].patient, target) == 0)
		{
			double temp = data[i].distance;
			distance += temp;
		}

	}
	return distance;
}



int TotalFloors(FitbitData data[], int size, char target[]) 
{
	int floors = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i].floors != (unsigned)12345 && strcmp(data[i].patient, target) == 0) 
		{
			int temp = data[i].floors;
			floors += temp;
		}

	}
	return floors;
}



int TotalSteps(FitbitData data[], int size, char target[]) 
{
	int steps = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i].steps != (unsigned)12345 && strcmp(data[i].patient, target) == 0) 
		{
			int temp = data[i].steps;
			steps += temp;
		}

	}
	return steps;
}



double AvgHeart(FitbitData data[], int size, char target[]) 
{
	double totalHeartBeat = 0.0;
	int ammount = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i].heartRate != (unsigned)12345 && strcmp(data[i].patient, target) == 0) 
		{
			double temp = data[i].heartRate;
			totalHeartBeat += temp;
			ammount++;
		}

	}
	return totalHeartBeat / (double)ammount;
}



int MaxSteps(FitbitData data[], int size, char minute[], char target[]) 
{
	int maxSteps = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i].steps >= maxSteps && data[i].steps != (unsigned)12345 && strcmp(data[i].patient, target) == 0) 
		{
			maxSteps = data[i].steps;
			strcpy(minute, data[i].minute);
		}
	}
	return maxSteps;
}



int PoorSleepRange(FitbitData data[], int size, char startingMin[], char endingMin[], char target[]) 
{
	int longestRangeInMinutes = 0;
	int tempRange = 0;
	int counter = 0;
	int t = 0;
	char tempString[9] = "";
	for (int i = 0; i < size; i++)
	{
		counter = i;

		while (data[counter].sleepLevel > 1)
		{
			if (t == 0)
			{
				strcpy(tempString, data[counter].minute);
				t++;
			}
			int temp = data[counter].sleepLevel;
			tempRange += temp;
			strcpy(endingMin, data[counter].minute);
			counter++;
		}

		if (tempRange > longestRangeInMinutes && strcmp(data[i].patient, target) == 0) 
		{
			longestRangeInMinutes = tempRange;
			strcpy(startingMin, tempString);
		}
		tempRange = 0;
		t = 0;
	}
	return longestRangeInMinutes;
}
