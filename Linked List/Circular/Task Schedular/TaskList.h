#include "Task.h"

using namespace std;

class TaskList
{
private:
    Task *head;
    Task *tail;
    Task *current;

public:
    TaskList();
    bool isEmpty();

    void insertAtTail(Task *);
    void insertAtHead(Task *);
    void insertAfterTask(Task *, Task *);

    void removeTask(Task *);
    Task *searchTask(int);

    void printAll();
    void printNext();
    void printPrevious();
    void printByPriority(string);

    Task *getCurrent();
    void setCurrent(Task *);
};
