#include "Header.h"


Node* makeNode(const Contact* newData)
{
	Node* pMem = (Node*)malloc(sizeof(Node));
	//nNode->pNext = NULL;
	return pMem;
}

Boolean insertContactInOrder(Node** pList, Contact newData)
{

}

Boolean deleteContact(Node** pList, Contact newData)
{

}

Boolean editContact(Node* pList, Contact newData)
{

}

Boolean loadContacts(FILE* infile, Node** pList)
{
	
	Node* Contacts = NULL;
	char line[100] = "";
	Contact person = { "", };

	Contacts = makeNode(pList);

	if (Contacts == NULL)
	{
		printf("Memory was not allocated");
	}
	else
	{
		printf("\nMemory was Successfully allocated\n");
		if (infile == NULL)
		{
			printf("file was not successfully opened!");
		}
		else
		{
			printf("\nfile was successfully opened!\n");
			while (!feof(infile) && fgets(line, 100, infile))
			{
				strcpy(person.name, strtok(line, ","));
				strcpy(person.phone, strtok(NULL, ","));
				strcpy(person.email, strtok(NULL, ","));
				strcpy(person.title, strtok(NULL, ","));
				pList = pList->pNext;
			}
		}

	}
}

Boolean storeContacts(FILE* infile, Node* pList)
{

}

void printList(Node* pList)
{

}