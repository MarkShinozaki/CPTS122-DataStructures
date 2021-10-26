#include "Header.h"

int Menu(void)
{
	int select;
	printf("\n\t| -><- Menu -><- | \n");
	printf("\n\t*-*-*-*-*-*-*-*-*-*\n");
	printf("\t<1>  Load\n\t<2>  Store\n\t<3>  Display\n\t<4>  Insert\n\t<5>  Delete\n\t<6>  Edit\n\t<7>  Sort\n\t<8>  Rate\n\t<9>  Play\n\t<10> Shuffle\n\t<11> Exit");
	printf("\n\t*-*-*-*-*-*-*-*-*-*\n");
	
	printf("\nSelect from Menu : ");
	scanf(" %d", &select);
	
	return select;
}

Node* MakeNode(Node* pMem)
{
	pMem = (Node*)malloc(sizeof(Node));
	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}

int Load(FILE* infile, Node** pList)
{
	char ReadLine[100] = "";
	Node* pMem = NULL, * pCur = NULL;
	Record nRecord = { "", };

	while (!feof(infile) && fgets(ReadLine, 100, infile))
	{
		pMem = MakeNode(pMem);

		if (ReadLine != NULL);
		{
			if (ReadLine[0] == '"')
			{
				strcpy(nRecord.Artist, strtok(ReadLine, ","));
				strcat(nRecord.Artist, ",");
				strcat(nRecord.Artist, strtok(NULL, ","));
			}
			else
			{
				strcpy(nRecord.Artist, strtok(ReadLine, ","));
			}
			strcpy(nRecord.Album_title, strtok(NULL, ","));
			strcpy(nRecord.Song_title, strtok(NULL, ","));
			strcpy(nRecord.Genre, strtok(NULL, ","));
			nRecord.Length.Minutes = atoi(strtok(NULL, ":"));
			nRecord.Length.Seconds = atoi(strtok(NULL, ","));
			nRecord.PlayBack = atoi(strtok(NULL, ","));
			nRecord.Rating = atoi(strtok(NULL, ","));

			pMem->data = nRecord;

			if (*pList == NULL)
			{
				*pList = pMem;
				pMem->pNext = NULL;
			}
			else
			{
				(*pList)->pPrev = pMem;
				pMem->pNext = *pList;
				*pList = pMem;
			}
		}
	}
	return 1;
}

void Store(FILE* outfile, Node** pList)
{
	Node* pCur = NULL;
	pCur = *pList;
	while (pCur != NULL)
	{
		fprintf(outfile, "%s,", pCur->data.Artist);
		fprintf(outfile, "%s,", pCur->data.Album_title);
		fprintf(outfile, "%s,", pCur->data.Song_title);
		fprintf(outfile, "%s,", pCur->data.Genre);
		fprintf(outfile, "%d:%d,", pCur->data.Length.Minutes, pCur->data.Length.Seconds);
		fprintf(outfile, "%d,", pCur->data.PlayBack);
		fprintf(outfile, "%d\n", pCur->data.Rating);

		pCur = pCur->pNext;
	}
}


void DisplaySong(Node* pList)
{
	Node* pCur = NULL;

	pCur = pList;
	while (pCur != NULL)
	{
		printf("\n\tArtist: %s", pCur->data.Artist);
		printf("\n\tSong title: %s", pCur->data.Song_title);
		printf("\n\t*-*-*-*-*-*-*-*-*-*-*-*-* \n");
		pCur = pCur->pNext;
	}
	putchar('\n');
}

void DisplayL(Node* pList)
{
	Node* pCur = NULL;

	pCur = pList;
	while (pCur != NULL)
	{
		printf("\n\tArtist: %s", pCur->data.Artist);
		printf("\n\tSong title: %s", pCur->data.Song_title);
		printf("\n\tAlbum title: %s", pCur->data.Album_title);
		printf("\n\tGenre:%s ", pCur->data.Genre);
		printf("\n\tLength: %d:%d ", pCur->data.Length.Minutes, pCur->data.Length.Seconds);
		printf("\n\tAmount of times played: %d", pCur->data.PlayBack);
		printf("\n\tRating: %d \n", pCur->data.Rating);
		printf("\n\t*-*-*-*-*-*-*-*-*-*-*-*-* \n");
		pCur = pCur->pNext;
	}
	putchar('\n');
}

int ArtistSearch(Node** pList, char* Artist, Node MultiAlbum[])
{
	Node* pCur = NULL;
	int search = 0, 
		index = 1;

	pCur = *pList;
	while (pCur != NULL)
	{
		if (strstr(pCur->data.Artist, Artist) != NULL)
		{
			MultiAlbum[index] = *pCur;
			printf("\n\t[%d]Artist : %s \n\t     Song : %s\n", index, MultiAlbum[index].data.Artist, MultiAlbum[index].data.Song_title);
			++index;
			search = 1;
		}
		pCur = pCur->pNext;
	}
	if (search == 1)//if found the artist
	{
		return index;
	}
	else
	{
		return 0;
	}
}


void DisplayR(Node* pCur)
{
	printf("\t<1> Artist : %s\n", pCur->data.Artist);
	printf("\t<2> Album title : %s \n", pCur->data.Album_title);
	printf("\t<3> Song title : %s \n", pCur->data.Song_title);
	printf("\t<4> Genre : %s \n", pCur->data.Genre);
	printf("\t<5> Song Length : %d:%d \n", pCur->data.Length.Minutes, pCur->data.Length.Seconds);
	printf("\t<6> Number times played : %d \n", pCur->data.PlayBack);
	printf("\t<7> Rating : %d \n\n", pCur->data.Rating);
} 


int Edit(Node** pList, char* Artist)
{
	int  index = 0, 
		select = 0, 
		select1 = 0;
	
	Node* pCur = NULL, 
		MultiAlbum[10] = { NULL };
	
	char 
		temp[50] = "";

	pCur = *pList;
	index = ArtistSearch(pList, Artist, MultiAlbum);

	if (index != 0)
	{
		do 
		{
			printf("\n\n Enter # associated with Artist Record you'd like to Edit: ");
			scanf("%d", &select);
			while (getchar() != '\n');
		} while (select > index);

		
		pCur = *pList;
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.Song_title, MultiAlbum[select].data.Song_title) == 0)
			{
				*pCur = MultiAlbum[select];
				break;
			}
			pCur = pCur->pNext;
		}

		
		DisplayR(pCur);

		do
		{
			printf("\nSelect an attribute to modify (Enter Attribute #): ");
			scanf("%d", &select1);
			while (getchar() != '\n'); // buffer'\n'

		} while ((select1 > 7) || (select1 < 1));

		switch (select1)
		{
		case 1:
			printf("\nModify Artist Name from (%s) to : ", pCur->data.Artist);
			gets(temp);
			strcpy(pCur->data.Artist, temp);
			break;
		case 2:
			printf("\nModify Album title from (%s) to : ", pCur->data.Album_title);
			gets(temp);
			strcpy(pCur->data.Album_title, temp);
			break;
		case 3:
			printf("\nModify Song title from (%s) to : ", pCur->data.Song_title);
			gets(temp);
			strcpy(pCur->data.Song_title, temp);
			break;
		case 4:
			printf("\nModify Genre from (%s) to : ", pCur->data.Genre);
			gets(temp);
			strcpy(pCur->data.Genre, temp);
			break;
		case 5:
			printf("\nModify Song Length  from (%d:%d) to : " , pCur->data.Length.Minutes, pCur->data.Length.Seconds);
			scanf("%d:%d", &pCur->data.Length.Minutes, &pCur->data.Length.Seconds);
			while (getchar() != '\n');
			break;
		case 6:
			printf("\nModify amount of playbacks from (%d) to : ", pCur->data.PlayBack);
			scanf("%d", &pCur->data.PlayBack);
			while (getchar() != '\n');
			break;
		case 7:
			printf("\nModify the Rating from (%d) to : ", pCur->data.Rating);
			scanf("%d", &pCur->data.Rating);
			while (getchar() != '\n');
			break;
		}
		printf("\n***Change has been made, Please Store Information!***\n\n");
		DisplayR(pCur);
		system("pause");
		return 1;
	}
	else
	{
		puts("\t\"Can not find that Artist!\"");
		return 0;
	}
}


Node* SongSearch(Node** pList, char* Tsong)
{
	Node* pCur = NULL;
	int 
		search = 0;

	pCur = *pList;
	while (pCur != NULL)
	{
		if (strcmp(pCur->data.Song_title, Tsong) == 0)
		{
			search = 1;
			return pCur;
			break;
		}
		pCur = pCur->pNext;
	}
	if (search == 0)
	{
		puts("\n\t\"Cannot find that song!\"");
		return NULL;
	}
}


void Rate(Node** pList)
{
	Node* pCur = NULL;
	char option = '\0', 
		song[50] = "";

	

	pCur = *pList;
	while (pCur != NULL)
	{
		printf("\t%15s _ rate : %d\n", pCur->data.Song_title, pCur->data.Rating);
		pCur = pCur->pNext;
	}

	
	do {
		printf("\nDo you want to change rating? (Yes or No) : ");
		scanf("%c", &option);
		while (getchar() != '\n'); 

	} while ((option != 'Y') && (option != 'y') && (option != 'N') && (option != 'n'));

	if ((option == 'Y') || (option == 'y'))
	{

		do 
		{
			pCur = *pList;
			printf("\n- Enter the title of the song which you want to edit rating : ");
			gets(song);
			pCur = SongSearch(pList, song);

		} while (pCur == NULL);

		
		printf("\tsong : %s \n rate : %d\n", pCur->data.Song_title, pCur->data.Rating);
		do
		{
			printf("\nChange Rating to: ");
			scanf("%d", &pCur->data.Rating);
			while (getchar() != '\n'); 
			if ((pCur->data.Rating < 1) || (pCur->data.Rating > 5))
			{
				puts(" Pleas Enter a integer between (1 - 5)!!");
			}
		} while ((pCur->data.Rating < 1) || (pCur->data.Rating > 5));

	}

}

void Selection(Node** pList)
{
	Node* pCur = NULL, 
		* Play = NULL, 
		* pHead = NULL;
	
	char temp_song[50] = "";
	
	int flag = 0;

	pHead = *pList;

	do //search matched song
	{
		pCur = *pList;
		printf("\n Enter the title of song you want to play first : ");
		gets(temp_song);
		pCur = SongSearch(pList, temp_song);

	} while (pCur == NULL);

	if (Play == NULL)
	{
		Play = pCur;
	}
	while (Play->pNext != NULL)
	{
		system("cls");
		printf("\t__________________________\n");
		puts("\n\t  Playing Music....\t");
		printf("\t__________________________\n");
		printf("\n");

		DisplayR(Play);
		Play = Play->pNext;
		Sleep(1000);
	}

	system("cls");
	printf("\t__________________________\n");
	puts("\n\t  Playing Music....\t");
	printf("\t__________________________\n");
	printf("\n");
	DisplayR(Play);
	Sleep(1000);

	while (strcmp(pCur->data.Song_title, pHead->data.Song_title) != 0)
	{
		system("cls");
		printf("\t__________________________\n");
		puts("\n\t  Playing Music....\t");
		printf("\t__________________________\n");
		printf("\n");

		DisplayR(pHead);
		pHead = pHead->pNext;
		Sleep(1000);
	}
	printf("\t__________________________\n");
	puts("\n\t  All Music has been played\t");
	printf("\t__________________________\n");
	printf("\n");
	system("pause");
	system("cls");

}

void Order(Node** pList)
{
	Node* pCur = NULL;

	pCur = *pList;
	while (pCur->pNext != NULL)
	{
		system("cls");
		printf("\t__________________________\n");
		puts("\n\t  Playing Music....\t");
		printf("\t__________________________\n");
		printf("\n");

		DisplayR(pCur);
		Sleep(1000);

		pCur = pCur->pNext;
	}

	system("cls");
	printf("\t__________________________\n");
	puts("\n\t  Playing Music....\t");
	printf("\t__________________________\n");
	printf("\n");

	DisplayR(pCur);
	Sleep(1000);
	
	printf("\t__________________________\n");
	puts("\n\t  All Music has been played\t");
	printf("\t__________________________\n");
	printf("\n");
	system("pause");
	system("cls");
}




void Insert(Node** pList)
{
	Node* pMem = NULL;
	int flag_rating = 0;
	pMem = MakeNode(pMem);

	printf("\n Enter the name of Artist: ");
	scanf("%s", pMem->data.Artist);
	printf("\n Enter the title of Album: ");
	scanf("%s", pMem->data.Album_title);
	printf("\n Enter the title of song: ");
	scanf("%s", pMem->data.Song_title);
	printf("\n Enter the type of Genre: ");
	scanf("%s", pMem->data.Genre);
	printf("\n Enter the length of the song (min:sec, for example 4:10): ");
	scanf("%d:%d", &pMem->data.Length.Minutes, &pMem->data.Length.Seconds);
	printf("\n Enter the number of times played : ");
	scanf("%d", &pMem->data.PlayBack);
	do
	{
		printf("\n Enter rating (Enter an integer between 1 - 5): ");
		scanf("%d", &pMem->data.Rating);
	} while ((pMem->data.Rating > 5) || (pMem->data.Rating < 1));

	if (*pList == NULL)
	{
		*pList = pMem;
		pMem->pNext = NULL;
	}
	else
	{
		(*pList)->pPrev = pMem;
		pMem->pNext = *pList;
		*pList = pMem;
	}
}
int Delete(Node** pList, char* Song)
{
	Node* pCur = NULL, * pPrev = NULL, * pNext = NULL;
	int success = 0;
	pCur = *pList;

	while ((pCur != NULL) && (strcmp(pCur->data.Song_title, Song) != 0))
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	if (pCur != NULL)
	{
		if (pPrev != NULL)
		{
			pPrev->pNext = pCur->pNext;
			free(pCur);
		}
		else
		{
			*pList = (*pList)->pNext;
			free(pCur);
		}
		success = 1;
	}
	return success;

}

int NodeSize(Node* pList, Node* pCur, int length)
{
	if (length == 0)
	{
		DisplayL(pList);
		pCur = pList;
	}
	if (pCur != NULL)
	{
		return NodeSize(pList, pCur->pNext, ++length);
	}
	else
	{
		return length;
	}
}



void SortByArtist(Node** pList)
{
	Node* pCur = NULL, 
		* pNext = NULL;

	char Temp_Artist[50] = "",
		Next_Artist[50] = "";

	int size = 0;

	size = NodeSize(*pList, pCur, size);

	pCur = *pList;
	pNext = pCur->pNext;

	for (int i = 0; i < size; ++i)
	{
		while (pNext != NULL)
		{
			if (pCur->data.Artist[0] == '"')
			{
				strtok(pCur->data.Artist, ", ");
				strcpy(Temp_Artist, strtok(NULL, ", "));
				strcat(pCur->data.Artist, ", ");
				strcat(pCur->data.Artist, Temp_Artist);
			}
			else
			{
				strcpy(Temp_Artist, pCur->data.Artist);
			}

			if (pNext->data.Artist[0] == '"')
			{
				strtok(pNext->data.Artist, ", ");
				strcpy(Next_Artist, strtok(NULL, ", "));
				strcat(pNext->data.Artist, ", ");
				strcat(pNext->data.Artist,Next_Artist);
			}
			else
			{
				strcpy(Next_Artist, pNext->data.Artist);
			}

			if (strcmp(Temp_Artist, Next_Artist) > 0)
			{
				if (pCur->pPrev == NULL)
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)
				{
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	DisplayL(*pList);
}

void SortByAlbum(Node** pList)
{
	Node* pCur = NULL, * pNext = NULL;
	int size = 0;

	size = NodeSize(*pList, pCur, size);

	pCur = *pList;
	pNext = pCur->pNext;

	for (int i = 0; i < size; ++i)
	{
		while (pNext != NULL)
		{
			if (strcmp(pCur->data.Album_title, pNext->data.Album_title) > 0)
			{
				if (pCur->pPrev == NULL)
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)
				{
					
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	DisplayL(*pList);


}

void SortByRating(Node** pList)
{
	Node* pCur = NULL, * pNext = NULL;
	int size = 0;

	size = NodeSize(*pList, pCur, size);

	pCur = *pList;
	pNext = pCur->pNext;

	for (int i = 0; i < size; ++i)
	{
		while (pNext != NULL)
		{
			if (pCur->data.Rating > pNext->data.Rating)
			{
				if (pCur->pPrev == NULL)
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)
				{
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	DisplayL(*pList);
}

void SortByPlayback(Node** pList)
{
	Node* pCur = NULL, * pNext = NULL;
	int size = 0;

	size = NodeSize(*pList, pCur, size);

	pCur = *pList;
	pNext = pCur->pNext;


	for (int i = 0; i < size; ++i)
	{
		while (pNext != NULL)
		{
			if (pCur->data.PlayBack < pNext->data.PlayBack)
			{
				if (pCur->pPrev == NULL)
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)
				{
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	DisplayL(*pList);
}


void Shuffle(Node** pList)
{
	Node* pCur = NULL;
	int size = 0, 
		random[100] = { 0 }, 
		flag = 0, 
		count = 0;

	size = NodeSize(*pList, pCur, size);
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; ++i)
	{
		do
		{
			flag = 0;
			random[i] = rand() % size + 1;

			for (int j = 0; j < i; ++j) 
			{
				if (random[j] == random[i])
				{
					flag = 1;
					break;
				}
			}

		} while (flag == 1);
	}

	for (int i = 0; i < size; ++i)
	{
		pCur = *pList;

		while (count < random[i] - 1)
		{
			pCur = pCur->pNext;
			++count;
		}

		
		system("cls");
		printf("\t__________________________\n");
		puts("\n\t  Playing Music....\t");
		printf("\t__________________________\n");
		printf("\n");
		printf("%d) order from list : %d\n", i + 1, random[i]);

		DisplayR(pCur);
		Sleep(1500);

		count = 0;
	}

}
