//
// Created by Carnival Stores on 4/27/2018.
//

#ifndef PASS1_INOUTFILE_H
#define PASS1_INOUTFILE_H

#include <vector>
#include <iostream>

using namespace std;


class inOutFile {
public:
    static vector<string> readFile(string);
    void static writeFile(vector<string>,vector<string>,vector<string>,vector<string>,
                          vector<string>,vector<int>, string);
    void static writeSymbolFile(vector<string>, vector<string>,string);
    void static writeLitralFile(vector<string>, vector<string>,
                                vector<int>, vector<string>,string);
};


#endif //PASS1_INOUTFILE_H
