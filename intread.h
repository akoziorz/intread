/*
Name: Adam Koziorz
Program: intread (header file)
Last Edited: June 4th, 2020
Description: This header file defines the ReadInteger function
*/

#ifndef INTREAD_H
#define INTREAD_H

// Read Integer Function
// (ReqValue - The printed message that prompts the user for the input)
// (min - The minimum value for the integer allowed)
// (max - The maximum value for the integer allowed)
int ReadInteger(std::string ReqValue, int min, int max);