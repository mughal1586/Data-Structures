#include <iostream>
#include <string>

using namespace std;

class Task
{
private:
    int id;
    string description;
    string priority;
    string deadline;

    Task *next;
    Task *previous;

public:
    Task();
    Task(int, string, string, string);

    int get_id();
    void set_id(int);
    string get_description();
    void set_description(string);
    string get_priority();
    void set_priority(string);
    string get_deadline();
    void set_deadline(string);

    Task *get_next();
    void set_next(Task *);
    Task *get_previous();
    void set_previous(Task *);

    void add();
    void display();
};