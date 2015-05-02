// Class responsible for converting values between hex, binary, and decimal
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <math.h>
#include "convert.h"

using namespace std;


// Pass in the string
string hex_to_bin(string s) {
    stringstream hex_to_bin;
    int n;
    string address_in_binary = "";

    if ( s.length() < 5 ) {
        hex_to_bin << hex << s;
        hex_to_bin >> n;
        bitset<16> b(n);
        address_in_binary = b.to_string();
    } else {
        hex_to_bin << hex << s;
        hex_to_bin >> n;
        bitset<32> b(n);
        address_in_binary = b.to_string();
    }

    return address_in_binary;
}

int bin_to_dec(string address_in_binary) {
    int dec;
    stringstream bin_to_dec;
    bitset<32> set(address_in_binary);
    bin_to_dec << hex << set.to_ulong() << endl;
    bin_to_dec >> dec;
    return dec;
}

int hex_to_dec(string s) {
    string address_in_bin = hex_to_bin(s);
    int address_in_dec = bin_to_dec(address_in_bin);
    return address_in_dec;
}

int bit_shift(string data, int hiBound, int loBound) {
    int hexNum = hex_to_dec(data);
    int bitShift;
    int final;
    int bitMask = pow(2, hiBound - loBound) - 1;

    bitShift = hexNum >> loBound;

    final = bitShift & bitMask;
    return final;
}

