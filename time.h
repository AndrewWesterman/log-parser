#ifndef __TIME_H
#define __TIME_H

using namespace std;

class Time {
  bool S_D_Rd;
  bool S_D_Wr;
  bool D_S_Rd;
  bool D_S_Wr;
  Rate rate[4];
public:
  Time();
  Rate* check_flag();
  void set_flag(string flag);
  void print(ofstream& outFile);
};

#endif
