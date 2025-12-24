#include "TaskList.h"

using namespace std;

TaskList::TaskList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

bool TaskList::isEmpty()
{
    return head == NULL;
}

void TaskList::insertAtTail(Task *task)
{
    if (isEmpty())
    {
        head = task;
        tail = task;
        head->set_next(head);
        head->set_previous(head);
    }
    else
    {
        tail->set_next(task);
        task->set_previous(tail);
        task->set_next(head);
        head->set_previous(task);
        tail = task;
    }
    if (current == NULL)
        current = head;
}

void TaskList::insertAtHead(Task *task)
{
    if (isEmpty())
    {
        insertAtTail(task);
    }
    else
    {
        task->set_next(head);
        task->set_previous(tail);
        head->set_previous(task);
        tail->set_next(task);
        head = task;
    }
    if (current == NULL)
        current = head;
}

void TaskList::insertAfterTask(Task *target, Task *task)
{
    if (target == NULL)
    {
        cout << "Target Task Not Found!" << endl;
        return;
    }
    if (target == tail)
    {
        insertAtTail(task);
    }
    else
    {
        task->set_next(target->get_next());
        task->set_previous(target);
        target->get_next()->set_previous(task);
        target->set_next(task);
    }
}

void TaskList::removeTask(Task *target)
{
    if (target == NULL)
    {
        cout << "Task Not Found!" << endl;
        return;
    }
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
        current = NULL;
        delete target;
        return;
    }
    if (target == head)
    {
        head = head->get_next();
        head->set_previous(tail);
        tail->set_next(head);
        if (current == target)
            current = head;
    }
    else if (target == tail)
    {
        tail = tail->get_previous();
        tail->set_next(head);
        head->set_previous(tail);
        if (current == target)
            current = tail;
    }
    else
    {
        target->get_previous()->set_next(target->get_next());
        target->get_next()->set_previous(target->get_previous());
        if (current == target)
            current = target->get_next();
    }
    delete target;
}

Task *TaskList::searchTask(int id)
{
    if (isEmpty())
        return NULL;
    Task *temp = head;
    do
    {
        if (temp->get_id() == id)
            return temp;
        temp = temp->get_next();
    } while (temp != head);
    return NULL;
}

void TaskList::printAll()
{
    if (isEmpty())
    {
        cout << "No tasks available" << endl;
        return;
    }
    Task *temp = head;
    do
    {
        temp->display();
        temp = temp->get_next();
    } while (temp != head);
}

void TaskList::printNext()
{
    if (isEmpty())
    {
        cout << "No tasks available" << endl;
        return;
    }
    if (current == NULL)
        current = head;
    current->display();
    current = current->get_next();
}

void TaskList::printPrevious()
{
    if (isEmpty())
    {
        cout << "No tasks available" << endl;
        return;
    }
    if (current == NULL)
        current = head;
    current = current->get_previous();
    current->display();
}

void TaskList::printByPriority(string priority)
{
    if (isEmpty())
    {
        cout << "No tasks available" << endl;
        return;
    }
    Task *temp = head;
    bool found = false;
    do
    {
        if (temp->get_priority() == priority)
        {
            temp->display();
            found = true;
        }
        temp = temp->get_next();
    } while (temp != head);
    if (!found)
        cout << "No tasks with priority " << priority << " found." << endl;
}

Task *TaskList::getCurrent()
{
    return current;
}

void TaskList::setCurrent(Task *task)
{
    current = task;
}
