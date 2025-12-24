#include "Task.h"

using namespace std;

Task::Task()
{
    id = -1;
    description = "";
    priority = "";
    deadline = "";

    next = NULL;
    previous = NULL;
}
Task::Task(int id, string description, string priority, string deadline)
{
    this->id = id;
    this->description = description;
    this->priority = priority;
    this->deadline = deadline;

    next = NULL;
    previous = NULL;
}

int Task::get_id()
{
    return id;
}
void Task::set_id(int id)
{
    this->id = id;
}
string Task::get_description()
{
    return description;
}
void Task::set_description(string description)
{
    this->description = description;
}
string Task::get_priority()
{
    return priority;
}
void Task::set_priority(string priority)
{
    this->priority = priority;
}
string Task::get_deadline()
{
    return deadline;
}
void Task::set_deadline(string deadline)
{
    this->deadline = deadline;
}

Task *Task::get_next()
{
    return next;
}
void Task::set_next(Task *next)
{
    this->next = next;
}
Task *Task::get_previous()
{
    return previous;
}
void Task::set_previous(Task *previous)
{
    this->previous = previous;
}

void Task::add()
{
    cout << "Enter Task ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Task Description: ";
    getline(cin, description);
    cout << "Enter Task Priority (High/Medium/Low): ";
    getline(cin, priority);
    cout << "Enter Task Deadline: ";
    getline(cin, deadline);
}

void Task::display()
{
    cout << "------------------------" << endl;
    cout << "Task ID: " << id << endl;
    cout << "Description: " << description << endl;
    cout << "Priority: " << priority << endl;
    cout << "Deadline: " << deadline << endl;
    cout << "------------------------" << endl;
}