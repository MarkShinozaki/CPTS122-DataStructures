# Lab 2

## I. Learner Objectives
- At the conclusion of this programming assignment, participants should be able to:
  - Design, implement and test a dynamic singly linked list in C
  - Programmatically traverse through a singly linked list
  - Implement insertions, in order, into a singly linked list
  - Implement deletions from a singly linked list
  - Support modifications and printings of data in a singly linked list
  - Develop a menu system
  - Apply standard library functions malloc() and free()
  - Design and implement basic manual unit tests

## II. Prerequisites
- Before starting this programming assignment, participants should be able to:
  - Analyze a basic set of requirements for a problem
  - Compose a small C language program
  - Compile a C program using Microsoft Visual Studio 2019
  - Create test cases for a program
  - Apply and implement arrays and strings in C
  - Apply and implement recursion in C
  - Apply and implement structs in C
  - Apply and implement pointers in C
  - Apply and implement dynamic memory in C

## III. Overview & Requirements
- This lab, along with your TA, will help you navigate through designing, implementing, and testing a dynamic linked list.

**Tasks:**
1. Linked lists may be used to implement many real-world applications. Recall, linked lists are data structures, which represent collections of nodes that may be accessed sequentially via a pointer to the first node. A node contains data and a pointer to the next node in sequence. When the last node in the list is reached, its next pointer is `NULL`. A logical view of a singly linked list of integers is illustrated below:
```c
[42] -> [100] -> [235] -> NULL
```
Build an application, in C, for storing contact information (you must have one header file and two source files). For each contact you must store a name, phone number, email, and professional title. Your application must support insertions in order (based on last name), deletions, modifications, and printings of contacts. For this task you will be required to implement a dynamic singly linked list, which grows and shrinks at runtime. Build a menu that allows the user to add, remove, edit, print, store, and load contact information. The `store` feature should write contact information found in the list to a file. The `load` feature should read contact information from the same file into the list. Note: your list should store the contact information in a struct called `Contact`. Each `Node` must be a struct, which consists of a `Contact` and a pointer to the next `Contact` in the list. Please see below.

```c
typedef enum boolean {
    FALSE, TRUE
} Boolean;

typedef struct contact {
    char name[50];
    char phone[12]; // 18005557777
    char email[50];
    char title[20];
} Contact;

typedef struct node {
    Contact data;
    struct node *pNext;
} Node;
```

- Which list operations should you support? There are more than the ones listed below!

```c
// Description: Allocates space for a Node on the heap and initializes the Node with the information found in newData.
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated
Node *makeNode(Contact newData);

// Description: Uses makeNode() to allocate space for a new Node and inserts the new Node into the list in alphabetic order
// ('a' - 'z')
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactInOrder(Node **pList, Contact newData);

// Description: Deletes a Contact in the list based on the name field; deletes the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean deleteContact(Node **pList, Contact searchContact);

// Description: Edits a Contact in the list based on the name field; edits the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean editContact(Node **pList, Contact searchContact);

// Description: Loads all contact information from the given file, in alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE *infile, Node **pList);

// Description: Stores all contact information from the list into the given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
Boolean storeContacts(FILE *infile, Node *pList);

// Description: Prints all contact information in the list
// Returns: Nothing
void printList(Node *pList);
```

2. Test your application. In the same project, create one more header file `testList.h` and source file `testList.c` (for a total of at least five files). The `testList.h` file should contain function prototypes for test functions you will use on your list functions. The `testList.c` source file should contain the implementations for these test functions. You will be designing and implementing unit tests. You will have at least one test function per application function. Your test functions must display a message "test failed" or "test passed" depending on the test result. For example, you will have an application function called `deleteContact()` (or a function very similar) that was used to remove contact information from the list. In this task, you will need to create a test function called `testDeleteContact()` which inserts various contact information directly into `deleteNode()` to see if it works correctly.

## Solution Implementation 
### Contact Mangement System 

**contact.h**
```c
#ifndef CONTACT_H
#define CONTACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean {
    FALSE, TRUE
} Boolean;

typedef struct contact {
    char name[50];
    char phone[12]; // 18005557777
    char email[50];
    char title[20];
} Contact;

typedef struct node {
    Contact data;
    struct node *pNext;
} Node;

// Function prototypes
Node *makeNode(Contact newData);
Boolean insertContactInOrder(Node **pList, Contact newData);
Boolean deleteContact(Node **pList, Contact searchContact);
Boolean editContact(Node **pList, Contact searchContact);
Boolean loadContacts(FILE *infile, Node **pList);
Boolean storeContacts(FILE *outfile, Node *pList);
void printList(Node *pList);

#endif
```
**contact.c**
```c
#include "contact.h"

Node *makeNode(Contact newData) {
    Node *pMem = (Node *)malloc(sizeof(Node));
    if (pMem != NULL) {
        pMem->data = newData;
        pMem->pNext = NULL;
    }
    return pMem;
}

Boolean insertContactInOrder(Node **pList, Contact newData) {
    Node *pMem = makeNode(newData), *pCur = *pList, *pPrev = NULL;
    if (pMem == NULL) return FALSE;

    while (pCur != NULL && strcmp(newData.name, pCur->data.name) > 0) {
        pPrev = pCur;
        pCur = pCur->pNext;
    }

    if (pPrev == NULL) {
        pMem->pNext = *pList;
        *pList = pMem;
    } else {
        pPrev->pNext = pMem;
        pMem->pNext = pCur;
    }

    return TRUE;
}

Boolean deleteContact(Node **pList, Contact searchContact) {
    Node *pCur = *pList, *pPrev = NULL;

    while (pCur != NULL && strcmp(searchContact.name, pCur->data.name) != 0) {
        pPrev = pCur;
        pCur = pCur->pNext;
    }

    if (pCur == NULL) return FALSE;

    if (pPrev == NULL) {
        *pList = pCur->pNext;
    } else {
        pPrev->pNext = pCur->pNext;
    }

    free(pCur);
    return TRUE;
}

Boolean editContact(Node **pList, Contact searchContact) {
    Node *pCur = *pList;

    while (pCur != NULL && strcmp(searchContact.name, pCur->data.name) != 0) {
        pCur = pCur->pNext;
    }

    if (pCur == NULL) return FALSE;

    pCur->data = searchContact;
    return TRUE;
}

Boolean loadContacts(FILE *infile, Node **pList) {
    Contact temp;
    while (fscanf(infile, "%s %s %s %s", temp.name, temp.phone, temp.email, temp.title) != EOF) {
        if (!insertContactInOrder(pList, temp)) return FALSE;
    }
    return TRUE;
}

Boolean storeContacts(FILE *outfile, Node *pList) {
    Node *pCur = pList;
    while (pCur != NULL) {
        fprintf(outfile, "%s %s %s %s\n", pCur->data.name, pCur->data.phone, pCur->data.email, pCur->data.title);
        pCur = pCur->pNext;
    }
    return TRUE;
}

void printList(Node *pList) {
    Node *pCur = pList;
    while (pCur != NULL) {
        printf("Name: %s\nPhone: %s\nEmail: %s\nTitle: %s\n\n", pCur->data.name, pCur->data.phone, pCur->data.email, pCur->data.title);
        pCur = pCur->pNext;
    }
}
```
**main.c**
```c
#include "contact.h"

void displayMenu() {
    printf("Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Edit Contact\n");
    printf("4. Print Contacts\n");
    printf("5. Store Contacts\n");
    printf("6. Load Contacts\n");
    printf("7. Exit\n");
}

int main() {
    Node *pList = NULL;
    int choice;
    Contact temp;
    char filename[50];
    FILE *file;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(temp.name, 50, stdin);
                temp.name[strcspn(temp.name, "\n")] = '\0'; // remove newline character
                printf("Enter phone: ");
                fgets(temp.phone, 12, stdin);
                temp.phone[strcspn(temp.phone, "\n")] = '\0'; // remove newline character
                printf("Enter email: ");
                fgets(temp.email, 50, stdin);
                temp.email[strcspn(temp.email, "\n")] = '\0'; // remove newline character
                printf("Enter title: ");
                fgets(temp.title, 20, stdin);
                temp.title[strcspn(temp.title, "\n")] = '\0'; // remove newline character
                if (insertContactInOrder(&pList, temp)) {
                    printf("Contact added successfully!\n");
                } else {
                    printf("Failed to add contact.\n");
                }
                break;
            case 2:
                printf("Enter name of contact to delete: ");
                fgets(temp.name, 50, stdin);
                temp.name[strcspn(temp.name, "\n")] = '\0'; // remove newline character
                if (deleteContact(&pList, temp)) {
                    printf("Contact deleted successfully!\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                printf("Enter name of contact to edit: ");
                fgets(temp.name, 50, stdin);
                temp.name[strcspn(temp.name, "\n")] = '\0'; // remove newline character
                printf("Enter new phone: ");
                fgets(temp.phone, 12, stdin);
                temp.phone[strcspn(temp.phone, "\n")] = '\0'; // remove newline character
                printf("Enter new email: ");
                fgets(temp.email, 50, stdin);
                temp.email[strcspn(temp.email, "\n")] = '\0'; // remove newline character
                printf("Enter new title: ");
                fgets(temp.title, 20, stdin);
                temp.title[strcspn(temp.title, "\n")] = '\0'; // remove newline character
                if (editContact(&pList, temp)) {
                    printf("Contact edited successfully!\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                printList(pList);
                break;
            case 5:
                printf("Enter filename to store contacts: ");
                fgets(filename, 50, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // remove newline character
                file = fopen(filename, "w");
                if (file != NULL) {
                    if (storeContacts(file, pList)) {
                        printf("Contacts stored successfully!\n");
                    } else {
                        printf("Failed to store contacts.\n");
                    }
                    fclose(file);
                } else {
                    printf("Failed to open file.\n");
                }
                break;
            case 6:
                printf("Enter filename to load contacts: ");
                fgets(filename, 50, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // remove newline character
                file = fopen(filename, "r");
                if (file != NULL) {
                    if (loadContacts(file, &pList)) {
                        printf("Contacts loaded successfully!\n");
                    } else {
                        printf("Failed to load contacts.\n");
                    }
                    fclose(file);
                } else {
                    printf("Failed to open file.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
```

**testList.h**
```c
#ifndef TESTLIST_H
#define TESTLIST_H

void testInsertContactInOrder();
void testDeleteContact();
void testEditContact();

#endif
```

**testList.c**
```c
#include "contact.h"
#include "testList.h"

void testInsertContactInOrder() {
    Node *pList = NULL;
    Contact c1 = {"John Doe", "1234567890", "john@example.com", "Manager"};
    Contact c2 = {"Jane Smith", "0987654321", "jane@example.com", "Engineer"};
    Contact c3 = {"Alice Brown", "5555555555", "alice@example.com", "Technician"};

    if (insertContactInOrder(&pList, c1)) {
        printf("Test Insert Contact In Order 1 Passed\n");
    } else {
        printf("Test Insert Contact In Order 1 Failed\n");
    }

    if (insertContactInOrder(&pList, c2)) {
        printf("Test Insert Contact In Order 2 Passed\n");
    } else {
        printf("Test Insert Contact In Order 2 Failed\n");
    }

    if (insertContactInOrder(&pList, c3)) {
        printf("Test Insert Contact In Order 3 Passed\n");
    } else {
        printf("Test Insert Contact In Order 3 Failed\n");
    }
}

void testDeleteContact() {
    Node *pList = NULL;
    Contact c1 = {"John Doe", "1234567890", "john@example.com", "Manager"};
    Contact c2 = {"Jane Smith", "0987654321", "jane@example.com", "Engineer"};

    insertContactInOrder(&pList, c1);
    insertContactInOrder(&pList, c2);

    if (deleteContact(&pList, c1)) {
        printf("Test Delete Contact 1 Passed\n");
    } else {
        printf("Test Delete Contact 1 Failed\n");
    }

    if (deleteContact(&pList, c2)) {
        printf("Test Delete Contact 2 Passed\n");
    } else {
        printf("Test Delete Contact 2 Failed\n");
    }
}

void testEditContact() {
    Node *pList = NULL;
    Contact c1 = {"John Doe", "1234567890", "john@example.com", "Manager"};
    Contact c2 = {"John Doe", "1111111111", "john_doe@example.com", "Director"};

    insertContactInOrder(&pList, c1);

    if (editContact(&pList, c2)) {
        printf("Test Edit Contact Passed\n");
    } else {
        printf("Test Edit Contact Failed\n");
    }
}

int main() {
    testInsertContactInOrder();
    testDeleteContact();
    testEditContact();
    return 0;
}
```
--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%203">Lab 3</a>
</p>











