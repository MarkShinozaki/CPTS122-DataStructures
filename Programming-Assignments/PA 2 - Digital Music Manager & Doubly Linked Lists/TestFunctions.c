#include "TestHeader.h"

//void TestMakeRecord (void)
//{
//	Record *pMem = NULL;
//
//	struct record nRecord;
//
//	strcpy(nRecord.Artist, "Katy Perry");
//	strcpy(nRecord.Album_title, "Prism");
//	strcpy(nRecord.Song_title, "Birthday");
//	strcpy(nRecord.Genre, "Disco");
//	nRecord.Length.Minutes = 3;
//	nRecord.Length.Seconds = 35;
//	nRecord.PlayBack = 42;
//	nRecord.Rating = 5;
//
//	//pMem = MakeNode (nRecord);
//
//	if (pMem != NULL)
//	{
//		printf ("Data was successfully allocated!\n");
//	}
//	else
//	{
//		printf ("Data was not successfully allocated!\n");
//	}
//
//	DisplayRecord (pMem);
//}
//
//void TestLoadRecord(void)
//{
//	FILE* File = NULL;
//	Record* pList = NULL;
//
//	File = fopen("Test.csv", "r");
//
//	if (File == NULL)
//	{
//		printf("File cannot be opened!\n");
//	}
//	else
//	{
//		Load(&pList, File);
//		DisplayR(pList);
//	}
//}
//
//void TestStoreRecord (void)
//{
//	FILE *File = NULL;
//	Record *pList = NULL;
//
//	File = fopen ("MySong.txt", "w+");
//
//	Store(&pList, File);
//	DisplayR(pList);
//}
//
//void TestInsertRecord (void)
//{
//	struct record nRecord;
//
//	Record *Temp = NULL;
//	Record *pList = NULL;
//
//	Insert (&Temp);
//
//	DisplayR(pList);
//}
