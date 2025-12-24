#include "PortEntry.h"

PortEntry::PortEntry()
{
    port = 0;
    count = 0;
    next = NULL;
}

PortEntry::PortEntry(int count)
{
    this->count = count;
    next = NULL;
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

PortEntry *PortEntry::get_next()
{
    return next;
}

void PortEntry::set_next(PortEntry *next)
{
    this->next = next;
}
