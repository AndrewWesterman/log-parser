#include <iostream>
#include <string>
#include <assert.h>
#include "convert.h"
#include "word.h"

using namespace std;

Word::Word() {
    line_num = 0;
    word_index = 0;
    field_name = "";
    description = "";
    data_value = -1;
}

void Word::set_values(int line_num, int word_num, string data) {
    int data_value;
    string field_name = "";
    string description = "";

    switch (word_num) {
    case 0:
        field_name = "Rec_Ctrl";
        data_value = bit_shift(data, 14, 13);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "no recording";
        else if (data_value == 2)
            description = "no processing";
        else if (data_value == 3)
            description = "processing & recording";
        else
            description = "unknown";
        break;
    case 1:
        field_name = "Cmd_Type";
        data_value = bit_shift(data, 15, 13);
        assert(data_value >= 0);
        if (data_value == 4)
            description = "Type A";
        else if (data_value == 5)
            description = "Type B";
        else if (data_value == 6)
            description = "Type C";
        else
            description = "unknown";
        break;
    case 4:
        field_name = "Rec_Raw";
        data_value = bit_shift(data, 0, 0);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "disable";
        else if (data_value == 1)
            description = "enable";
        else
            description = "unknown";
        break;
    case 5:
        field_name = "Cmd_ID";
        data_value = bit_shift(data, 6, 0);
        assert(data_value >= 0);
        description = "no recording";
        break;
    case 10:
        field_name = "Num_Responses";
        data_value = bit_shift(data, 15, 11);
        assert(data_value >= 0);
        description = "";
        break;
    case 15:
        field_name = "Reset_Enable";
        data_value = bit_shift(data, 2, 2);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "disable";
        else if (data_value == 1)
            description = "enable";
        else
            description = "unknown";
        break;
    case 22:
        field_name = "Direction";
        data_value = bit_shift(data, 3, 3);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "Right";
        else if (data_value == 1)
            description = "Left";
        else
            description = "unknown";
        break;
    case 32:
        field_name = "Num_Samples";
        data_value = bit_shift(data, 14, 0);
        assert(data_value >= 0);
        description = "";
        break;
    case 37:
        field_name = "Parity";
        data_value = bit_shift(data, 15, 15);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "even";
        else if (data_value == 1)
            description = "odd";
        else
            description = "unknown";
        break;
    case 39:
        field_name = "Test";
        data_value = bit_shift(data, 14, 14);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "disable";
        else if (data_value == 1)
            description = "enable";
        else
            description = "unknown";
        break;
    case 40:
        field_name = "Ctrl_Enable";
        data_value = bit_shift(data, 7, 7);
        assert(data_value >= 0);
        if (data_value == 0)
            description = "disable";
        else if (data_value == 1)
            description = "enable";
        else
            description = "unknown";
        break;
    case 41:
        field_name = "Code";
        data_value = bit_shift(data, 14, 8);
        assert(data_value >= 0);
        description = "";
        break;
    }

    // Set the values for the current Word
    this->line_num = line_num;
    this->word_num = word_num;
    this->field_name = field_name;
    this->data_value = data_value;
    this->description = "("+description+")";
}

string Word::get_field_name() {
    return field_name;
}

void Word::print() {
    cout << "Line " << line_num << ": Word " << word_num << ": " << field_name << "= " << data_value << " "+description << endl;
}
