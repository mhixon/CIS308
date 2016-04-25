#include <iostream>
#include <string>
#include <string.h>
#include "utf8string.hpp"
#include "ksu_utf8.h"

using namespace std;

//Empty Constructor
utf8string :: utf8string() {
	_string = new unsigned char;
	_string[0] = '\0';
    //won't have to worry about freeing null
    //ignore /0 in length and byte
    _length = 0;
	_byteLength = 0;
}

//Constructor with string
utf8string :: utf8string(std::string str) {
    //store a pointer to the memory spot of str
    char *p = (char *)str.c_str();
    _length = ksu_charlen((unsigned char *) p);
    _byteLength = str.length();
	_string = new unsigned char[_byteLength+1];
    for(int i = 0; i <= _byteLength; i++){
        _string[i] = p[i];
    }
    
}

//Copy constructor
utf8string :: utf8string(const utf8string& utf8s){
	_length = utf8s._length;
	_byteLength = utf8s._byteLength;
	_string = new unsigned char[utf8s._byteLength + 1];
	for(int i = 0; i <= utf8s._byteLength; i++){
		_string[i] = utf8s._string[i];
	}
}

//Deconstructor
utf8string :: ~utf8string(){
	delete[] _string;
}

//Overload the assignment operator
utf8string & utf8string :: operator=(const utf8string& utf8s){
    //remove current string
    delete[] _string;
    //reset attributes
    _length = utf8s._length;
    _byteLength = utf8s._byteLength;
    _string = new unsigned char[utf8s._byteLength + 1];
    for(int i = 0; i <= utf8s._byteLength; i++){
        _string[i] = utf8s._string[i];
    }
    return *this;
}

//Return char length
size_t utf8string :: length(){
	return _length;
}

//Return byte length
size_t utf8string :: byte_length() {
	return _byteLength;
}

//Overload the << operator
ostream &operator<<(ostream& os, utf8string utf8s){
    //we want to print the string
    os << utf8s._string;
    return os;
}

//Overload the == operator
bool utf8string :: operator==(const utf8string& utf8s){
    int i = 0;
    //check each char against each other until you reach the end of a word
    while(utf8s._string[i] != '\0' && _string[i] != '\0'){
        if(utf8s._string[i] == _string[i])
            i++;
        else
            return false;
    }
    
    if(utf8s._string[i] == '\0' && _string[i] == '\0')
        return true;
    else
        return false;

}

//Convert the word to uppercase
utf8string utf8string :: upper(){
    unsigned char* cpy = ksu_utf8_upper(this->_string);
    utf8string ret = utf8string(string((char *)cpy));
    //free our copy
    free(cpy);
    return ret;
}

