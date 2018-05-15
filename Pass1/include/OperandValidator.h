#ifndef PASS1_OPERANDVALIDATOR_H
#define PASS1_OPERANDVALIDATOR_H
#include <string>
using namespace std;

class OperandValidator {

public :
    static const int TYPE_IMMEDITAE_WORD = 0; //A
    static const int TYPE_IMMEDITAE_SYMBOL = 1; //R
    static const int TYPE_INDIRECT_WORD = 2;   //A
    static const int TYPE_INDIRECT_SYMBOL = 3; //R
    static const int TYPE_SYMBOL_OPERAND = 4;  //R for all except equ
    static const int TYPE_HEXA_LITERAL = 5;  //u
    static const int TYPE_WORD_LITERAL = 6;  //u
    static const int TYPE_BYTE_LITERAL = 7;  //u
    static const int TYPE_HEXA_OPERAND = 8;  //R
    static const int TYPE_BYTE_OPERAND = 9; //R
    static const int TYPE_INDEXED_SYMBOL = 10; //R
    static const int TYPE_WORD_OPERAND = 11; //A for all except word itself
    static const int TYPE_REGISTER_TO_REGISTER = 12; //u
    static const int TYPE_LOCCTR = 13;//R idk el sra7a
    static const int TYPE_SIMPLE_EXPRESSION = 14;//depending
    static const int TYPE_COMPLEX_EXPRESSION = 15;

    int getOperandType(string);
    bool isCompatible(int, string, string);
    bool isRelative(int);
    bool isAbsolute(int);

private :
    const string REGEX_SYMBOL_OPERAND = "^([a-zA-Z])+([a-zA-Z0-9\\$])*";
    const string REGEX_IMMEDITAE_WORD = "^#(\\d)+$" ;
    const string REGEX_IMMEDITAE_SYMBOL = "^#([a-zA-Z])+([a-zA-Z0-9\\$])*";
    const string REGEX_INDIRECT_WORD = "^@(\\d)+$" ;
    const string REGEX_INDIRECT_SYMBOL = "^@([a-zA-Z])+([a-zA-Z0-9\\$])*" ;
    const string REGEX_HEXA_LITERAL = "^=(X|x)\'([a-fA-F0-9])+\'$";
    const string REGEX_WORD_LITERAL = "^=(W|w)\'(-)?(\\d)+\'$";
    const string REGEX_BYTE_LITERAL = "^=(C|c)\'([a-zA-Z0-9])+\'$";
    const string REGEX_HEXA_OPERAND = "^(X|x)\'([a-fA-F0-9])+\'$";///for resb and byte
    const string REGEX_BYTE_OPERAND = "^(C|c)\'([a-zA-Z0-9])+\'$";
    const string REGEX_INDEXED_SYMBOL = REGEX_SYMBOL_OPERAND + ",(X|x)$";
    const string REGEX_WORD_OPERAND = "^(-?)(\\d)+";
    const string REGEX_REGISTER_TO_REGISTER = "^(A|X|L|B|S|T|F),(A|X|L|B|S|T|F)$";
    const string REGEX_SIMPLE_EXPRESSION1 = REGEX_SYMBOL_OPERAND + "(\\+|-)(\\d)+";
    const string REGEX_SIMPLE_EXPRESSION2 = "^(\\d)+(\\+|-)([a-zA-Z])+([a-zA-Z0-9\\$])*)";
    const string REGEX_COMPLEX_EXPRESSION = "(([a-zA-Z])+([a-zA-Z0-9\\$])*)(\\+|-)(([a-zA-Z])+([a-zA-Z0-9\\$])*)";


    bool isNumberPositive(string);
    bool isRegister(string);
};


#endif //PASS1_OPERANDVALIDATOR_H
