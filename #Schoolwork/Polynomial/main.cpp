#include "MyLinkedStack.h"

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";
    while (waiting) {
        cin >> command;
        check_stream(command);
        command = tolower(command);
        if (command == '?' || command == '=' ||
            command == '+' || command == 'q' ||
            command == '*' || command == '-')
            waiting = false;
        else {
            cout << "Please enter a valid command:" << endl
                 << "[?] Read a Polynomial" << endl
                 << "[=] Return Top Polynomial" << endl
                 << "[+] Sum two Polynomial" <<endl
                 << "[-] Difference two Polynomial" <<endl
                 << "[*] Mult one Polynomial with a Term" <<endl
                 << "[q] Quit." << endl;
        }
    }
    return command;
}

bool do_command(char command, MyLinkedStack &stored_polynomials)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of Polynomial
      objects given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The classes Stack and Polynomial.
*/
{
    Polynomial p, q, r;

    switch (command) {
        case '?':
            p.read();
            if (stored_polynomials.push(p) == overflow)
                cout << "Warning: Stack full, lost polynomial" << endl;
            break;

        case '=':
            if (stored_polynomials.isEmpty())
                cout << "Stack empty" << endl;
            else {
                stored_polynomials.top(p);
                p.print();
            }
            break;

        case '+':
            if (stored_polynomials.isEmpty())
                cout << "Stack empty" << endl;
            else {
                stored_polynomials.top(p);
                stored_polynomials.pop();
                if (stored_polynomials.isEmpty()) {
                    cout << "Stack has just one polynomial" << endl;
                    stored_polynomials.push(p);
                }
                else {
                    stored_polynomials.top(q);
                    stored_polynomials.pop();
                    r.equals_sum(q, p);
                    if (stored_polynomials.push(r) == overflow)
                        cout << "Warning: Stack full, lost polynomial" << endl;
                    else {
                        cout << "The following Polynomial has been put into the stack:" << endl;
                        r.print();
                    }
                }
            }
            break;

        case '-':
            if (stored_polynomials.isEmpty())
                cout << "Stack empty" << endl;
            else {
                stored_polynomials.top(p);
                stored_polynomials.pop();
                if (stored_polynomials.isEmpty()) {
                    cout << "Stack has just one polynomial" << endl;
                    stored_polynomials.push(p);
                }
                else {
                    stored_polynomials.top(q);
                    stored_polynomials.pop();
                    r.equals_difference(q, p);
                    if (stored_polynomials.push(r) == overflow)
                        cout << "Warning: Stack full, lost polynomial" << endl;
                    else {
                        cout << "The following Polynomial has been put into the stack:" << endl;
                        r.print();
                    }
                }
            }
            break;

        case '*':
            if (stored_polynomials.isEmpty())
                cout << "Stack empty" << endl;
            else {
                double coefficient;
                int exponent;
                stored_polynomials.top(p);
                stored_polynomials.pop();
                cout << "Enter the coefficients and exponents for the polynomial,one pair per line." << endl
                     << "Exponents must be >=0." << endl;
                cout << "coefficient? " << flush;
                cin  >> coefficient;
                cout << "exponent? " << flush;
                cin  >> exponent;
                if (exponent < 0) {
                    cout << "Bad exponent: Exponents must be >=0." << endl;
                    stored_polynomials.push(p);
                }
                else {
                    Term new_term(exponent, coefficient);
                    r.mult_term(p,new_term);
                    if (stored_polynomials.push(r) == overflow)
                        cout << "Warning: Stack full, lost polynomial" << endl;
                    else {
                        cout << "The following Polynomial has been put into the stack:" << endl;
                        r.print();
                    }
                }
            }
            break;

        case 'q':
            cout << "Calculation finished." << endl;
            return false;
    }
    return true;
}

int main()
/*
Post: The program has executed simple polynomial arithmetic
      commands entered by the user.
Uses: The classes Stack and Polynomial and the functions
      introduction, instructions, do_command, and get_command.
*/
{
    MyLinkedStack stored_polynomials;
    void introduction();
    void instructions();
    bool do_command(char command, MyLinkedStack &stored_polynomials);
    char get_command();
    char tolower(char command);
    introduction();
    instructions();
    while (do_command(get_command(), stored_polynomials));

    return 0;
}