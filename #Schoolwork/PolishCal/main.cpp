#include "PolishCal.h"

int main()
/* Pre: The user supplies a series of commands and numbers.
   Post: The program has executed simple arithmetic commands entered by the user.
   Uses: The class Stack and the functions introduction, instructions, do_command, and get_command.*/

{
    MyStack stored_numbers;

    introduction();
    instructions();

    while (do_command(get_command(), stored_numbers));

    return 0;
}
