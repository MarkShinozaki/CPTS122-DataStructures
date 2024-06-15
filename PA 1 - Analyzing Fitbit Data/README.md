# Programming Assignment 1: Analyzing Fitbit Data

## I. Learner Objectives
**At the conclusion of this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Apply basic techniques for data cleansing or data cleaning
- Analyze a medium set of data and compute results
- Filter data
- Implement deduping methods
- Compose C language programs
- Create and compile a program using Microsoft Visual Studio 2019
- Execute a program in Microsoft Visual Studio 2019
- Create basic test cases for a program
- Apply arrays, strings, and pointers
- Define and apply structs
- Parse strings from files
- Convert strings to numerical values
- Summarize differences between array notation and pointer notation
- Apply basic string handling library functions

## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Access Microsoft Visual Studio 2019 Integrated Development Environment (IDE)
- Design and develop a small or medium-sized program in any language
- Apply sequential, conditional, and iterative constructs
- Design and implement user-defined functions

## III. Overview & Requirements
- The intent of this assignment is to review concepts from your prior “CS 1” course and to challenge and enhance those concepts.

- Fitbit is a company that builds wearable technology devices that track various activities. The devices have sensors that measure number of steps and distance walked, heart rate, sleep quality, floors climbed, and calories burned. In this assignment, you will analyze data that was aggregated from Fitbit devices. The data is stored in a comma-separated values (.csv) file that you will find at: Fitbit Data. The entries in this file were merged from two different devices. You will need to filter any data that is not related to the target patient. The first data entry in the file contains the target. You will also need to discard any entries that appear multiple times and perform data cleansing on any entries that have missing fields.

- A .csv file stores data as plaintext in tabular form. Each row in the file is considered a record. Each record consists of comma-separated values.

- In particular, you will analyze 24 hours of data. Each record in the “FitbitData.csv” represents one minute of data and consists of 10 fields. These fields include the following:

1. Patient
2. Minute
3. Calories
4. Distance (in miles)
5. Floors
6. Heart rate
7. Steps
8. Sleep level

### What data structures are required?
**In this assignment, you must define a C struct to store a subset of the Fitbit data fields as follows:**
```c
typedef struct fitbit {
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;
```

**The type `Sleep` is enumerated and must be defined as follows:**

```c
typedef enum sleep {
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;
```

You must also define an array of `FitbitData` that can store 24 hours of minute data. Hence, you must declare an array of size 1440. You have the freedom to decide on other data structures and variables that you need for the assignment.

### What are the other requirements?
- This program does not require any user input! However, you will need to display some results to the screen!

  - You must open “FitbitData.csv” for mode read; check for success
  - You must read each record in the file as a string, one line at a time; if the record does not belong to the target patient, then it should be discarded
  - You must parse each record into the corresponding fields, and store into the `FitbitData` array; note: not all fields have values, some are “empty” or null; if some of the fields are “empty” or null, then you must perform data cleansing and insert values to construct a record that is consistent with the others; these “default” values should not represent realistic values
  - You must compute the total calories burned, distance walked in miles, floors walked, and steps taken
  - You must compute the average heart rate over the 24 hour period
  - You must report the max steps taken in one minute over the 24 hour period
  - When the max is discovered, then report the minute and the corresponding value
  - You must compute the longest consecutive range of poor sleep; this range is identified by consecutive minutes where the sleepLevel is greater than or equal to 1 (ASLEEP, AWAKE, REALLYAWAKE); report the starting and ending minute of the range; the max sum of the range is the longest range; if there are multiple ranges, then return the first one that is found
You must write the total calories, total distance, total floors, total steps, average heart rate, max steps, and the longest poor sleep range to an output file named “Results.csv” in the following format:
    - Line 1: Total Calories,Total Distance,Total Floors,Total Steps,Average Heartrate,Max Steps,Max Steps:Minute,Longest Poor Sleep Range, SleepStart:SleepEnd
  - You must write the following information to the screen:
    - Read FitbitData.csv
    - Write to Results.csv
    - Each line written in the file should be displayed on the screen

## V. Grading Guidelines
- **This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:**

  - 5 pts for correctly defining struct FitbitData
  - 3 pts for correctly defining enum Sleep
  - 3 pts for correctly opening “FitbitData.csv” for mode read
  - 2 pts for correctly checking the success of the file opening operation
  - 10 pts for correctly reading each record in the file as a string, one line at a time, and filtering and deduping any lines that do not belong to the target patient or are duplicates
  - 15 pts for correctly cleaning the data and parsing each record into the corresponding fields
  - 5 pts for correctly converting the strings to the field types
  - 5 pts for correctly storing the fields into the FitbitData array
  - 3 pts for correctly computing the total calories burned
  - 3 pts for correctly computing the total distance walked in miles
  - 3 pts for correctly computing the total floors walked
  - 3 pts for correctly computing the total steps taken
  - 5 pts for correctly computing the average heart rate over the 24 hour period
  - 5 pts for correctly determining the max steps taken in one minute over the 24 hour period
  - 5 pts for correctly determining the longest consecutive range of poor sleep
  - 5 pts for correctly opening “Results.csv” for mode write
  - 8 pts for correctly formatting and outputting the data, without any duplicate entries, to “Results.csv” and to the screen
  - 2 pts for correctly closing the “FitbitData.csv”
  - 2 pts for correctly closing the “Results.csv”
  - 5 pts for appropriate top-down design of functions and good style

---

# Step-by-Step Guide to Completing Programming Assignment 1: Analyzing Fitbit Data
## Step 1: Understand the Requirements
- Read the assignment guidelines thoroughly to understand the objectives and requirements.
- Review the data structure definitions, required calculations, and the output format.
## Step 2: Set Up Your Development Environment
- Ensure you have Microsoft Visual Studio 2019 installed.
- Create a new project for the assignment.
## Step 3: Define Data Structures
- Define the `FitbitData` struct to store the required data fields.
- Define the `Sleep enum` to represent the sleep levels.
  
**Example:**
```c
typedef enum sleep {
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;
```
## Step 4: Read and Parse Data
- Open the `FitbitData.csv` file for reading.
- Check if the file opened successfully.
- Read each line from the file and parse the data into the `FitbitData` array.
- Filter out records that do not belong to the target patient and handle duplicates.
  
**Example:**
```c
  FILE *file = fopen("FitbitData.csv", "r");
if (file == NULL) {
    // Handle file open error
}
```
## Step 5: Data Cleansing
- Ensure all fields in the FitbitData array are properly populated.
- Replace empty or null fields with default values.

## Step 6: Compute Required Metrics
- Calculate the total calories burned, total distance walked, total floors walked, and total steps taken.
- Compute the average heart rate over the 24-hour period.
- Determine the maximum steps taken in one minute and identify the corresponding minute.
- Identify the longest consecutive range of poor sleep.

## Step 7: Output Results
- Open the `Results.csv` file for writing.
- Write the computed metrics to the file in the specified format.
- Display the results on the screen.

**Example:**

```c
FILE *outputFile = fopen("Results.csv", "w");
if (outputFile == NULL) {
    // Handle file open error
}

// Write results to the file and screen
fprintf(outputFile, "Total Calories,Total Distance,Total Floors,Total Steps,Average Heartrate,Max Steps,Max Steps:Minute,Longest Poor Sleep Range, SleepStart:SleepEnd\n");
// Additional code to write the computed values
fclose(outputFile);
```

##Step 8: Close Files
- Close both the input and output files properly.

## Step 9: Test Your Program
- Create test cases to ensure your program works as expected.
- Verify the correctness of the output by comparing it with expected results.

## Step 10: Prepare Documentation
- Write a test plan that includes sample input data, expected results, and screenshots of your program’s output.
- Create a readme.txt file with any assumptions, referenced files, and other relevant information.

## Step 11: Submit Your Assignment
- Zip all required files into a single file named PA1.zip.
- Upload the zip file to the appropriate Canvas assignment submission folder.

## Summary of Files to Include:
1. C program code file.
2. C header file.
3. Test plan document (Word).
4. readme.txt file.
5. Results.csv file.

## Tips:
- Break down the tasks into smaller, manageable functions.
- Continuously test your functions as you implement them.
- Follow good coding practices and maintain a clean, readable codebase.











