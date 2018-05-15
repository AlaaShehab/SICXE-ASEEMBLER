#include "SymbolTable.h"
#include <iostream>
#include <map>
#include <algorithm>
#include<vector>
#include "Converters.h"
#include "inOutFile.h"
using namespace std;

    SymbolTable::SymbolTable(){

    }

    void SymbolTable::addSymbol(string* symbolName, int symbolAddress, bool symbolType) {
        toUpper(symbolName);
        symbol_info symbolInfo;
        symbolInfo.address = symbolAddress;
        symbolInfo.type = symbolType;
        int symbolLen = symbolLength(*symbolName);
        symbolInfo.length = symbolLen;
        symbol_table[*symbolName] = symbolInfo;
    }

    int SymbolTable::symbolLength(string symbolName) {
        return symbolName.length();
    }

    bool SymbolTable::containSymbol(string* symbolName) {
         toUpper(symbolName);
         return (symbol_table.find(*symbolName) != symbol_table.end());
    }

    int SymbolTable::getSymbolAddress(string* symbolName) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(*symbolName);
        if (symbol_table_iterator != symbol_table.end()) {
            return symbol_table_iterator->second.address;
        }
        return -1;
    }
    int SymbolTable::getSymbolLength(string* symbolName) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(*symbolName);
        if (symbol_table_iterator != symbol_table.end()) {
           return symbol_table_iterator->second.length;
        }
        return -1;
    }
    bool SymbolTable::getSymbolType(string* symbolName) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(*symbolName);
        return symbol_table_iterator->second.type;
    }

    void SymbolTable::modifySymbol(string* symbolName, int symbolAddress, bool symbolType) {
        toUpper(symbolName);
        symbol_table_iterator = symbol_table.find(*symbolName);
        if (symbol_table_iterator != symbol_table.end()) {
            symbol_table_iterator->second.address = symbolAddress;
            symbol_table_iterator->second.type = symbolType;
        }
    }
    void SymbolTable::toUpper(string* symbolName) {
        transform(symbolName->begin(), symbolName->end(), symbolName->begin(), ::toupper);
    }

    void SymbolTable::printSymbolTable() {
        Converters convert;
        std::multimap<int, std::string> temp;
        std::vector<std::string> symbolAddressVec;
        std::vector<std::string> symbolLabelVec;

        for(auto elem : symbol_table) {
            temp.insert(std::pair<int, std::string>(elem.second.address, elem.first));
        }


        for(auto elem : temp) {
            symbolLabelVec.push_back(elem.second);
            string hexAddress = convert.convertToHexa(elem.first);
            symbolAddressVec.push_back(hexAddress);
        }

        file = inOutFile();
        file.writeSymbolFile(symbolLabelVec, symbolAddressVec, "SymbolTable.txt");
    }
