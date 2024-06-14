/*
Programmer: Mark Shinozaki
Class: Cpts 122; Section 1
Lab Assignment 2: Data Structures and Dynamic Singly Linked Lists in C
Date: 9/6/21

Overview & Requirments:
 - Design, implement and test a dynamic singly linked list in C
 - Programmatically traverse through a singly linked list 
 - Implement insertions, in order, into singly linked list 
 - Implement deletions from a singly linked list 
 - Support modifications and printings of data in a singly linked list
 - Develop a menu system 
 - Apply standard library functions malloc() and free()
 - Design and implement basic manual unit tests 

Description:
 - Build an application in C, for storing contact information.
 you must store a name, phone number, email, and professional title.
 Your application must support insertions in order (based on last name)
 , deletions, modifications, and printings of contacts 

*/

#include "Header.h"

int main(int argc, char* argv[])
{
	FILE* infile = NULL;
	infile = fopen("ContactList.csv", "r");
	Node* pList = NULL;
	int option = 0;
	
	do 
	{
		printf("1. Load");
		printf("2. Store");
		printf("3. Insert");
		printf("4. Edit");
		printf("5. Delete");
		printf("6. print List");
		printf("7. Exit");
		printf("pick option above:");
		scanf("%d", option);
		switch (option)
		{
			
				// load 
			case 1: 
			


				//store
			case 2:
			
				// insert 
			case 3:
			
				// Edit
			case 4:
			
				// Delete 
			case 5:
			
				// Print 
			case 6:
			
				// Exit
			case 7:
				
				exit("system");
				break;

		}
	} while (option != 7);

	


	return 0;
}




