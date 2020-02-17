/* 
Tai Nguyen
CPSC 323
Project 1
main.cpp
*/

#include <iostream>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;

int main() {
    string fileName = "input.txt";
    LexicalAnalyzer LA;
    LA.LexicalRecord(fileName);
    return 0;
}