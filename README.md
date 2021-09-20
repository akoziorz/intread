# intread
Rigorous Integer Reader Module for C++

This module provides a function ReadInteger(ReqValue, min, max) that successfully reads strictly integer input within a specified range. 
This specific module offers the ability to provide a prompt message and forces users to retry their input if the read is unsuccessful.
  
Function Format:

    int ReadInteger(std::string ReqValue, int min, int max);
    
Where

    ReqValue - The printed message that prompts the user for the input
    min - The minimum value for the integer allowed
    max - The maximum value for the integer allowed

Requires the following modules: <iostream.h>, <ctype.h>, <sstream.h>
