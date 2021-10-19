/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Daniel Partika
 * Date        : 9/25/2021
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    for(const char &c : s){
        if (c < 'a' || c > 'z'){
            return false;
        }
    }
    return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    unsigned int i = 0;
    for(const char &c : s){ 
        if ((i & (1 << (c - 'a'))) > 0)  {
            return false;
        } else {
            i = i | (1 << (c - 'a'));
        }
        
    }
    return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    string s;

	istringstream iss;

	if(argc != 2){ 
	//wrong input
		cerr << "Usage: " << argv[0] << " <string>" << endl;
		return 1; 
	}

	iss.str(argv[1]);
	if(!(iss >> s) || !(is_all_lowercase(s))){ //reads iss and stores in s, if the condition is not met error needs to be thrown
		cerr << "Error: String must contain only lowercase letters." << endl;
		return 1; //end program
	}
    iss.clear();
    //input is correct
    if (s.length() <= 26 && all_unique_letters(s)){ //make more efficient, check if less than 26 letters.
        cout << "All letters are unique." << endl;
    } else {
        cout << "Duplicate letters found." << endl;
    }
	 
	return 0; 
}






