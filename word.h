// Header file for word module

//Include guards
#ifndef __WORD_H
#define __WORD_H

using namespace std;

class Word {
    int line_num;
    int word_index;
    string field_name;
    string description;
    int bit;
public:
    Word();
    void set_values(int line_num, int word_num, string address);
    string get_field_name();
    void print();
};

#endif