#include "sequence.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>

using namespace std;

Switch::Switch(int i) : loc(i), is_fixed(false) {}

Switch::Switch(int i, bool val) : loc(i), is_fixed(val) {}

void Switch::set_fixed(bool val) { is_fixed = val; }

void Switch::set_location(int loctn) { loc = loctn; }

bool Switch::get_fixed() { return is_fixed; }

int Switch::get_location() { return loc; }

Sequence::Sequence() {
    for(int i = 0; i < 10; ++i) {
        Switch s((i+1));
        switches.push_back(s);
    }
}

void Sequence::print(ostream &os) {
    for(int i = 0; i < 10; ++i) {
        os << switches[i].get_location();
        if(switches[i].get_fixed()) {
            os << "*";
        }
        os << " ";
    }
    os << endl;
}

void Sequence::fix_values(vector<int> vals) {
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < (int) vals.size(); ++j) {
            if(switches[i].get_location() == vals[j]) {
                // Maybe not rly fixing?
                switches[i].set_fixed(true);
                break;
            }
        }        
    }
}

void Sequence::set_value(Switch s, int ind) {
    switches[ind] = s;
}

bool Sequence::is_complete() {
    int correct_val = 0;
    for(int i = 0; i < 10; ++i) {
        if(switches[i].get_fixed()) {
            ++correct_val;
        }
    }
    if(correct_val >= 9) {
        return true;
    }
    return false;
}

Switch Sequence::get_switch(int i) {
    return switches[i];
}

void Sequence::next_sequence() {
    Sequence next;

    for(int i = 0; i < 10; ++i) {
        Switch s = switches[i];
        Switch n(0);
        if(s.get_fixed()) {
            n = s;
        } else {
            for(int j = i; j < i+10; ++j) {
                int cur = j % 10;
                Switch c = switches[cur];
                if(!c.get_fixed()) {
                    n.set_location(c.get_location());
                    n.set_fixed(false);
                }
            }
        }
        next.set_value(n, i);
    }

    for(int i = 0; i < 10; ++i) {
        Switch s = next.get_switch(i);
        switches[i].set_location(s.get_location());
        switches[i].set_fixed(s.get_fixed());
    }
}

void Sequence::exit() {

}