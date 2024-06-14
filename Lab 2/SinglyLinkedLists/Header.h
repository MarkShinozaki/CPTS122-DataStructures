#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum boolean
{
	FALSE, TRUE
}Boolean;

typedef struct contact
{
	char name[50];
	char phone[12];
	char email[50];
	char title[20];
}Contact;

typedef struct node
{
	Contact data; // data of the node
	struct node* pNext; // address of the next node
}Node;


// Description: Allocates space for a Node on the heap and initializes the Node
// with the information found in newData. 
// Returns: The address of the start of the block of memory on the heap 
// or NULL if no memory was allocated 

Node* makeNode(Contact newData);

// Description: Uses makeNode() to allocate space for a new Node
// and inserts the new node into the list in alphabetic order
// ('a' - 'z')
// based on the name field 
// Returns: TRUE if memory was allocated for a Node; False otherwise 

Boolean insertContactInOrder(Node** pList, Contact newData);

// Description: Deletes a Contact in the list based on the name field;
// deletes the first occurance of the name
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise

Boolean deleteContact(Node ** pList, Contact newData);

// Description: Edits a Contact in the list based on the name field;
// edits the first occurance of the name 
// Returns: TRUE if the Contact was found; FALSE otherwise 

Boolean editContact(Node* pList, Contact newData);

// Description: Loads all Contact information from the give file,
// in alphabetic order, based on the name, into the list 
// Returns: TRUE if all contacts were loaded; FALSE otherwise

Boolean loadContacts(FILE* infile, Node** pList); 

// Description: Stores all contact information from the list into 
// the given file 
// Returns: TRUE if all Contacts were stored; FALSE otherwise

Boolean storeContacts(FILE* infile, Node* pList);

// Description: Prints all contact information in the list
// Returns: Nothing 

void printList(Node* pList);






