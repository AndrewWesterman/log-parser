#include <iostream>
#include <string>
#include <sstream>
#include "command.h"

using namespace std;

//set default values
Command::Command()
{
    line_num = 0;
    name = "";
    type = "";
    num_words = 0;
}

//get number of words
int Command::get_num_of_words () const
{
    return num_words;
}

//set the values
void Command::set_values(int line_num, string name, string kind, string num)
{
    //retrieve line number
    this->line_num = line_num;
    //retrieve name
    this->name = name;

    //determine if type = write or read
    if ( kind.compare("Wr") == 0 )
        this->type = "Write";
    else
        this->type = "Read";

    stringstream hexa;
    int num_words;
    //clears hexa for reusage
    hexa.clear();
    hexa.str(string());
    //convert num from string to hex
    hexa << hex << num;
    //read num_words from hexa
    hexa >> num_words;
    //retrieve num_words divided by 2
    this->num_words = num_words / 2;
}
//output line#/type/name/#words
void Command::print() const
{
    cout << "Line " << line_num << ": " << type << " " << name
         << " command: " << num_words << " words" << endl;
}

