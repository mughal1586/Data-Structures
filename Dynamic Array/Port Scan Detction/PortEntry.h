#include <iostream>

using namespace std;

class PortEntry
{
private:
    int port;
    int count;

public:
    PortEntry();
    PortEntry(int);

    int get_port();
    void set_port(int);
    int get_count();
    void set_count(int);
};