#include <iostream>
#include <string>
#include <assert.h>
#include "convert.h"
#include "word.h"

using namespace std;

//-----------------------------------------------------------------------
Word::Word() {
    line_num = 0;
    word_num = 0;
    field_name = "";
    description = "";
    data_value = -1;
}
//-----------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------
void Word::set_values(int line_num, int word_num, string data) {
    int data_value;
    string field_name = "";
    string description = "";

    switch (word_num) {
    //--------------------------Case 0: Rec_Ctrl---------------------------------------
    case 0:
        field_name = " Rec_Ctrl";
        data_value = bit_shift(data, 14, 13);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (no recording)";
        else if (data_value == 2)
            description = " (no processing)";
        else if (data_value == 3)
            description = " (processing & recording";
        else
            description = " (unknown)";
        break;
    //--------------------------------------------------------------------------------

    //-------------------------Case 1: Cmd_Type----------------------------------------
    case 1:
        field_name = " Cmd_Type";
        data_value = bit_shift(data, 15, 13);
        assert(data_value >= 0);
        if (data_value == 4)
            description = " (Type A)";
        else if (data_value == 5)
            description = " (Type B)";
        else if (data_value == 6)
	  description = " (Type C)";
        else
            description = " (unknown)";
        break;
    //---------------------------------------------------------------------------------

    //-------------------------Case 4: Rec_Raw-----------------------------------------
    case 4:
        field_name = " Rec_Raw";
        data_value = bit_shift(data, 0, 0);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (disable)";
        else if (data_value == 1)
            description = " (enable)";
        else
            description = " (unknown)";
        break;
    //---------------------------------------------------------------------------------

    //-------------------------Case 5: Cmd_ID------------------------------------------
    case 5:
        field_name = " Cmd_ID";
        data_value = bit_shift(data, 6, 0);
        assert(data_value >= 0);
        description = "";
        break;
    //---------------------------------------------------------------------------------
    
    //--------------------------Case 10: Num_Response----------------------------------
    case 10:
        field_name = " Num_Responses";
        data_value = bit_shift(data, 15, 11);
        assert(data_value >= 0);
        description = "";
        break;
    //---------------------------------------------------------------------------------
    
    //--------------------------Case 15: Reset_Enable----------------------------------
    case 15:
        field_name = " Reset_Enable";
        data_value = bit_shift(data, 2, 2);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (disable)";
        else if (data_value == 1)
            description = " (enable)";
        else
            description = " (unknown)";
        break;
    //---------------------------------------------------------------------------------
   
    //-------------------------Case 22: Direction----------------------------------------
    case 22:
        field_name = " Direction";
        data_value = bit_shift(data, 3, 3);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (Right)";
        else if (data_value == 1)
            description = " (Left)";
        else
            description = " (unknown)";
        break;
    //----------------------------------------------------------------------------------

    //------------------------Case 32: Num_Samples-----------------------------------------
    case 32:
        field_name = " Num_Samples";
        data_value = bit_shift(data, 14, 0);
        assert(data_value >= 0);
        description = "";
        break;
    //-------------------------------------------------------------------------------------

    //-----------------------Case 37: Parity-----------------------------------------------
    case 37:
        field_name = " Parity";
        data_value = bit_shift(data, 15, 15);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (even)";
        else if (data_value == 1)
            description = " (odd)";
        else
            description = " (unknown)";
        break;
    //-------------------------------------------------------------------------------------

    //--------------------------Case 38: Test----------------------------------------------
    case 38:
        field_name = " Test";
        data_value = bit_shift(data, 14, 14);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (disable)";
        else if (data_value == 1)
            description = " (enable)";
        else
            description = " (unknown)";
        break;
    //------------------------------------------------------------------------------------

    //-------------------------Case 40: Ctrl Enable---------------------------------------
    case 40:
        field_name = " Ctrl_Enable";
        data_value = bit_shift(data, 7, 7);
        assert(data_value >= 0);
        if (data_value == 0)
            description = " (disable)";
        else if (data_value == 1)
            description = " (enable)";
        else
            description = " (unknown)";
        break;
    //-------------------------------------------------------------------------------------

    //------------------------Case 41: Code------------------------------------------------
    case 41:
        field_name = " Code";
        data_value = bit_shift(data, 14, 8);
        assert(data_value >= 0);
        description = "";
        break;
    }
    //-------------------------------------------------------------------------------------

    //-----------Set the values for the current Word---------------------------------------
    this->line_num = line_num;
    this->word_num = word_num;
    this->field_name = field_name;
    this->data_value = data_value;
    this->description = description;
    //-------------------------------------------------------------------------------------
}
//-------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------
string Word::get_field_name() {
    return field_name;
}
//------------------------------------------------------------------------

//-------------------------------------------------------------------------
void Word::print(ostream& stream) {
  stream << "Line " << line_num << ": Word " << word_num << ":" << field_name 
	 << " = " << data_value  << description << endl;
}
//-------------------------------------------------------------------------
