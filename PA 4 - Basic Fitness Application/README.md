# Programming Assignment 4: Basic Fitness Application in C++

## I. Learner Objectives
**At the conclusion of this programming assignment, participants should be able to:**

- Design, implement and test classes in C++
- Declare and define constructors
- Declare and define destructors
- Compare and contrast public and private access specifiers in C++
- Describe what is an attribute or data member of a class
- Describe what is a method of a class
- Apply and implement overloaded functions
- Apply and implement overloaded operators (stream insertion and stream extraction)
- Distinguish between pass-by-value and pass-by-reference
- Discuss classes versus objects
- Apply basic file operations on file streams

## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose basic C++ language programs
- Create basic test cases for a program
- Apply arrays, strings, and pointers

## III. Overview & Requirements

In this assignment, you will write a basic fitness application, in C++, that allows the user of the application to manually edit “diet” and “exercise” plans. For this application you will need to create three classes: `DietPlan`, `ExercisePlan`, and `FitnessAppWrapper`.

The class `DietPlan` is used to represent a daily diet plan. Your class must include three data members to represent your goal calories (an integer), plan name (a std::string), and date for which the plan is intended (a std::string). The maximum intake of calories for a day must be stored as goal calories.

The class `ExercisePla`n is used to represent a daily exercise plan. Your class must include three data members to represent your goal steps (an integer), plan name (a std::string), and date for which the plan is intended (a std::string). Your goal steps represent the number of desired steps for a day.

### Diet and Exercise Plan Operations:

Both the `DietPlan` and `ExercisePlan` should provide several member functions including: a constructor, copy constructor, and destructor. Remember that you will have to think about other appropriate member functions (think about setter and getter functions!). Member function `editGoal()` should prompt the user for a new goal, and use the value to change the goal in the plan. Each time a plan is changed, the plan must be displayed to the screen, using an overloaded stream insertion operator (<<) (see below).

In the same file in which each class declaration exists, three nonmember functions must be declared. Note: an overloaded operator is considered an overloaded function. The overloaded stream insertion (<<) for both displaying a plan to the screen and for writing a plan to a file, and the extraction (>>) operator for reading a plan from a file.

Observation: please notice that the DietPlan and ExercisePlan classes define very similar attributes and operations. In the future, we will be able to design around these similarities (using inheritance and polymorphism).

### Fitness Application:
Each of the daily plans will be read from a file. Each file must consist of exactly seven daily plans, representing a full week of plans. The daily diet plans will be read from a file called “dietPlans.txt” and the daily exercise plans will be read from a file called “exercisePlans.txt”. The format for the files must be represented in the following way:

**Plan name**

**Goal**

**Date**

**Example:**
```
Plan name  
1000  
01/01/2022  
Plan name  
1500  
02/01/2022  
```

You will overload the stream extraction operator (>>) to read a plan from a file, and overload the stream insertion operator (<<) to write a plan to a file. You should write these overloaded operators in a manner similar to the DietPlan and ExercisePlan classes. Each class should contain its own overloaded operator implementations. For now, you should assume that the data structure whether it be an array, vector, or linked list, is already defined and opened!

### FitnessAppWrapper Operations:
- **Your `FitnessAppWrapper` class will need to open the “dietPlans.txt” and “exercisePlans.txt” files for reading and writing. You must define member functions that perform the following:**

- `void loadDailyPlan(fstream &fileStream, DietPlan &plan)`: reads a daily plan from the given stream. You must apply the overloaded stream extraction operator here. Precondition: file is already open!

- `void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])`: must define two of these functions; one for a DietPlan and one for an ExercisePlan. This function must read in all seven daily plans from the given stream. Note: the array parameter may change if using a vector or linked list! This function should call `loadDailyPlan()` directly. Precondition: file is already open!

- `void displayDailyPlan(const DietPlan &plan)`: writes a daily plan to the screen. You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate parameters and return type. Once again you must define two of these!

- `void displayWeeklyPlan(const DietPlan weeklyPlan[])`: writes a weekly plan to the screen. This function must call `displayDailyPlan()`. Note: you must determine the appropriate parameters and return type. Once again you must define two of these!

- `void storeDailyPlan(fstream &fileStream, const DietPlan &plan)`: writes a daily plan to a file. You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate parameters and return type. Once again you must define two of these!
  
- `void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[])`: writes a weekly plan to a file. This function must call `storeDailyPlan()`. Note: you must apply the overloaded stream insertion operator here! Note: you must determine the appropriate parameters and return type. Once again you must define two of these!

- `void runApp(void)`: displays nine menu options. These include:
  1. Load weekly diet plan from file.
  2. Load weekly exercise plan from file.
  3.  Store weekly diet plan to file.
  4. Store weekly exercise plan to file.
  5. Display weekly diet plan to screen.
  6. Display weekly exercise plan to screen.
  7. Edit daily diet plan.
  8. Edit daily exercise plan.
  9. Exit.

Observation: Many of the functions in the FitnessAppWrapper class are overloaded. There’s one version for use on a DietPlan and another for an ExercisePlan. In the future, we could reuse these functions on generic plan types that are defined by a common base class, i.e., an abstract data type. Hence, in the future, we will study inheritance and the compiler generate code for us, instead of manually defining overloaded functions.

**BONUS:**
Create a linked list of ListNode and List to store the diet and exercise plans. You may need to implement a different linked list for each plan type. Other similarities could also be resolved by using templates.

## V. Grading Guidelines

This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:

- 5 pts - Appropriate top-down design, style, and commenting according to class standards
- 18 pts - Appropriate design and implementation of Class DietPlan (including member functions and data members)
  - 3 pts - 1 pt/each for declaring goal calories, plan name, and date
  - 5 pts - declaring and defining a constructor
  - 2 pts - declaring and defining a copy constructor
  - 2 pts - declaring and defining a destructor
  - 3 pts - declaring and defining editGoal()
  - 3 pts - declaring and defining stream insertion operator
- 18 pts - Appropriate design and implementation of Class ExercisePlan (including member functions and data members)
  - 3 pts - 1 pt/each for declaring goal steps, plan name, and date
  - 5 pts - declaring and defining a constructor
  - 2 pts - declaring and defining a copy constructor
  - 2 pts - declaring and defining a destructor
  - 3 pts - declaring and defining editGoal()
  - 3 pts - declaring and defining stream insertion operator
- 9 pts - Appropriate design and implementation of Class FitnessAppWrapper (including menu options, etc.)
  - 1 pt/each for correctly implementing each function
  - 2 pts - Correctly reading the weekly plans from a file stream
  - 2 pts - Correctly writing the weekly plans to a file stream
  - 1 pt - for correctly implementing runApp()
- 4 pts - Correctly overloading the stream extraction operator (total 2 stream insertion operators and 2 stream extraction operators)
- 3 pts - Efficient and appropriate design and implementation of Linked List
- BONUS: Up to 10 pts for correct circular implementation

---

# Summary and Step Guide for Completing the Assignment
## 1. Understand the Requirements
  - Carefully read through the assignment guidelines.
  - Identify the required classes (DietPlan, ExercisePlan, FitnessAppWrapper) and their functionalities.

## 2. Set Up the Development Environment
  - Open Microsoft Visual Studio 2019 and create a new project.
  - Ensure the project setup includes necessary header (.h) and source (.cpp) files.

## 3. Define Classes and Member Functions
  - Create the DietPlan and ExercisePlan classes:
    - Define data members: goal (calories or steps), plan name, and date.
    - Implement constructors, copy constructors, and destructors.
    - Implement getter and setter functions, including editGoal().
  - Implement the overloaded stream insertion (<<) and extraction (>>) operators for these classes.

## 4. Implement FitnessAppWrapper Class
  - Define functions for loading, displaying, and storing daily and weekly plans.
  - Implement the runApp() function to handle menu operations.

## 5. Overload Stream Operators
  - Ensure the overloaded << and >> operators are implemented correctly for both DietPlan and ExercisePlan classes.

## 6. Implement Linked List (BONUS)
  - If attempting the bonus, create linked list structures to handle the diet and exercise plans.

## 7. Write Test Cases
  - Write test cases to verify the correctness of insert, delete, sort, and shuffle functionalities.
  - Ensure edge cases are considered and tested.

## 8. Test the Program
  - Run the program and validate outputs against expected results.
  - Debug any issues that arise during testing.

## 9. Prepare Documentation
  - Write a test plan including sample input data, expected results, and screenshots.
  - Create a readme.txt file with assumptions, referenced files, and additional information.

## 10. Submit the Assignment
  - Zip the project files including code, header files, test plan, readme, and data files.
  - Upload the zipped file to the appropriate Canvas assignment submission folder.
















