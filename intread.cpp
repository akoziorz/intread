/*
Name: Adam Koziorz
Program: intread
Last Edited: June 4th, 2020
Description: Reads strictly integer input, including a prompt and validation
             The ReadInteger function takes the form:
                 int ReadInteger(std::string ReqValue, int min, int max)
             Where:
                 ReqValue - The printed message that prompts the user for the input
                 min - The minimum value for the integer allowed
                 max - The maximum value for the integer allowed
             
*/

// Include Statements
#include <iostream.h>
#include <ctype.h>
#include <sstream.h>   
#include "intread.h"

// Read Integer Function
int ReadInteger(std::string ReqValue, int min, int max) {
    // Declaring Variables
    std::string inputString;      // User's input as a string
    int inputInt;                 // User's input as an integer
    int digits = 0;               // The # of numerical characters in inputString

    bool NonZeroOccured = false;  // Used in the process of determining if the input
                                  //     starts with zero(es)
    bool isNegative     = false;  // Used to determine if the input is negative
                                      
    bool isGoodInput = true;      // Flag that remains true only if:
                                  //     + Something was input,
                                  //     + There's no spaces in the input,
                                  //     + The input does not start with zero(es),
                                  //     + The input as an integer is in range, and
                                  //     + The # of numerical characters in inputString is
                                  //       equal to the size of the inputString (indicating
                                  //       that there are no non-numeric characters)
                                  // This flag will be used to verify the validity of the input.
                                  // If the flag is true, the input is an integer.                           
    bool isValid = false;         // Used at the end to flag if the input is valid
    bool didFail = false;         // Used at the end to flag if the user had an invalid input

// This loop will run until a valid input has been made.
    while(!isValid)
    {
    // Asks the user for their input. The message depends on whether or not the user
    // has had an invalid input.
        if (!didFail)
            cout << ReqValue << ": ";
        else {
            cout << "Invalid input! Please try again: ";
        }
       
        // A getline is used to retrieve the user's input so that the program does not error
        // if a space is input.
        getline(cin, inputString);
        
        // Converts the input string into an integer.
        std::stringstream conversion(inputString);
        conversion >> inputInt;
             
        // Checks if the integer is negative.
        if (inputString[0] == '-')
            isNegative = true;

            // This loop analyzes all characters within the input string.
        for (int i = 0; i < inputString.size(); i++) {
            // If there are any spaces in the input string, the isGoodInput flag will be set
            // to false.
            if (isspace(inputString[i]))
                isGoodInput = false;
            
            // All digits in the input string is counted and analyzed, which will be used later
            // to check the input’s validity.
            if (isdigit(inputString[i])) {
                // Increment the digit counter.
                digits++;    
                
                // If a non-zero digit is detected after a zero and a non-zero digit was not
                // found earlier in the input, the input would have to had started with
                // zero(es), and the isGoodInput flag will be set to false, provided the input
                // itself is not 0. The below if-statements will be used to check this.
                if (inputString[i] != '0')
                    NonZeroOccured = true;
                else if (!NonZeroOccured and inputString[i+1] != '0' and inputInt != 0)
                    isGoodInput = false;
            }        
        }

        // If nothing was input or if the input as an integer is out of range, the isGoodInput flag
        // will be set to false.
        if (inputString.empty() or inputInt < min or inputInt > max)
            isGoodInput = false;
       
        // If the # of numerical characters if not equal to the length of the input string, the
        // isGoodInput flag will be set to false. If the number is negative, the negative sign will
        // be accounted for.
        if (isNegative) {
            if (digits + 1 != inputString.size())
                isGoodInput = false;
        } else if (digits != inputString.size())
            isGoodInput = false;
                
            // If the isGoodInput flag is still true, then the input is valid and will be 
            // flagged as such, breaking the loop.
            if (isGoodInput)
                isValid = true;

                // Otherwise...
            else {
            // If this is the user's first invalid input, the program will insert a line
            // for graphic reasons.
            if (!didFail)
                  cout << endl;
            
            // Resetting all variables and flagging didFail as true
            didFail = true;
            NonZeroOccured = false;
            isNegative = false;    
            isGoodInput = true;
            inputString.clear();
            inputInt = 0;
            digits = 0;
        }   
    }
    // Returns the user's input as an integer 
    return inputInt;
}
