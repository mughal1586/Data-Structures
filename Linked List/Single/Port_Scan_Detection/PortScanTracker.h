#include "PortEntry.h"

class PortScanTracker
{
private:
    PortEntry *head;
    PortEntry *tail;

public:
    PortScanTracker();

    void addport(int);
    void delport(int);
    PortEntry *search(int);
    void display();
    void clear();
};
