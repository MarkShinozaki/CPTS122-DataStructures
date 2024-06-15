# Programming Assignment 5: Grocery Store Simulation

## I. Learner Objectives
**At the conclusion of this programming assignment, participants should be able to:**

- Design and implement a dynamic queue
- Allocate and de-allocate memory at runtime
- Manipulate links in a dynamic queue
- Insert items into a dynamic queue
- Delete items from a dynamic queue
- Traverse a dynamic queue
- Design, implement, and apply test cases in C++
- Design test classes in C++

## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose C++ language programs
- Create basic test cases for a program
- Apply arrays, strings, and pointers
- Summarize differences between array notation and pointer notation
- Apply pointer arithmetic
- Apply basic string handling library functions
- Define and implement classes in C++
- Summarize the operations of a linked list
- Describe the operations of a queue including: enqueue(), dequeue(), printQueue()

## III. Overview & Requirements
Note: parts of this assignment were inspired by Deitel and Deitel's Supermarket Simulation problem. We've all had the pleasant experience of standing in line at the grocery store. As I'm standing in line I'm always trying to figure out if I chose the line with the fastest service. In most cases, I fail, miserably. Let's write a program to simulate two lines in a grocery store, which will allow you to better understand which line has the fastest time. Note: you're all required to write some test cases for this program. I highly recommend that you start writing your tests before you start implementing any simulation code. This will allow you to figure out a way to test the application before you begin. More on this as we get started.

For this assignment you will need to simulate two lines using queues. This will require that you develop enqueue(), dequeue(), printQueue(), and isEmpty() operations on a queue. Although you will need to develop two queues, each one of these will consist of the same kind of queue nodes. Define a queue node in the following manner:

```c++
class Data {
public:
    // Member functions

private:
    int customerNumber;  // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;     // Random time; varies between express and normal lanes; units in minutes
    int totalTime;       // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
    // This memory needs to be allocated on the heap!
};

class QueueNode {
public:
    // Member functions

private:
    Data *pData;         // The memory for Data will need to be allocated on the heap as well!
    QueueNode *pNext;
};

class Queue {
public:
    // Member functions

private:
    QueueNode *pHead;
    QueueNode *pTail;
};
```

One of your queues will represent the express lane and the other a normal lane. You will randomly generate arrival times and service times of customers into each lane. The express lane has customers arrive every one to five minutes, and customers arrive every three to eight minutes in the normal lane. Service times vary from one to five minutes, and three to eight minutes, for express and normal lane customers, respectively. As customers arrive, each line will print a message stating which customer has arrived at what time, along with the customer's arrival time and customer number. When customers have finished checking out, print a message indicating which customer finished checking out at what time, and remove that customer from the line. Allow for the program to run for a number of minutes, which is inputted by the user.

**The general program flow is as follows:**

1. Randomly generate numbers between 1 - 5 and 3 - 8 for express and normal lanes, respectively. This represents the arrival time of the first customer into each lane. Set the variable for total time elapsed to 0.

2. As customers arrive to the queue, randomly generate a number for the service time for each customer and add them to the queue. When a customer is done being serviced, print a message and remove the customer from the queue. The total time elapsed should be updated by one minute.

Hints: Since the simulation time minute is really one unit of time. Thus, the incrementing of an integer variable represents the passing of one minute in elapsed time.

**Required test cases:**

1. Define a class Data in a separate .h file. You must declare a class QueueNode in a separate .h file and define your queue class. You must also place your test case implementations in a separate .cpp file from your other classes.

2. Create one test file for the following test cases. You must write the following test cases:
  - Tests for enqueue() operation on an empty queue
  - Tests for enqueue() operation on a queue with one node
  - Tests for enqueue() operation on a queue with two nodes
  - Tests for dequeue() operation on an empty queue
  - Tests for dequeue() operation on a queue with one node
  - Tests for dequeue() operation on a queue with two nodes
3. Write a short write-up on your simulation for 24 hours.

**BONUS**
1. Modify QueueNode such that it contains a pointer to the start of a dynamic singly linked list. The linked list will build the grocery list of items for the person. These items should be strings like "cereal", "milk", "steak", etc. Adjust the serviceTime of the QueueNode so that it is no longer random, but proportional to the number of items for the person served.


## V. Grading Guidelines:

This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:

- 5 pts - Appropriate top-down design, style, and commenting according to class standards
- 15 pts - Correct usages of two queues in simulation
- 5 pts - Correct Data class
- 5 pts - Correct QueueNode class
- 10 pts - Correct Queue class
- 10 pts - Correct constructors/destructors for the classes
- 5 pts - Correct getters/setters for the classes
- 5 pts - Correct printQueue()
- 5 pts - Correct isEmpty()
- 10 pts - Correct enqueue()
- 10 pts - Correct dequeue()
- 25 pts (2 pts/test case) - Correct test cases for the application
- BONUS: Up to 20 pts for implementation of grocery item list/customer

---

# Summary and Step Guide for Completing the Assignment

1. Understand the Requirements
  - Carefully read through the assignment guidelines.
  - Identify the required classes (Data, QueueNode, Queue) and their functionalities.

2. Set Up the Development Environment
  - Open Microsoft Visual Studio 2019 and create a new project.
  - Ensure the project setup includes necessary header (.h) and source (.cpp) files.

3. Define Classes and Member Functions
  - Create the Data class:
    - Define data members: customerNumber, serviceTime, and totalTime.
    - Implement necessary member functions.
  - Create the QueueNode class:
    - Define data members: pointer to Data and pointer to QueueNode.
  - Create the Queue class:
    - Define data members: pHead and pTail.
    - Implement the enqueue(), dequeue(), printQueue(), and isEmpty() functions.

4. Implement Queue Operations
  - Implement the enqueue() operation for adding customers to the queue.
  - Implement the dequeue() operation for removing customers from the queue.
  - Implement the printQueue() operation to display the queue.
  - Implement the isEmpty() operation to check if the queue is empty.

5. Develop the Simulation Logic
  - Simulate two queues (express lane and normal lane).
  - Randomly generate arrival times and service times for customers.
  - Print messages for customer arrival and departure.
  - Update the total time elapsed and manage the queue operations.

6. Write Test Cases
  - Write test cases to verify the correctness of enqueue(), dequeue(), printQueue(), and isEmpty() operations.
  - Ensure edge cases are considered and tested.

7. Implement **Bonus** (Optional)
  - Modify `QueueNode` to include a pointer to a dynamic singly linked list for grocery items.
  - Adjust the `serviceTime` based on the number of items in the list.

8. Test the Program
  - Run the program and validate outputs against expected results.
  - Debug any issues that arise during testing.

9. Prepare Documentation
  - Write a short write-up on your simulation for 24 hours.
  - Create a readme.txt file with assumptions, referenced files, and additional information.

10. Submit the Assignment
  - Zip the project files including code, header files, test plan, readme, and data files.
  - Upload the zipped file to the appropriate Canvas assignment submission folder.










