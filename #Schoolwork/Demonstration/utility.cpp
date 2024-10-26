//
// Created by 王海生 on 2024/3/21.
//

#include "utility.h"

void introduction()
{
    help();
}

void help()
/*
Pre: None
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/
{
    cout << endl
         << "This program allows the user to enter one command" << endl
         << "(but only one) on each input line." << endl
         << "For example, if the command S is entered, then" << endl
         << "the program will serve the front of the queue." << endl
         << endl
         << " The valid commands are:" << endl
         << "A - Append the next input character to the extended queue" << endl
         << "S - Serve the front of the extended queue" << endl
         << "R - Retrieve and print the front entry." << endl
         << "# - The current size of the extended queue" << endl
         << "C - Clear the extended queue (same as delete)" << endl
         << "P - Print the extended queue" << endl
         << "H - This help screen" << endl
         << "Q - Quit" << endl;
}