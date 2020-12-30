#include <iostream>
#include <sstream>
#include <string>
#include "sequence.h"

using namespace std;

inline bool is_integer(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

// Returns false when sequence complete
bool try_sequence(Sequence &seq, ostringstream &os) {
    cout << "Enter new sparked switches in enter-separated list; e to enter, z to undo, -1 to exit: " << endl;
    cout << "Next sequence to try:" << endl;
    seq.print(os);
    cout << os.str();

    string val;
    string last_val;
    vector<int> sparked;
    while(cin >> val) {
        if(is_integer(val)) {
            int num = stoi(val);
            if(num == -1) {
                return false;
            } else {
                sparked.push_back(num);
            }
        } else if(val == "e") {
            break;
        } else if(val == "z") {
            if(sparked.size() >= 1) {
                sparked.pop_back();
                cout << "Undid last spark" << endl;
            } else {
                cout << "Nothing to undo" << endl;
            }
        } else {
            cout << "Invalid input" << endl;
        }
    }

    seq.fix_values(sparked);
    if(seq.is_complete()) { return false; }
    else { 
        os.str("");
        os.clear();  
        seq.next_sequence();
        return true; 
    }
}

bool solve() {
    Sequence seq;
    ostringstream os;

    while(try_sequence(seq, os)) {}
    cout << "Sequence complete! Solution:" << endl;
    cout << os.str();
    cout << endl;

    cout << "it's gamer time baby" << endl;
    cout << "enter \'enter\' to solve a sequence or \'unenter\' to stop" << endl;
    string val;
    cin >> val;
    if(val == "enter") {
        return true;
    } else {
        return false;
    }
}