#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "rate.h"

using namespace std;

//--------------------------------------------------------------
Rate::Rate(){
  name = "";
  total_time = 0.0;
  count = 0;
}
//--------------------------------------------------------------

//--------------------------------------------------------------
void Rate::set_name(string name){
  this->name = name;
}
//--------------------------------------------------------------

//--------------------------------------------------------------------------------
void Rate::set_time( string current_time){
  string type;
  type = current_time.substr(current_time.length() - 2, 2);
  
  double current_time_d;
  current_time = current_time.substr(0, current_time.length() - 2);
  current_time_d = atof(current_time.c_str());  // Convert current_time to double
 
  if (type.compare("ns") == 0 ) current_time_d = current_time_d/1000000000;
  else if (type.compare("us") == 0 ) current_time_d = current_time_d/1000000;
  else if (type.compare("ms") == 0 ) current_time_d = current_time_d/1000;

  /* Set values to class variables */
  this->total_time += current_time_d;
  this->count += 32;
}
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
void Rate::print(ofstream& outFile){

  double rate;
  rate = count/total_time;
  if (rate > TERABITS){
    rate = rate/TERABITS;
    outFile<<name<<": "<<fixed<<setprecision(2)<<rate<<" Terabits/sec"<<endl;
  }
  else if (rate > GIGABITS) {
    rate = rate/GIGABITS;
    outFile<<name<<": "<<fixed<<setprecision(2)<<rate<<" Gigabits/sec"<<endl;
  }
  else if ( rate > MEGABITS) {
    rate = rate/MEGABITS;
    outFile<<name<<": "<<fixed<<setprecision(2)<<rate<<" Megabits/sec"<<endl;
  }
  else if ( rate > KILOBITS) {
    rate = rate/KILOBITS;
    outFile<<name<<": "<<fixed<<setprecision(2)<<rate<<" Kilobits/sec"<<endl;
  }

}
//-----------------------------------------------------------------------------------
