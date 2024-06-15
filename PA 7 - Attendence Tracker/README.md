
# Programming Assignment 7: Attendance Tracker w/ Class Templates

## I. Learner Objectives

At the conclusion of this programming assignment, participants should be able to:

- Design, implement and test classes in C++
- Apply class templates in C++
- Declare and define constructors
- Declare and define destructors
- Compare and contrast public and private access specifiers in C++
- Describe what is an attribute or data member of a class
- Describe what is a method of a class
- Apply and implement overloaded functions
- Distinguish between pass-by-value and pass-by-reference
- Discuss classes versus objects
- Implement container classes
- Implement a list class
- Implement a stack class
- Read and write files in C++
- Programmatically acquire calendar dates

## II. Prerequisites

Before starting this programming assignment, participants should be able to:

- Analyze a basic set of requirements for a problem
- Compose basic C++ language programs
- Create basic test cases for a program
- Apply arrays, strings, and pointers

## III. Overview & Requirements

Let's create an application that manages attendance for a course. This application has four major requirements:

1. **Import records:** The application must import records pertaining to each student registered for the course from a course list.
2. **Mark absences:** The application must allow the user to mark each student in the course as present or absent on any given day.
3. **Generate reports:** The application must generate reports based on attendance records.
4. **Menu:** The application must support a user interface to the attendance tracker.

**Import records:**  
Records must be read from a comma-separated values (.csv) course file. A .csv file stores data as plaintext in tabular form. Each row in the file is considered a record. Each record consists of the following fields separated by commas. Please review this [sample .csv file](https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c).

- record number (max 3 digits)
- ID number (max 9 digits)
- name (last, first)
- email
- number of credits for class or AU for audit
- class (freshman, sophomore, junior, senior, graduate)

You are required to create a class for your master list, which is NOT a template. This class will be implemented using an array or std::vector. The Stack class must support push(), pop(), peek(), and isEmpty() operations, but does not have to be a template. All of the stack operations should execute in constant time O(1).

**Mark absences:**  
The user of the program should be able to view the master list of students in the course and mark absences for the current day. This may be implemented by simply traversing the linked list (linear time O(n)) and asking if the student absent? If so, mark it. The date for the day must be derived from the computer's date. The following fragment of code illustrates how to derive the date from the computer:

```cpp
#include <ctime>
using namespace std;

time_t now = time(0);
char* dt = ctime(&now);
cout << "The local date and time is: " << dt << endl;
```
### Generate reports:
The user of the program should be able to generate two versions of reports. One version is a report that shows all of the students in the class and the number of times they have been absent, along with the dates of the most recent absence. The other version is a report that shows only the students who have missed more than the allowed number of absences. You DO NOT need to show the dates absent for the second version. Write each report to a different text file. How will you traverse the linked list efficiently? What searching algorithms will you use? What is their Big-O efficiency?

### Menu:
At startup of the program, a menu must be displayed. The menu must support six options. These include:

- Import course list
- Load master list
- Store master list
- Mark absences
- BONUS: Edit absences
- Generate report
- Exit

**Option 1:** Reads the .csv course file and overwrites the master list.

**Option 2:** Reads the master list file.

**Option 3:** Stores the contents of the master list's nodes to master.txt.

**Option 4:** Prompts the user to input the students who missed class that day.

**Option 5:** Edit absences for a student.

**Option 6:** Generates two reports as described.

**Option 7:** Exits the program.

### IV. Submitting Assignments:
Using Canvas [https://canvas.wsu.edu/](https://canvas.wsu.edu/), please submit your solution to the correct "Programming Assignments" (PA) folder. Your solution should be zipped into a .zip file with the name `<your last name>_PA7.zip` and uploaded. To upload your solution, please navigate to your correct Canvas lab course space. Select the "Assignments" link in the main left menu bar. Navigate to the correct PA submission folder. Click the "Start Assignment" button. Click the "Upload File" button. Choose the appropriate .zip file with your solution. Finally, click the "Submit Assignment" button.

Your project must contain at least two header files (.h files) and three C++ source files (which must be .cpp files). Your solution must contain the implementations for the test functions. Your project must build properly. The most points an assignment can receive if it does not build properly is 65 out of 100.

### V. Grading Guidelines:
This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:

- 5 pts - Appropriate design and implementation of class Templates Node and List (including member functions and data members)
- 30 pts - Appropriate design and implementation of class Stack (including member functions and data members)
- 12 pts - Appropriate design and implementation of class Data (including member functions and data members)
- 8 pts - Importing "import records" feature
- 10 pts - Working "Mark absences" feature
- 20 pts - Working "Generate reports" feature - each report is 5 pts
- 10 pts - Working "Menu" feature encapsulated by a menu object
- BONUS 20 pts - Working "Edit absences" feature


---

# Summary and Step Guide for Completing the Assignment

1. **Understand the Requirements**
   - Carefully read through the assignment guidelines.
   - Identify the required classes (Templates Node, List, Stack, Data) and their functionalities.

2. **Set Up the Development Environment**
   - Open Microsoft Visual Studio 2019 and create a new project.
   - Ensure the project setup includes necessary header (.h) and source (.cpp) files.

3. **Define Classes and Member Functions**
   - Create the Templates Node and List classes:
     - Define data members and member functions.
   - Create the Stack class:
     - Implement push(), pop(), peek(), and isEmpty() operations.
   - Create the Data class:
     - Define data members and member functions.

4. **Implement Import Records Feature**
   - Implement functionality to read records from a .csv file and store them in the master list.

5. **Implement Mark Absences Feature**
   - Implement functionality to mark students as absent or present.
   - Use the provided code snippet to get the current date.

6. **Implement Generate Reports Feature**
   - Implement functionality to generate two reports:
     - All students with their absence count and dates of absences.
     - Students with more than the allowed number of absences.

7. **Implement Menu Interface**
   - Implement a menu to navigate the program functionalities.
   - Include options to import, load, store, mark absences, edit absences, generate reports, and exit.

8. **Write Test Cases**
   - Write test cases to verify the correctness of the implemented features.
   - Ensure edge cases are considered and tested.

9. **Bonus Feature (Optional)**
   - Implement the Edit Absences feature to allow editing of student absence records.

10. **Test the Program**
    - Run the program and validate outputs against expected results.
    - Debug any issues that arise during testing.

11. **Prepare Documentation**
    - Write a short write-up on your simulation for the attendance tracker.
    - Create a readme.txt file with assumptions, referenced files, and additional information.

12. **Submit the Assignment**
    - Zip the project files including code, header files, test plan, readme, and data files.
    - Upload the zipped file to the appropriate Canvas assignment submission folder.

