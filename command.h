#ifndef __COMMAND_H
#define __COMMAND_H

using namespace std;

class Command 
{
  int line_num;
  string name;
  string type;
  int num_words;

public:
  Command();
  void set_values(int line_num, string name, string type, string num) ;
  int get_num_of_words() const;
  void print() const;
};

#endif
