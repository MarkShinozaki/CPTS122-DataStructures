#include "Header.h"

/************************************
* Programmer: Mark Shinozaki
* Student Id: 011672355
* Class: Cpts 122, Fall 2021;
* Programming Assignment #2: Digital Music Manager & Doubly Linked Lists - Part 3
* Date: 9/15/2021
* Description: Create a music manager using doubly linked lists with functions such as:
* load, store, display, insert, delete, edit sort, rate, play, shuffle, exit
**************************************/

int main(void)
{
	FILE* 
		infile = NULL, 
		* outfile = NULL;

	int 
		select = 0, 
		select1 = 0, 
		found = 0, 
		flag2 = 0, 
		index = 0, 
		flag1 = 0, 
		play = 0, 
		flag3 = 0;

	Node* 
		pList = NULL, 
		MultiAlbum[10] = { NULL };
	
	char
		Tsong[50] = " ", 
		Tartist[50] = " ";

	printf("\n\t...Welcome to Music Manager...");
	printf("\n\t    by, Mark Shinozkai\n");
	printf("\n");
	system("\npause");
	system("cls");
	do
	{
		do
		{
			select = Menu();
			system("cls");
			while (getchar() != '\n');

		} while ((select > 11) || (select < 1));

		system("cls");
		switch (select)
		{
		case 1:// load
			printf("\t__________________________\n");
			puts("\n\t     Loading Playlist...");
			printf("\t__________________________\n");



			if (pList == NULL)
			{
				infile = fopen("musicPlayList.csv", "r");
				flag1 = Load(infile, &pList);
				if (flag1 == 1)
				{
					printf("\t________________________________\n");
					puts("\n\t Playlist has Successfully Loaded...");
					printf("\t________________________________\n");

					puts("\n");
					fclose(infile);
				}
				else
				{
					puts("\n\t...Failure Loading... ");
				}
			}
			else
			{
				puts("\n\t...It has already been loaded...\n");
			}
			system("pause");
			system("cls");
			break;

		case 2:	// store
			printf("\t__________________________\n");
			puts("\n\t     Storing Playlist...");
			printf("\t__________________________\n");

			outfile = fopen("musicPlayList.csv", "w");
			Store(outfile, &pList);
			fclose(outfile);
			printf("\t__________________________\n");
			puts("\n\t Playlist Stored Successfully ...");
			printf("\t__________________________\n");
			printf("\n");
			system("pause");
			system("cls");
			break;

		case 3:	// display
			printf("\t__________________________\n");
			puts("\n\t     Display Playlist");
			printf("\t__________________________\n");

			do {
				printf("\n\t<1> Print all records\n\t<2> Print all records that match an artist\n\n");
				printf("Enter # from menu : ");
				scanf("%d", &select1);
				while (getchar() != '\n'); 

				if (select1 == 1)
				{
					DisplayL(pList);
					system("pause");
				}
				else if (select1 == 2)
				{
					do
					{
						system("cls");
						DisplaySong(pList);
						puts("^All Records shown above^ ");
						printf("\n\tEnter artist Name: ");
						gets(Tartist);
						index = ArtistSearch(&pList, Tartist, MultiAlbum);
						if (index == 0)
						{
							puts("\t\"Cannot find any artist\"");
						}

						for (int i = 1; i < index; ++i)
						{
							printf("\n\n[%d] ", i);
							DisplayR(&MultiAlbum[i]);
						}
						system("pause");

					} while (index == 0);

				}
			} while ((select1 != 1) && (select1 != 2));
			system("cls");
			break;

		case 4:	// insert
			printf("\t_____________________________\n");
			puts("\n\t Insert Record into Playlist");
			printf("\t_____________________________\n");
		
			Insert(&pList);
			system("cls");
			break;



		case 5:	// delete
			printf("\t__________________________\n");
			puts("\n\t Delete Record in Playlist");
			printf("\t__________________________\n");
			
			if (pList != NULL)
			{
				DisplaySong(pList);
				printf("\n Enter the Title of the song you want to Delete: ");
				scanf("%[^\n]", Tsong);

				printf("\t____________________________________\n");
				printf("\n\t The Record, (%s) has been Deleted\n", Tsong);
				printf("\t____________________________________\n");
				found = Delete(&pList, Tsong);
				
				if (found == 0)
				{
					puts("\t\"Can not find any song\"");
				}
				
				printf("\n");
				printf("\t__________________________\n");
				puts("\n\t A CHANGE HAS BEEN MADE");
				puts("\n\t Update Playlist Storing Playlist");
				printf("\t__________________________\n");
				printf("\n");
			}

			found = 0;
			if (pList == NULL)
			{
				puts("\n There is no List\n");
			}
			system("pause");
			system("cls");
			break;

		case 6:	// edit
			printf("\t__________________________\n");
			puts("\n\t     Edit Record Playlist");
			printf("\t__________________________\n");

			do
			{
				DisplaySong(pList);
				printf("\nEnter Artist Name that you'd like to edit: ");
				gets(Tartist);
				flag2 = Edit(&pList, Tartist);

			} while (flag2 == 0);
			system("cls");
			break;
		case 7:	// sort
			
			printf("\t__________________________\n");
			puts("\n\t     Sort Playlist");
			printf("\t__________________________\n");
			
			
			do {
				printf("\n\t1) Sort based on artist(A-Z)\n\t2) sort based on album title(A-Z)\n\t3) Sort based on rating(1-5)\n\t4) Sort based on times played(largest-smallest)\n\n");
				printf("select sorting option : ");
				scanf("%d", &flag3);
				if (flag3 == 1)//  Sort based on artist (A-Z)
				{
					SortByArtist(&pList);
				}
				else if (flag3 == 2)//Sort based on album title (A-Z)
				{
					SortByAlbum(&pList);
				}
				else if (flag3 == 3)//  Sort based on rating (1-5)
				{
					SortByRating(&pList);
				}
				else if (flag3 == 4)// Sort based on times played (largest-smallest)
				{
					SortByPlayback(&pList);
				}
			} while ((flag3 > 4) || (flag3 < 1));

			system("pause");
			system("cls");
			break;
		case 8:	// rate
			printf("\t__________________________\n");
			puts("\n\t  Rate Records in Playlist");
			printf("\t__________________________\n");
			printf("\n");
			
			
			Rate(&pList);
			system("cls");

			break;
		case 9:	// play
			printf("\t__________________________\n");
			puts("\n\t     Play Playlist");
			printf("\t__________________________\n");
			do {
				printf("\n\t1) Play in Order\n\t2) Play from Song you select\n\n");
				printf("select menu : ");
				scanf("%d", &play);
				while (getchar() != '\n'); 
				if (play == 1)
				{
					Order(&pList);
				}
				if (play == 2)
				{
					DisplaySong(pList);
					Selection(&pList);
				}
			} while ((play != 1) && (play != 2));

			break;
		case 10:	// shuffle
			printf("\t__________________________\n");
			puts("\n\t     Shuffle Playlist");
			printf("\t__________________________\n");
			
			printf("\t__________________________\n");
			puts("\n\t     Playing Music...");
			printf("\t__________________________\n");
			printf("\n");
			
			system("pause");

			Shuffle(&pList);
			system("pause");
			system("cls");
			break;
		
		case 11:	// exit
			printf("\t__________________________\n");
			puts("\n\t   EXITING MUSIC MANAGER ");
			puts("\n\t         Thank you ");
			puts("\n\t   Programmer: Mark Shinozaki");
			printf("\t__________________________\n");

			outfile = fopen("musicPlayList.csv", "w");
			Store(outfile, &pList);
			fclose(outfile);
			break;
		}

	} while (select != 11);
	return 0;
}
