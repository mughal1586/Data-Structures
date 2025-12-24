#include "Management.h"

using namespace std;

int main()
{
    Management system;
    int choice;

    do
    {
        cout << "\n********** -- Cyber Incident Management Menu -- **********" << endl;
        cout << "1. Add Incident Record" << endl;
        cout << "2. Display Most Severe Active Incident" << endl;
        cout << "3. Show Most Recent Incident" << endl;
        cout << "4. Resolve & Remove an Incident" << endl;
        cout << "5. Display All Incidents" << endl;
        cout << "6. Display All Incidents (Reverse Order)" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            Node record;
            record.input();

            if (record.get_severity() == "critical")
            {
                system.insertAtHead(record);
            }
            else if (record.get_severity() == "high")
            {
                if (system.isEmpty())
                {
                    cout << "List is empty, inserting at head by default." << endl;
                    system.insertAtHead(record);
                }
                else
                {
                    Node target;
                    int id;
                    cout << "Enter Incident ID after which to insert (for high severity): ";
                    cin >> id;
                    cin.ignore();
                    target.set_incident_id(id);
                    system.insertAtTarget(target, record);
                }
            }

            else if (record.get_severity() == "low")
            {
                system.insertAtTail(record);
            }
            else
            {
                cout << "Invalid Severity Type! Record not added." << endl;
            }

            break;
        }

        case 2:
        {
            string status;
            string severity;

            cout << "\nEnter Status to Filter (active/resolved): ";
            getline(cin, status);

            cout << "Enter Severity to Search (critical/high/low): ";
            getline(cin, severity);

            system.highest_severity(status, severity);
            break;
        }

        case 3:
        {
            if (system.isEmpty())
            {
                cout << "\nNo incidents recorded yet !!!" << endl;
            }
            else
            {
                cout << "\nMost Recent Incident:" << endl;
                system.get_tail()->display();
            }
            break;
        }

        case 4:
        {
            int id;
            cout << "\nEnter Incident ID to Resolve & Remove: ";
            cin >> id;
            cin.ignore();

            system.remove_incident(id);
            break;
        }

        case 5:
        {
            cout << "\nAll Recorded Incidents:" << endl;
            system.printAll();
            break;
        }

        case 6:
        {
            cout << "\nAll Incidents (Reverse Display):" << endl;
            system.printReverse();
            break;
        }

        case 0:
            cout << "\nExiting Program..." << endl;
            break;

        default:
            cout << "\nInvalid choice !!! \nTry again." << endl;
        }

    } while (choice != 0);

    return 0;
}
