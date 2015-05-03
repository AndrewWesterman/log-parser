// Header file for word module

// Include guards
#ifndef __WORD_H
#define __WORD_H

using namespace std;

class Word {
    int line_num;
    int word_num;
    string field_name;
    string description;
    int data_value;

 public:
    // Constructor
    Word();

    // Applies the given values to Word object variables
    void set_values(int line_num, int word_num, string data);

    // Returns the field name of the word i.e "Rec_Ctrl"
    string get_field_name();

    // Prints the word object to std out
    void print();
};

#endif