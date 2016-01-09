# C_header-File-Protocol
A simplified version of the standard sdtio.h file stream functions. 

// Use in C:
  #include <stdio.h>
  #include "fp.h"

  int main ( void ) {
    // Create and write to file: text.txt, include text in file on creation: "Hello".
    fProto_write ("text.txt", "Hello");
    
    // Add additional text to previously created file: text.txt, text added: " World!".
    fProto_add ("text.txt", " World!");
    
    // Read out file contents to console.
    fProto_read ("text.txt");
    return 0;
  }
  
  //////////////////////////////////////////////////////////////
  
  // Use in C++:
  #include <iostream>
  #include "fp.h"
  using namespace std;
  
  int main ( void ) {
     // Create and write to file: text.txt, include text in file on creation: "Hello".
    fProto_write ("text.txt", "Hello");
    
    // Add additional text to previously created file: text.txt, text added: " World!".
    fProto_add ("text.txt", " World!");
    
    // Read out file contents to console.
    fProto_read ("text.txt");
      return 0;
  }

