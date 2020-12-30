#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <iostream>

class Switch {
    public:
        Switch(int i);
        Switch(int i, bool val);
        void set_fixed(bool val);
        void set_location(int loctn);
        bool get_fixed();
        int get_location();
    private:
        int loc;
        bool is_fixed;
};

class Sequence {
    public:
        static const int SEQUENCE_LENGTH = 10;

        Sequence();

        void print(std::ostream &os);
        void fix_values(std::vector<int> vals);
        void set_value(Switch s, int ind);
        Switch get_switch(int i);
        void next_sequence();
        bool is_complete();
        void exit();

    private:
        std::vector<Switch> switches;
};

#endif /* SEQUENCE_H */