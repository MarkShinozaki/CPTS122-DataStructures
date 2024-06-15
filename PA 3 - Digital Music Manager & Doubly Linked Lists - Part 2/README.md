# Programming Assignment 3: Digital Music Manager & Doubly Linked Lists - Part II

## I. Learner Objectives
**At the conclusion of this programming assignment, participants should be able to:**

- Design and implement a dynamic doubly linked list
- Allocate and de-allocate memory at runtime
- Manipulate links in a dynamic list
- Insert items into a dynamic linked list
- Delete items from a dynamic linked list
- Edit items in a dynamic linked list
- Traverse a dynamic linked list
- Implement and implement basic test cases
  
## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose C language programs
- Compile a program using Microsoft Visual Studio 2019
- Create basic test cases for a program
- Apply arrays, strings, and pointers
- Summarize differences between array notation and pointer notation
- Apply basic string handling library functions
- Apply and implement structs in C
- Apply and implement pointers in C
- Apply and implement dynamic memory in C
- Apply and implement the operations of a linked list

## III. Overview & Requirements
**In this assignment, you will complete the Digital Music Manager that you started in PA 2. You must implement the following features:**

- (4) insert
- (5) delete
- (7) sort
- (10) shuffle

You will also be required to write 3 test functions.

### What must "insert" do?
- The “insert” command must prompt the user for the details of a new record. The prompt must request the artist name, album title, song title, genre, song length, number of times played, and rating. The new record must be inserted at the front of the list.

### What must "delete" do?
- The “delete” command must prompt the user for a song title, and remove the matching record from the list. If the song title does not exist, then the list remains unchanged.

### What must "sort" do?
- The “sort” command must prompt the user for 4 different methods to sort the records in the list. These include:

  - Sort based on artist (A-Z)
  - Sort based on album title (A-Z)
  - Sort based on rating (1-5)
  - Sort based on times played (largest-smallest)

- Once a sort method is selected by the user, the sort must be performed on the records in the list. Consider using bubble sort, insertion sort, or selection sort.

### What must "shuffle" do?
- The “shuffle” command must provide a random order in which the songs are played. This command must not modify the links in the list. It must just specify the order in which songs are played, based on the position of the song in the list. For example, let’s say we have a list with 5 songs at positions 1 - 5 in the list, shuffle must generate an order 1 - 5 in which the songs are played. An order 2, 5, 3, 1, 4 would require that the second song in the list is played first, the fifth song in the list is played second, the third song in the list is played third, the first song in the list is played fourth, and the fourth song in the list is played fifth. The songs are accessed by traversing the list both forwards and backwards to satisfy the order. Hence, the need for a doubly linked list!

### What "test" functions are required?
You must design and implement three test functions. These test functions must not accept any arguments or return any values. They should be developed as void functions and should print the status of their tests in a separate header file than your implementation file. The results of your test functions should be placed in a separate source file from your implementation file. The test functions must cover the following scenarios:

- For the insert test function you must provide a test case with the following test point: artist name = “Perry, Katy”, album title = “Witness”, song title = “Chained to the Rhythm”, genre = “pop”, song length = “4:36”, times played = 1, rating = 6. You should think about what is your expected result? Should you be able to insert a song with -1 times played? Should you be able to add a song with rating 6? Is the head pointer of the list updated?

- For the delete test function you must provide a test case with the following test point: song title to delete = “Chained to the Rhythm”. List state = artist name = “Perry, Katy”, album title = “Witness”, song title = “Chained to the Rhythm”, genre = “pop”, song length = “4:36”, times played = 3, rating = 5 (the only song in the list). You should think about what is your expected result? Has the head pointer been updated? Is it NULL? Did the memory get released?

- For the shuffle test function you must provide a test case with the following test point: play order = 3, 1, 2. List state = you provide 3 songs. Does the shuffle play in the correct order?

## IV. Logical Block Diagram

**Once again, the logical block diagram for your doubly linked list should look like the following:**
```
    +------+     +------+     +------+     +------+
    | Data |<--->| Data |<--->| Data |<--->| Data |
    +------+     +------+     +------+     +------+
    | Prev |     | Prev |     | Prev |     | Prev |
    +------+     +------+     +------+     +------+
    | Next |     | Next |     | Next |     | Next |
    +------+     +------+     +------+     +------+
```

## VI. Grading Guidelines
- **This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:**

  - 5 pts - Appropriate top-down design, style, and commenting according to class standards
  - 17 pts - Correct “insert” command implementation
    - (7 pts - 1pt/attribute) For prompting and getting the details of a new record from the user
    - (10 pts) For correctly inserting the record at the front of the list
  - 24 pts - For correct “delete” command implementation
    - (3 pts) For prompting and getting the song title from the user
    - (6 pts) For searching for specific record matching the song title
    - (15 pts) For removing the matching record from the list, and reconnecting the list correctly
  - 24 pts - For correct “sort” command implementation
    - (3 pts) For prompting and getting the sort method from the user
    - (7 pts) For sorting based on artist (A-Z)
    - (7 pts) For sorting based on album title (A-Z)
    - (7 pts) For sorting based on rating (1-5)
    - (7 pts) For sorting based on times played (largest-smallest)
  - 15 pts - Correct “shuffle” command implementation
    - (5 pts) For prompting and implementing based on the number of songs in the list
    - (10 pts) For correctly traversing the list in both forward and backwards and playing the songs in the order generated
  - 10 pts - Robust test functions - 3 separate test functions
    - (3 pts) For testing the bounds of your insert feature
    - (3 pts) For testing the bounds of your delete feature
    - (3 pts) For testing the bounds of your shuffle feature
  - BONUS: Up to 15 pts for correct circular implementation

---

# Step-by-Step Guide to Completing Programming Assignment 3: Digital Music Manager & Doubly Linked Lists - Part II

## Step 1: Understand the Requirements
- Read the assignment guidelines thoroughly to understand the objectives and requirements.
- Review the data structure definitions, required functionalities, and the output format.

## Step 2: Set Up Your Development Environment
- Ensure you have Microsoft Visual Studio 2019 installed.
- Create a new project for the assignment.

## Step 3: Review Previous Implementation
- Review the code and structures implemented in PA 2.
- Identify areas where new features (insert, delete, sort, shuffle) need to be added.

## Step 4: Implement Insert Function
- Prompt the user for new record details.
- Insert the new record at the front of the doubly linked list.
- Ensure proper memory allocation and linking of nodes.

**Example:**
```c
void insertFront(Node** head, Record data) {
    Node* newNode = makeNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
```

## Step 5: Implement Delete Function
- Prompt the user for a song title.
- Search for the matching record in the list.
- Remove the matching record and update the links accordingly.

**Example:**
```c
void deleteNode(Node** head, char* songTitle) {
    Node* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->data.song, songTitle) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            if (temp == *head) {
                *head = temp->next;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}
```
## Step 6: Implement Sort Function
- Prompt the user for the sorting method.
- Implement sorting based on artist, album title, rating, and times played using suitable sorting algorithms.

**Example:**
```c
void sortList(Node** head, int sortMethod) {
    // Implement sorting logic based on sortMethod
}
```

## Step 7: Implement Shuffle Function
- Generate a random order for playing songs.
- Traverse the list in the specified order without modifying the links.

**Example:**
```c
void shuffleList(Node* head) {
    // Implement shuffle logic
}
```
## Step 8: Implement Test Functions
- Create test functions for insert, delete, and shuffle commands.
- Validate that the corresponding functions work as expected with edge cases.

**Example:**
```c
void testInsert(Node** head) {
    Record data = {"Perry, Katy", "Witness", "Chained to the Rhythm", "pop", {4, 36}, -1, 6};
    insertFront(head, data);
    // Validate the insert operation
}
```
## Step 9: Test Your Program
- Create test cases to ensure your program works as expected.
- Verify the correctness of the output by comparing it with expected results.

## Step 10: Prepare Documentation
- Write a test plan that includes sample input data, expected results, and screenshots of your program’s output.
- Create a readme.txt file with any assumptions, referenced files, and other relevant information.

## Step 11: Submit Your Assignment
- Zip all required files into a single file named `<your last name>_PA3.zip.`
- Upload the zip file to the appropriate Canvas assignment submission folder.

## Summary of Files to Include:
1. C program code files.
2. Header files.
3. Test plan document (Word).
4. readme.txt file.
5. musicPlaylist.csv file (if modified).
6. Any additional files required by your program.

## Tips:
- Break down the tasks into smaller, manageable functions.
- Continuously test your functions as you implement them.
- Follow good coding practices and maintain a clean, readable codebase.
  
