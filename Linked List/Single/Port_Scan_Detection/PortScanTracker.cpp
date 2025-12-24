#include "PortScanTracker.h"

using namespace std;

PortScanTracker::PortScanTracker()
{
    head = NULL;
    tail = NULL;
}

void PortScanTracker::addport(int portnum)
{
    PortEntry *existing = search(portnum);

    if (existing != NULL)
    {
        cout << "\nUpdating port " << portnum << " count..." << endl;
        existing->set_count(existing->get_count() + 1);
    }
    else
    {
        PortEntry *newport = new PortEntry();
        newport->set_port(portnum);
        newport->set_count(1);
        newport->set_next(head);
        head = newport;

        cout << "\nAdding new port " << portnum << endl;
    }
}

void PortScanTracker::delport(int portnum)
{
    if (head == NULL)
    {
        cout << "\nNo ports to delete!" << endl;
        return;
    }

    PortEntry *temp = head;
    PortEntry *prev = NULL;

    while (temp != NULL)
    {
        if (temp->get_port() == portnum)
        {
            break;
        }
        prev = temp;
        temp = temp->get_next();
    }

    if (temp == NULL)
    {
        cout << "\nPort Not Found !!!" << endl;
        return;
    }

    if (temp == head)
    {
        head = head->get_next();
        }
    else
    {
        prev->set_next(temp->get_next());
    }

    delete temp;
    cout << "\nPort " << portnum << " deleted successfully." << endl;
}

PortEntry *PortScanTracker::search(int portnum)
{
    PortEntry *temp = head;
    while (temp != NULL)
    {
        if (temp->get_port() == portnum)
        {
            cout << "Searching... ";
            return temp;
        }
        temp = temp->get_next();
    }
    return NULL;
}

void PortScanTracker::display()
{
    if (head == NULL)
    {
        cout << "\nZero Ports Detected !!!" << endl;
        return;
    }

    cout << "\nList of Ports Tracked" << endl;
    PortEntry *temp = head;
    int index = 1;
    while (temp != NULL)
    {
        cout << index << ". Port = " << temp->get_port()
             << ", Count = " << temp->get_count() << endl;
        temp = temp->get_next();
        index++;
    }
    cout << endl;
}

void PortScanTracker::clear()
{
    PortEntry *temp = head;
    while (temp != NULL)
    {
        PortEntry *next = temp->get_next();
        delete temp;
        temp = next;
    }
    head = NULL;
    cout << "All ports cleared." << endl;
}
