#include <iostream>
#include <string>
#include <fstream>
#include "rate.h"
#include "time.h"

using namespace std;

Time::Time(){
  S_D_Rd = false;
  S_D_Wr = false;
  D_S_Rd = false;
  D_S_Wr = false;
  rate[0].set_name("Read S-to-D command");
  rate[1].set_name("Write S-to-D command");
  rate[2].set_name("Read D-to-S command");
  rate[3].set_name("Write D-to-S command");
}

Rate* Time::check_flag(){
  if ( S_D_Rd ) return &rate[0];
  else if ( S_D_Wr ) return &rate[1];
  else if ( D_S_Rd ) return &rate[2];
  else if ( D_S_Wr ) return &rate[3];
  else return NULL;
}

void Time::set_flag(string flag){
  if (flag.compare("S_D_Rd") == 0 ) S_D_Rd = true;
  else if (flag.compare("S_D_Wr") == 0) S_D_Wr = true;
  else if (flag.compare("D_S_Wr") == 0) D_S_Wr = true;
  else if (flag.compare("D_S_Rd") == 0) D_S_Rd = true;
  else {
    S_D_Rd = S_D_Wr = D_S_Wr = D_S_Rd = false;
  }
}

void Time::print(ofstream& outFile) {
  for ( int i = 0; i < 4; i++ ) rate[i].print(outFile);
}
