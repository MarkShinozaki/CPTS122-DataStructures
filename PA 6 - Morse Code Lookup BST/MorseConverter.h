#ifndef MORSECONVERTER_H
#define MORSECONVERTER_H

#include "BST.h"
#include <string>

class MorseConverter {
private:
    BST morseBST;

public:
    void createMorseBST(const std::string& morseTableFilename);
    void convertTextToMorse(const std::string& inputFilename);
    void displayConversion(const std::string& text, const std::string& morse);
};

#endif // MORSECONVERTER_H
