#ifndef __RATE_H
#define __RATE_H


using namespace std;


const unsigned int  KILOBITS = 1000;
const unsigned int MEGABITS = 1000000;
const unsigned long GIGABITS = 1000000000;
const unsigned long long TERABITS = 1000000000000;

class Rate {
  string name;
  double total_time;
  long count;
public:
  Rate();
  void set_name(string name);
  void set_time(string current_time);
  void print(ofstream& outFile);
};

#endif
