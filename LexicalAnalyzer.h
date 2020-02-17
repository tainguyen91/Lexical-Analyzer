/* 
Tai Nguyen
CPSC 323
Project 1
LexicalAnalyzer.h
*/

#ifndef LexicalAnalyzer_h
#define LexicalAnalyzer_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class LexicalAnalyzer
{
private:
    string *keywords;
    string *separators;
    string *operators;
    string *token;
    string *tokenType;
    string temp;
    char lastToken;
    int lexSTATE, cSTATE, index; 
    int lexReturnCount;
    
public:
    
    LexicalAnalyzer()
    {
        cSTATE = 0;
        lexSTATE = 0;
        index = 0;
        token = new string[100000];
        tokenType = new string[100000];
        keywords = new string[20]  {"int", "float", "bool", "true", "false", "if", "else", "then", "endif",
            "while", "whileend", "do", "doend", "for", "forend", "input", "output", "and", "or", "not"};
        separators = new string[11] {"'", "(", ")", "{", "}", "[", "]", ".", ":", ";", "sp"};
        operators = new string[8] {"*", "+", "-", "=", "/", ">", "<", "%"};
        lexReturnCount = 0;
    }
    
    ~LexicalAnalyzer()
    {
        delete []token;
        delete []tokenType;
        delete []separators;
        delete []operators;
        
    }
    
    
    int getNumTokens()
    {
        return index;
    }
    
    string *getTokens()
    {
        return token;
    }
    string *getTokenType()
    {
        return tokenType;
    }
    
    
    void updateCurrentState(char s)
    {
        
    }
    

    void LexicalRecord(string filename)
    {
        fstream file(filename);
        
        if (file.is_open())
        {
            cout << "Successfully opened file " << filename << endl;
            string line;
            
            char s;
            
            while (getline(file,line))
            {
                line += ' ';
                
                for(int i = 0; i < line.length(); i++)
                {
                    
                    s = line[i];
                    updateCurrentState(s);
                }
                
                
            }
            file.close();
            
            ofstream file;
            file.open ("output.txt");
            file << "TOKENS" << "\t\t\t\t" << "Lexemes" << endl;
            for(int i = 0; i < index; i++)
            {
                file << tokenType[i] << "\t = \t" <<  token[i] << endl;;
            }
            file.close();
        }
        else    {
            cout << ("Could not open the file " + filename);
        }
    }
};
#endif 