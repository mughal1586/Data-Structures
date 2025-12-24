#include "Circular.h"
#include <iostream>

using namespace std;

int main()
{
    Circular list;
    int choice, value, target;

    while (true)
    {
        cout << "\n********* -- Circular Linked List -- *********" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert after value" << endl;
        cout << "4. Remove value" << endl;
        cout << "5. Search value" << endl;
        cout << "6. Print list" << endl;
        cout << "7. Check if empty" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            list.insertAtHead(value);
            cout << "Value " << value << " inserted at head\n";
            break;

        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            list.insertAtTail(value);
            cout << "Value " << value << " inserted at tail\n";
            break;

        case 3:
            cout << "Enter target value to insert after: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> value;
            list.inserAtTarget(target, value);
            break;

        case 4:
            cout << "Enter value to remove: ";
            cin >> value;
            list.remove(value);
            break;

        case 5:
        {
            cout << "Enter value to search: ";
            cin >> value;
            Node *found = list.search(value);
            if (found != NULL)
            {
                cout << "Value " << value << " found in list\n";
            }
            else
            {
                cout << "Value " << value << " not found\n";
            }
            break;
        }

        case 6:
            cout << "Current list:\n";
            list.printAll();
            break;

        case 7:
            cout << "List is " << (list.isEmpty() ? "empty" : "not empty") << "\n";
            break;

        case 8:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
