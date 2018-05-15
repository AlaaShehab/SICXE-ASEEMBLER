#include <iostream>
#include <InstructionLine.h>
#include <Controller.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;



int main() {

    string fileName;
    cin>>fileName;
    Controller controller;
    controller.start(fileName);




    return 0;
}
