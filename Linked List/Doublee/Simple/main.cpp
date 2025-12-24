#include "DoubleeLinkedList.h"

using namespace std;

int main()
{
    DoubleLinkedList list;
    int choice, data, target;

    do
    {
        cout << "\n********** -- Double Linked List Menu -- **********" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Insert after Target Data" << endl;
        cout << "4. Remove Node with Data" << endl;
        cout << "5. Search for Data" << endl;
        cout << "6. Print List Forward" << endl;
        cout << "7. Print List Reverse" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at head: ";
            cin >> data;
            list.insertAtHead(data);
            break;
        case 2:
            cout << "Enter data to insert at tail: ";
            cin >> data;
            list.insertAtTail(data);
            break;
        case 3:
            cout << "Enter target data after which to insert: ";
            cin >> target;
            cout << "Enter data to insert: ";
            cin >> data;
            list.insertAtTarget(target, data);
            break;
        case 4:
            cout << "Enter data to remove: ";
            cin >> data;
            list.remove(data);
            break;
        case 5:
        {
            cout << "Enter data to search: ";
            cin >> data;
            Node *found = list.search(data);
            if (found)
                cout << "Data " << data << " found in list." << endl;
            else
                cout << "Data " << data << " not found." << endl;
            break;
        }
        case 6:
            cout << "List contents (forward):" << endl;
            list.printAll();
            break;
        case 7:
            cout << "List contents (reverse):" << endl;
            list.printReverse();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
