// Class responsible for turning a string line from the log file into
// a useful object from which specific values can be accessed
#include <iostream>
#include <string>
#include <sstream>
#include "parse.h"

using namespace std;

//Empty values for parsed elements
Data_Info::Data_Info() {
    address = "";
    data = "";
    size = "";
    kind = "";
    time = "";
}

//Retrieve values from line
void Data_Info::parse_line(string a) {
    stringstream ss;
    string not_useful;
    string address;
    string data;
    string size;
    string kind;
    string time;
    ss.str(string());
    ss.clear();
    ss << a;

    // Skip the first  2 words
    for ( int i = 1; i < 3; i++ ) ss >> not_useful;

    // Get realtime
    ss >> time;

    // Skip the next 3 words
    for ( int i = 1; i < 4; i++ ) ss >> not_useful;

    // Get data info
    ss >> address >> data >> size >> kind;

    // Copy values to the class variables
    this->address = address;
    this->data = data;
    this->size = size;
    this->kind = kind;
    this->time = time;
}

//Get address
string Data_Info::get_address() {
    return address;
}

//Get data
string Data_Info::get_data() {
    return data;
}

//Get size
string Data_Info::get_size() {
    return size;
}

//Get kind
string Data_Info::get_kind() {
    return kind;
}

//Get time
string Data_Info::get_time() {
    return time;
}


