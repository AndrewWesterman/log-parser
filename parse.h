#ifndef __PARSE_H
#define __PARSE_H

using namespace std;

class Data_Info {
    string address;
    string data;
    string size;
    string kind;
    string time;
 public:
    Data_Info();
    void parse_line(string a);
    string get_address();
    string get_data();
    string get_size();
    string get_kind();
    string get_time();
};

#endif

