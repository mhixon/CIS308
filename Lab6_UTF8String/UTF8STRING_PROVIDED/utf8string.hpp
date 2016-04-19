#ifndef UTF8STRING_HPP
#define UTF8STRING_HPP

#include <iostream>
#include <string>

class utf8string {
      unsigned char* _string;		// Define whichever attributes
      size_t _length;			// you feel necesseary
	  size_t _byteLength;

  public:
      // Constructors
      utf8string();  // Default cosntructor
      // Constructor from an existing string
      utf8string(std::string);
      // Copy constructor
      utf8string(const utf8string&);
      // Destructor
      ~utf8string();
      // Assignment operator
      utf8string &operator=(const utf8string&);
      size_t     length();
      size_t     byte_length();
      friend std::ostream &operator<<(std::ostream&, utf8string);


      // ------------------------------------------------
      // ADDITIONALLY, implement one method in group A
      // and one method in group B (your choice)
      // ------------------------------------------------
      // GROUP A
      // -------
      // bool operator==(const utf8string&);     // Comparison operator
      // utf8string operator+(const utf8string); // Regular concatenation
      // utf8string &operator+=(const utf8string);
      //
      // GROUP B
      // -------
      // friend std::istream &operator>>(std::istream&, utf8string&);
      // utf8string upper();
      // utf8string lower();
      // utf8string unaccent();
      // utf8string reverse();   // return the reversed string
      //                         // i.e  utf8string("ABC").reverse() -> "CBA"
      // utf8string replace(utf8string remove, utf8string substitute);
      //                         // Replace ALL occurrences of remove
      //                         // with substitute in the string
};

#endif
