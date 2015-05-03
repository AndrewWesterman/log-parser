
/* 254 Project 
   Duy Do
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include "convert.h"
#include "parse.h"
#include "command.h"
#include "word.h"
#include "convert.h"
#include "rate.h"
#include "time.h"

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
  string* data;
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
  
  ofstream outFile;
  outFile.open("test.txt");
  if ( ! outFile.is_open()) {
    cerr << "Cannot create an output file."<<endl;
    exit(2);
  }
  //outFile.close();
  //outFile.open("test.txt", ios::app);

  /* Create two objects of class Data_Info to get useful data from input file */
  Data_Info Command_Info;
  Data_Info Word_Info;

  /* Allocate an object of class Command to save information about a command */
  Command* command = new Command;

  /* Allocate an array of 42 words to save information of each word */
  Word * list_word;
  list_word = new Word[42];

  /* Create an object of class Time to handle the reltime for four different types of commands */
  Time RelTime;

  /* Create a pointer to hold the address of an object of class Rate to set the values for each types of commands */
  Rate* previous_command;
  
  /* Read input file line by line from the beginning to end 
     Each line is copied into the string line */

  while( getline(inFile, line)){
    ++line_num;     /* increase line number by one each time a new line is read */

    /* Call function parse_line to parse data of the line. Now useful data is in Command_Info */
    Command_Info.parse_line(line);

    /* Check the flag of the time to see if the previous line was a command. If it was, then the address of the object
       that holds the time for that type of command will be returned to object previous_command. If it was not, then it 
       will return NULL */

    previous_command = RelTime.check_flag();

    /* If the previous line was a command, then set the time using the data from Command_Info.get_time() */
    if ( previous_command ) {
      previous_command->set_time(*Command_Info.get_time());
      RelTime.set_flag("No");  /* Set all the flags to false */
    }

    
    
    /* Check if it's is S to D command by comparing the address with command_S_to_D which is "40000810" */
    if ( Command_Info.get_address()->compare(command_S_to_D) == 0 ) {
      
      /* Using the information in Command_Info to set values to object command */
      command->set_values(line_num, "S-to-D", *Command_Info.get_kind(), *Command_Info.get_data());

      /* Set the flag to indicate that this is a S to D command */
      if ( Command_Info.get_kind()->compare("Wr") == 0 ) RelTime.set_flag("S_D_Wr");
      else RelTime.set_flag("S_D_Rd");
							  
	   
      /* Print information of the command by calling function print() */
      command->print(outFile);
      num_words = command->get_num_of_words();   /* Get the number of words of the command */
      
      /* If the number of words of the command is not 0, then process next lines to get information of each word */
      if ( num_words != 0 ) {
	getline(inFile, line);        
	++line_num;
	Word_Info.parse_line(line);   /* Get useful info of the line into object Word_Info */

	/* Check the flag to set the time for this command */

	previous_command = RelTime.check_flag();
	previous_command->set_time(*Word_Info.get_time());

	/* Compare the address of this line to "40000818".
	   If they are the same, it means that the words start from word 0 to N */
	if ( Word_Info.get_address()->compare(data1) == 0 ) {
	  order = true;
	  index = 0;
	  data = Word_Info.get_data();    
	  
	  /* If the size of data is D32, it means the data contains two words 
	     Use information in Word_Info to set values for word 0 and 1 */
	  if (Word_Info.get_size()->compare("D32") == 0) {
	    list_word[index].set_values(line_num, index, data->substr(0, 4));
	    ++index;
	    list_word[index].set_values(line_num, index,  data->substr(4, 4));
	    ++index;
	  }
	  
	  /* Keep reading file input and use the information to set values for words 2 to N
	     Stop the loop when we get enough number of words for the command */
	  while(index < num_words){
	    getline(inFile, line);
	    ++line_num;
	    Word_Info.parse_line(line);

	    /* set the time */
	    previous_command->set_time(*Word_Info.get_time());

	    /* set values for words */
	    data = Word_Info.get_data();
	    if (Word_Info.get_size()->compare("D32") == 0) {
	      list_word[index].set_values(line_num, index, data->substr(0, 4));
	      ++index;
	      list_word[index].set_values(line_num, index, data->substr(4, 4));
	      ++index;
	    }
	  }
	}

	/* If the address is not "40000818", the words starts from N to 0 */
	else {
	  order = false;
	  index_reverse = num_words - 1;        /* This is the index of word N */
	  data = Word_Info.get_data();
	  if (Word_Info.get_size()->compare("D32") == 0) {
	    list_word[index_reverse].set_values(line_num, index_reverse, data->substr(4, 4));
	    --index_reverse;
	    list_word[index_reverse].set_values(line_num, index_reverse, data->substr(0, 4));
	    --index_reverse;
	  }
	  while(index_reverse >= 0){
	    getline(inFile, line);
	    ++line_num;
	    Word_Info.parse_line(line);

	    /* set the time */
	    previous_command->set_time(*Word_Info.get_time());

	    data = Word_Info.get_data();
	    if (Word_Info.get_size()->compare("D32") == 0) {
	      list_word[index_reverse].set_values(line_num, index_reverse, data->substr(4, 4));
	      --index_reverse;
	      list_word[index_reverse].set_values(line_num, index_reverse, data->substr(0, 4));
	      --index_reverse;
	    }
	  }
	}
	 
	/*Print words in the the ascending order */
	if ( order == true ) {
	  for ( int i = 0; i < num_words; i++) {
	    if (list_word[i].get_field_name().compare("") != 0) {
	      list_word[i].print(outFile);
	    }
	  }
	  outFile<<endl;
	}
	
	/*Print words in the the descending order */
	else {
	  for ( int i = num_words - 1; i >= 0; i--) {
	    if (list_word[i].get_field_name().compare("") != 0) {
	      list_word[i].print(outFile);
	    }
	  }
	  outFile<<endl;
	}
        
      } else outFile<<endl; 
       
    }
   

    /* Check if it's D to S command */
    else if ( Command_Info.get_address()->compare(command_D_to_S) == 0 ) {
      command->set_values(line_num, "D-to-S", *Command_Info.get_kind(), *Command_Info.get_data());
      
      command->print(outFile);

      /* Set the flag to indicate that this is a S to D command */
      if ( Command_Info.get_kind()->compare("Wr") == 0 ) RelTime.set_flag("D_S_Wr");
      else RelTime.set_flag("D_S_Rd");
      
      num_words = command->get_num_of_words();
      if ( num_words != 0 ) {
	getline(inFile, line);
	++line_num;
	Word_Info.parse_line(line);

	/* Check the flag to set the time for this command */
	previous_command = RelTime.check_flag();
	previous_command->set_time(*Word_Info.get_time());

	if ( Word_Info.get_address()->compare(data3) == 0 ) {
	  order = true;
	  index = 0;
	  data = Word_Info.get_data();
	  if (Word_Info.get_size()->compare("D32") == 0) {
	    list_word[index].set_values(line_num, index, data->substr(0, 4));
	    ++index;
	    list_word[index].set_values(line_num, index, data->substr(4, 4));
	    ++index;
	  }
	  
	  while(index < num_words){
	    getline(inFile, line);
	    ++line_num;
	    Word_Info.parse_line(line);

	    /* Set the time */
	    previous_command->set_time(*Word_Info.get_time());
	    
	    data = Word_Info.get_data();
	    if (Word_Info.get_size()->compare("D32") == 0) {
	      list_word[index].set_values(line_num, index, data->substr(0, 4));
	      ++index;
	      list_word[index].set_values(line_num, index, data->substr(4, 4));
	      ++index;
	    }
	  }
	}
	else {
	  order = false;
	  index_reverse = num_words - 1;
	  data = Word_Info.get_data();
	  if (Word_Info.get_size()->compare("D32") == 0) {
	    list_word[index_reverse].set_values(line_num, index_reverse, data->substr(4, 4));
	    --index_reverse;
	    list_word[index_reverse].set_values(line_num, index_reverse, data->substr(0, 4));
	    --index_reverse;
	  }
	  while(index_reverse >= 0){
	    getline(inFile, line);
	    ++line_num;
	    Word_Info.parse_line(line);

	    /* Set the time */
	    previous_command->set_time(*Word_Info.get_time());
	    
	    data = Word_Info.get_data();
	    if (Word_Info.get_size()->compare("D32") == 0) {
	      list_word[index_reverse].set_values(line_num, index_reverse, data->substr(4, 4));
	      --index_reverse;
	      list_word[index_reverse].set_values(line_num, index_reverse, data->substr(0, 4));
	      --index_reverse;
	    }
	  }
	}
	 
        
	if ( order == true ) {
	  for ( int i = 0; i < num_words; i++) {
	    if (list_word[i].get_field_name().compare("") != 0) {
	      list_word[i].print(outFile);
	    }
	  }
	  outFile<<endl;
	}
	else {
	  for ( int i = num_words - 1; i >= 0; i--) {
	    if (list_word[i].get_field_name().compare("") != 0) {
	      list_word[i].print(outFile);
	    }
	  }
	  outFile<<endl;
	}
	
      } else outFile<<endl; 
     
      }
  }

  inFile.close();

  RelTime.print(outFile);
  outFile.close();
  	
  delete [] list_word;
  delete command;
  return 0;

}

