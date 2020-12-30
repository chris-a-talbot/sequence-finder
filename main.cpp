#include <iostream>
#include "run.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "it's gamer time baby" << endl;
    cout << "enter \'enter\' to solve a sequence or \'unenter\' to stop" << endl;
    string val;
    cin >> val;
    if(val == "enter") {
        while(solve()) {}
        return 0;
    } else {
        return 0;
    }
}