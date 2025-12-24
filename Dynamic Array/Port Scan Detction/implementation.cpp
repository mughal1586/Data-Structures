#include "PortScanTracker.h"

/************** -- Implementation of Port Entry -- **************/
PortEntry::PortEntry()
{
    this->port = 0;
    this->count = 0;
}
PortEntry::PortEntry(int count)
{
    this->count = count;
}

int PortEntry::get_port()
{
    return port;
}
void PortEntry::set_port(int port)
{
    this->port = port;
}
int PortEntry::get_count()
{
    return count;
}
void PortEntry::set_count(int count)
{
    this->count = count;
}

/************** -- Implementation of Port Entry -- **************/
PortScanTracker::PortScanTracker(int capacity)
{
    this->capacity = capacity;
    port = new PortEntry[capacity];
    size = 0;
}
int PortScanTracker::get_capacity()
{
    return capacity;
}
void PortScanTracker::set_capacity(int capacity)
{
    this->capacity = capacity;
}
int PortScanTracker::get_size()
{
    return size;
}
void PortScanTracker::set_size(int size)
{
    this->size = size;
}

// Others ....

void PortScanTracker::addport(int portnum)
{
    int index = search(portnum);
    if (index == -1)
    {
        if (capacity == size)
        {
            cout << "\nResizing ..." << endl;
            resize();
        }
        cout << "Adding port " << portnum << endl;
        port[size].set_port(portnum);
        port[size].set_count(port[size].get_count() + 1);

        size++;
    }
    else
    {
        if (capacity == size)
        {
            cout << "\nResizing ..." << endl;
            resize();
        }
        cout << "\nUpdating a port " << portnum << " count " << endl;
        port[index].set_count(port[index].get_count() + 1);
    }
}
void PortScanTracker::delport(int portnum)
{
    int index = search(portnum);
    if (index == -1)
    {
        cout << "\nPort Not Found !!!" << endl;
    }
    else
    {
        cout << "\nDeleting port " << portnum << endl;
        shift(index);
        size--;

        port[size].set_port(0);
        port[size].set_count(0);
    }
}
int PortScanTracker::search(int portnum)
{
    for (int i = 0; i < size; i++)
    {
        if (port[i].get_port() == portnum)
        {
            cout << "Searching ... ";
            return i;
        }
    }
    return -1;
}
void PortScanTracker::resize()
{
    capacity = capacity * 2;
    PortEntry *newportlist = new PortEntry[capacity];
    for (int i = 0; i < size; i++)
    {
        newportlist[i] = port[i]; // newportlist[i].set_port(port[i].get_port()); && newportlist[i].set_count(port[i].get_count());
    }
    delete[] port;
    port = newportlist;
}
void PortScanTracker::shift(int index)
{
    for (int i = index; i < size - 1; i++)
    {
        port[i] = port[i + 1]; // port[i].set_port(port[i + 1].get_port()); && port[i].set_count(port[i + 1].get_count());
    }
}
void PortScanTracker::display()
{
    if (size == 0)
    {
        cout << "\nZero Ports Detected !!!" << endl;
    }
    else
    {
        cout << "\nList of Ports Tracked" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". Port = " << port[i].get_port() << ", Count = " << port[i].get_count() << endl;
        }
    }
    cout << endl;
}
void PortScanTracker::cleararray()
{
    size = 0;
    capacity = 5;
    delete[] port;
    port = new PortEntry[capacity];
}