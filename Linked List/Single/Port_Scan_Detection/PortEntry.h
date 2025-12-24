#include <iostream>
using namespace std;

class PortEntry
{
private:
    int port;
    int count;
    PortEntry *next;

public:
    PortEntry();
    PortEntry(int);

    int get_port();
    void set_port(int);
    int get_count();
    void set_count(int);

    PortEntry *get_next();
    void set_next(PortEntry *);
};