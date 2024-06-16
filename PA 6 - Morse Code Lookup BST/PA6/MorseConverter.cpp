#include "MorseConverter.h"
#include <iostream>
#include <fstream>
#include <sstream>

void MorseConverter::createMorseBST(const std::string& morseTableFilename) {
    std::ifstream file(morseTableFilename);
    if (!file) {
        std::cerr << "Error opening Morse table file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char ch;
        std::string morse;
        iss >> ch >> morse;
        morseBST.insert(ch, morse);
    }
}

void MorseConverter::convertTextToMorse(const std::string& inputFilename) {
    std::ifstream file(inputFilename);
    if (!file) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string morseLine;
        for (char ch : line) {
            if (ch != ' ') {
                std::string morseCode = morseBST.search(toupper(ch));
                if (!morseCode.empty()) {
                    morseLine += morseCode + ' ';
                }
                else {
                    morseLine += "[UNKNOWN] ";
                }
            }
            else {
                morseLine += "  ";
            }
        }
        displayConversion(line, morseLine);
    }
}

void MorseConverter::displayConversion(const std::string& text, const std::string& morse) {
    std::cout << "Original Text: " << text << std::endl;
    std::cout << "Morse Code: " << morse << std::endl;
    std::cout << std::endl;
}
