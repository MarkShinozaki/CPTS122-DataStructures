# Programming Assignment 2: Digital Music Manager & Doubly Linked Lists - Part I


## I. Learner Objectives
**At the conclusion of this programming assignment, participants should be able to:**

- Design and implement a dynamic doubly linked list
- Allocate and de-allocate memory at runtime
- Manipulate links in a dynamic list
- Insert items into a dynamic linked list
- Delete items from a dynamic linked list
- Edit items in a dynamic linked list
- Traverse a dynamic linked list

## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose C language programs
- Compile a program using Microsoft Visual Studio 2019
- Create basic test cases for a program
- Apply arrays, strings, and pointers
- Summarize differences between array notation and pointer notation
- Apply basic string handling library functions
- Implement user-defined functions
- Summarize the operations of a list

## III. Overview & Requirements
- Many of us have large digital music collections that are not always very well organized. We need to have a program that would enable us to store our collection, perform various operations, and apply useful features such as adding, deleting, sorting, and updating songs by genre, duration, and rating. For this assignment, you will write a basic digital music manager (DMM).

- Your DMM program must have a text-based interface that allows the user to select from a main menu of options including: (1) load, (2) store, (3) display, (4) insert, (5) delete, (6) edit, (7) sort, (8) rate, (9) play, (10) shuffle, and (11) exit. For Part I of the assignment, you only need to complete the main menu, (1) load, (2) store, (3) display, (4) insert, (5) delete, (6) edit, (8) rate, (9) play, and (11) exit options. The other features will be completed in the next part of the assignment.

### What must the main menu contain?

**The main menu must display the following commands:**

1. load
2. store
3. display
4. insert
5. delete
6. edit
7. sort
8. rate
9. play
10. shuffle
11. exit

After a command is selected and completed, your program must display the main menu again. This procedure will continue until the “exit” command is selected.

### What must "load" do?

The “load” command must read all records from a file called `musicPlaylist.csv` (you may find a sample file here) into a dynamic doubly linked list. The doubly linked list is considered to be empty. As each record is read from the file, it must be inserted at the end of the list. Each record consists of the following attributes:

- Artist - a string
- Album title - a string
- Song title - a string
- Genre - a string
- Song length - a struct `Duration` type consisting of seconds and minutes, both integers
- Number times played - an integer
- Rating - an integer (1 - 5)
  
Each attribute in each record must be separated by a comma in the CSV (comma-separated values) file. This means that you will need to parse each string to extract the required attributes for each record. Each field in each record will have a value. You do not need to perform any error handling.

Define a `Duration` struct to represent the above attributes. Also, do not forget that the `Song Length` must be stored in a struct called `Duration`. `Duration` is defined as follows:

```c
typedef struct duration {
    int minutes;
    int seconds;
} Duration;
```

### Finally, each struct Node in the doubly linked list must be defined as follows:
- Data - `a Record`
- Pointer to the next node
- Pointer to the previous node

### What must "store" do?
- The “store” command writes the current records, in the dynamic doubly linked list, to the `musicPlaylist.csv` file. The store will completely overwrite the previous contents in the file.

### What must "display" do?

- **The “display” command prints records to the screen. This command must support two methods, one of which is selected by the user:**

  - Print all records.
  - Print all records that match an artist.

### What must "edit" do?
- The “edit” command must allow the user to find a record in the list by artist. If there are multiple records with the same artist, then your program must prompt the user which one to edit. The user may modify all of the attributes in the record.

### What must "rate" do?
- The “rate” command must allow the user to assign a value of 1 to 5 to a song; 1 is the lowest rating and 5 is the highest rating. The user must be able to select which song to rate.

### What must "play" do?
- The “play” command must allow the user to select a song, and must start “playing” each song in order from the current song. Your program must display the name of the song that is currently playing and the song that will be played next for a short period of time. The user should have the option to stop the play at any time.

### What must "exit" do?
- The “exit” command writes the most recent list to the `musicPlaylist.csv` file. This command will completely overwrite the existing contents in the file.

## IV. Logical Block Diagram
**The logical block diagram for your doubly linked list should look like the following:**
```
    +------+     +------+     +------+     +------+
    | Data |<--->| Data |<--->| Data |<--->| Data |
    +------+     +------+     +------+     +------+
    | Prev |     | Prev |     | Prev |     | Prev |
    +------+     +------+     +------+     +------+
    | Next |     | Next |     | Next |     | Next |
    +------+     +------+     +------+     +------+
```

## V. Grading Guidelines
- **This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:**

  - 5 pts - Appropriate top-down design, style, and commenting according to class standards
  - 2 pts - For correct definition of struct `Record`
  - 2 pts - For correct definition of struct `Duration`
  - 3 pts - For correct definition of struct `Node`
  - 5 pts - For correctly displaying the main menu, getting the command from the user, and executing the command
  - 3 pts - For looping back to main menu after a command is executed
  - 10 pts - For correctly constructing a doubly linked list, including:
    1. Implementing a `makeNode` function, which allocates space for a struct node on the heap, and initializes the node
    2. Implementing an `insertEnd` function, which calls makeNode() and returns it for successfully initializing
    3. Implementing a `printList` function, which visits each node in the list and prints out the contents of the node
  - 5 pts - For correctly opening `musicPlaylist.csv` for mode “read”
  - 5 pts - For correctly reading each record from the file in the `loadPlaylist` function
  - 2 pts - For correctly converting and storing the fields into the `Record` struct
  - 1 pt - For correctly writing the current records in the list to the `musicPlaylist.csv` file.
    1. Correctly opening `musicPlaylist.csv` for mode “write”.
    2. Correctly writing the data back to the file, maintaining the .csv format
    3. Correctly closing the file
  - 3 pts - For correctly inserting records into `Record`
  - 5 pts - For correctly deleting records from `Record`
  - 3 pts - For correctly editing records in `Record`
  - 5 pts - For correctly rating records in `Record`
  - 2 pts - For correctly implementing the play functionality
  - 10 pts - For correctly implementing the display functionality:
    1. Display all records
    2. Display records by artist - should be able to use the same search function as used in the edit function
  - 10 pts - For correctly implementing the exit functionality:
    1. Correctly writing records to `musicPlaylist.csv` for mode “write”
    2. Correctly closing the file

--- 

# Step-by-Step Guide to Completing Programming Assignment 2: Digital Music Manager & Doubly Linked Lists - Part I

## Step 1: Understand the Requirements
- Read the assignment guidelines thoroughly to understand the objectives and requirements.
- Review the data structure definitions, required functionalities, and the output format.

## Step 2: Set Up Your Development Environment
- Ensure you have Microsoft Visual Studio 2019 installed.
- Create a new project for the assignment.

## Step 3: Define Data Structures
- Define the `Duration` struct to store the song length.
- Define the `Record` struct to store the song attributes.
- Define the `Node` struct for the doubly linked list.

**Example:**
```c
typedef struct duration {
    int minutes;
    int seconds;
} Duration;

typedef struct record {
    char artist[50];
    char album[50];
    char song[50];
    char genre[20];
    Duration songLength;
    int timesPlayed;
    int rating;
} Record;

typedef struct node {
    Record data;
    struct node *next;
    struct node *prev;
} Node;
```
## Step 4: Implement Linked List Operations
- Implement functions for inserting nodes at the end, deleting nodes, editing nodes, and displaying nodes.
- Implement functions for reading from and writing to the `musicPlaylist.csv` file.

**Example:**
```c
Node* makeNode(Record data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

void insertEnd(Node** head, Record data) {
    Node* newNode = makeNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->data.song);
        temp = temp->next;
    }
}
```
## Step 5: Implement Menu Functionality
- Implement a function to display the main menu and handle user input for different commands.
- Loop back to the main menu after each command is executed.

**Example:**
```c
void displayMenu() {
    printf("1. load\n2. store\n3. display\n4. insert\n5. delete\n6. edit\n7. sort\n8. rate\n9. play\n10. shuffle\n11. exit\n");
}

void executeCommand(int command, Node** head) {
    switch (command) {
        case 1:
            // Call load function
            break;
        case 2:
            // Call store function
            break;
        case 3:
            // Call display function
            break;
        // Handle other cases
        case 11:
            // Call exit function
            break;
        default:
            printf("Invalid command\n");
    }
}
```
## Step 6: Read and Parse Data
- Implement the `load` function to read records from `musicPlaylist.csv` and insert them into the doubly linked list.
  
**Example:**
```c
void loadPlaylist(Node** head) {
    FILE* file = fopen("musicPlaylist.csv", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Record data;
        // Parse line and populate data
        insertEnd(head, data);
    }
    fclose(file);
}
```
## Step 7: Implement Other Commands
- Implement the functions for `store`, `display`, `insert`, `delete`, `edit`, `rate`, and `play` commands.
- Ensure each function performs the required operations and updates the linked list accordingly.

## Step 8: Test Your Program
- Create test cases to ensure your program works as expected.
- Verify the correctness of the output by comparing it with expected results.

## Step 9: Prepare Documentation
- Write a test plan that includes sample input data, expected results, and screenshots of your program’s output.
- Create a readme.txt file with any assumptions, referenced files, and other relevant information.

## Step 10: Submit Your Assignment
- Zip all required files into a single file named `PA2.zip`.
- Upload the zip file to the appropriate Canvas assignment submission folder.

## Summary of Files to Include:
1. C program code file.
2. C header file.
3. Test plan document (Word).
4. readme.txt file.
5. musicPlaylist.csv file (if modified).
6. Any additional files required by your program.

## Tips
- Break down the tasks into smaller, manageable functions.
- Continuously test your functions as you implement them.
- Follow good coding practices and maintain a clean, readable codebase.
