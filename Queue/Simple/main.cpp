#include "Queue.h"

using namespace std;

int main(){
    Queue q;
    int choice, value;

    do {
        cout << "\n***** -- Queue Menu -- *****\n";
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display Queue"<<endl;
        cout << "4. Search Element"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.printAll();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (q.search(value))
                    cout << "Element found !!!" << endl;
            else
                cout << "Element not found !!!" << endl;
            break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice !!!" << endl;
        }
    } while (choice != 0);

    return 0;
}
