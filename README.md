# Lexical-Analyzer
The Lexer

A major component of your assignment will be to write a procedure (Function) –lexer (),  that returns atoken when it is needed.  Your lexer()  should return a record, one field for the token and another field the actual "value" of the token (lexeme), i.e. the instance of a token. 

Your main program should test the lexer i.e., your program should read a file containingthe source code given from classto generate tokens and write out the results to an output file.Make sure that you print both, the tokens and lexemes.  Basically, your main program should work as follows:

while not finished (i.e. not end of the source file)
do call the lexer for a token           
print the token and lexeme    
endwhile 
