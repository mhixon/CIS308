#include <iostream>
#include <string>
#include "utf8string.hpp"
#include "ksu_utf8.h"
#include "ksu_unicode.h"


//Empty Constructor
utf8string :: utf8string() {
	//allocate empty char*
	_string = new unsigned char;		
	_string[0] = '\0';
	//init string length 
	_length = 1;			
	//init total number of bytes
	_byteLength = ksu_charpos_to_bytes(_string, 1);
}

utf8string :: utf8string(std::string) {
	_length = string.length();
	_string = new unsigned char[string.length()];
	_string = string.c_str(); 
	_byteLength = ksu_charpos_to_bytes(_string, 1);
}

utf8string :: utf8string(const utf8string& utf8s);{
	_length = utf8s._length;
	_byteLength = utf8s._byteLength;
	_string = new unsigned char[utf8s._length];
	for(int i = 0; i < utf8s._length; i++){
		_string[i] = utf8s._string[i];
	}
}

utf8string :: ~utf8string(){
	delete[] _string;
}

utf8string :: utf8string &operator=(const utf8string&){

}

utf8string :: size_t length(){
	return _length;
}

utf8string :: size_t byte_length() {
	return _byteLength;
}


utf8string :: ostream &operator<<(ostream&, utf8string){

}
