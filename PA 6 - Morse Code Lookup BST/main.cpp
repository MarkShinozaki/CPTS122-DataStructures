/******************************************************************************
* Programmer: Mark Shinozaki													  *
* Class: CptS 122;                                            *
* Programming Assignment: PA6 Morse Code Loopk Up BST                         *                                                           *
*                                                                             *
* Description: This program design, implement, and test a Binary Search Tree. *
*              Apply a BST for looking up Morse Code                          *
******************************************************************************/

#include "MorseConverter.h"

int main() {
    MorseConverter converter;
    converter.createMorseBST("MorseTable.txt");
    converter.convertTextToMorse("Convert.txt");
    return 0;
}

