#include "PortEntry.h"

using namespace std;

class PortScanTracker
{
private:
    PortEntry *port;
    int capacity;
    int size;

public:
    PortScanTracker(int);
    int get_capacity();
    void set_capacity(int);
    int get_size();
    void set_size(int);

    // Others ....

    void addport(int);
    void delport(int);
    int search(int);
    void resize();
    void shift(int);
    void display();
    void cleararray();
};