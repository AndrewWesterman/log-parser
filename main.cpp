
/* 254 Project 
   Duy Do
*/

#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
#include "convert.h"
#include "parse.h"
#include "command.h"
#include "word.h"
#include "convert.h"

using namespace std;
 

int main(int argc, char** argv)
{
  /* Sanity check */
  if ( argc != 2 ) {
    cerr << "Usage: "<<argv[0]<<" <input file> "<<endl;
    exit(1);
  }
  const string command_S_to_D = "40000810";
  const string command_D_to_S = "40000C18";
  string data1 = "40000818";
  string data2 = "40000C14";
  string data3 = "40000C20";
  string data4 = "4000101C";

  
  int line_num = 0;
  int num_words;
  string line;
  string data;
  int index;
  int index_reverse;
  bool order = false;

  /* Open the file to read */
  ifstream inFile;
  inFile.open(argv[1]);
  if ( ! inFile.is_open()) {
    cerr << "Cannot open the input file."<<endl;
    exit(2);
  }

  /* Create two objects of class Data_Info to get useful data from input file */
  Data_Info Command_Info;
  Data_Info Word_Info;

  /* Allocate an object of class Command to save information about a command */
  Command* command = new Command;


  
  /* Read input file line by line from the beginning to end 
     Each line is copied into the string line */

  while( getline(inFile, line)){
    ++line_num;     /* increase line number by one each time a new line is read */

    /* Call function parse_line to parse data of the line. Now useful data is in Command_Info */
    Command_Info.parse_line(line);
    
    /* Check if it's is S to D command by comparing the address with command_S_to_D which is "40000810" */
    if ( Command_Info.get_address().compare(command_S_to_D) == 0 ) {
      
      /* Using the information in Command_Info to set values to object command */
      command->set_values(line_num, "S-to-D", Command_Info.get_kind(), Command_Info.get_data());

      /* Print information of the command by calling function print() */
      command->print();
      num_words = command->get_num_of_words();   /* Get the number of words of the command */
     }
   

    /* Check if it's D to S command */
    else if ( Command_Info.get_address().compare(command_D_to_S) == 0 ) {
      command->set_values(line_num, "D-to-S", Command_Info.get_kind(), Command_Info.get_data());
      
      command->print();
    }
  }

  inFile.close();
  	
  delete command;
  return 0;

}

