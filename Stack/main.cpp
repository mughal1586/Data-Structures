#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack s;
    int choice, data, position;

    cout << " ____  _             _    " << endl;
    cout << "/ ___|| |_ __ _  ___| | __" << endl;
    cout << "\\___ \\| __/ _` |/ __| |/ /" << endl;
    cout << " ___) | || (_| | (__|   < " << endl;
    cout << "|____/ \\__\\__,_|\\___|_|\\_\\" << endl;

    do {
        cout << "-----------------------------------------------------" << endl;
        cout << "1. Push to Stack" << endl;
        cout << "2. Pop from Stack" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Search in Stack" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Stack contents (top to bottom):" << endl;
                s.display();
                break;
            case 4:
                cout << "Enter data to search: ";
                cin >> data;
                position = s.search(data);
                if (position != -1) {
                    cout << "Data " << data << " found at index " << position << " (0-based from bottom)." << endl;
                } else {
                    cout << "Data " << data << " not found in stack." << endl;
                }
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
