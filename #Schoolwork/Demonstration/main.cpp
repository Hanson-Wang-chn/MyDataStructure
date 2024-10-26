#include "MyQueue.h"

bool do_command(char c, MyExtendedQueue &test_queue);
char get_command();

int main()
{
    MyExtendedQueue test_queue;

    introduction();
    while (do_command(get_command(), test_queue));
}

bool do_command(char c, MyExtendedQueue &test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
      Returns false if c == 'q', otherwise returns true.
*/
{
    bool continue_input = true;
    char x;

    switch (c) {
        case 'r':
            if (test_queue.retrieve(x) == underflow)
                cout << "Queue is empty." << endl;
            else
                cout << endl
                     << "The first entry is: " << x
                     << endl;
            break;

        case 'a':
            cout << "please input a char" << endl;
            cin >> x;
            if (test_queue.append(x) == overflow)
                cout << "Queue is full." << endl;
            break;

        case 's':
            if (test_queue.serve() == underflow)
                cout << "Queue is empty." << endl;
            break;

        case '#':
            cout << "The size of Queue is:" << test_queue.size() << endl;
            break;

        case 'c':
            test_queue.clear();
            cout << "The empty queue with length" << "  " << test_queue.size() << endl;
            break;

        case 'h':
            help();
            break;

        case 'p':
            int i, j;
            char y;
            j = test_queue.size();
            if (j == 0)
                cout << "Empty Queue" << endl;
            else {
                cout << "The Queue is " << flush;
                for(i=1;i<=j;i++) {
                    test_queue.serve_and_retrieve(y);
                    cout << y << " " << flush;
                    test_queue.append(y);
                }
                cout << endl;
            }
            break;

        case 'q':
            cout << "Queue demonstration finished." << endl;
            continue_input = false;
            break;
    }
    return continue_input;
}

char get_command()
/*
Pre:  None
Post: The function returns a valid lowercase command character that the user has input.
*/
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";
    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == 'a' || command == 's' || command == 'r' ||
            command == '#' || command == 'c' || command == 'p' ||
            command == 'h' || command == 'q' ) {
            waiting = false;
        } else {
            cout << "Please enter a valid command:" << endl
                 << "[a] Append [s] Serve  [r] Retrieve " << endl
                 << "[#] Size [c] Clear [p] Print [h] Help page" << endl
                 << "[q]uit." << endl;
        }
    }
    return command;
}