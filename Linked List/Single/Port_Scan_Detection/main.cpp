#include "PortScanTracker.h"

using namespace std;

int main()
{
    PortScanTracker tracker;
    int choice;
    int port;

    while (true)
    {
        cout << "********* -- PORT SCAN TRACKER -- *********" << endl;
        cout << "1. Add Port" << endl;
        cout << "2. Delete Port" << endl;
        cout << "3. Search Port" << endl;
        cout << "4. Display All Ports" << endl;
        cout << "5. Clear All Ports" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter port to add = ";
            cin >> port;
            tracker.addport(port);
            break;

        case 2:
            cout << "Enter port to delete = ";
            cin >> port;
            tracker.delport(port);
            break;

        case 3:
            cout << "Enter port to search: ";
            cin >> port;
            if (tracker.search(port))
                cout << "Port " << port << " is being tracked." << endl;
            else
                cout << "Port " << port << " not found." << endl;
            break;

        case 4:
            tracker.display();
            break;

        case 5:
            tracker.clear();
            break;

        case 6:
            cout << "Exiting program ..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
