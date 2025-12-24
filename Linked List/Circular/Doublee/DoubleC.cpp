#include "DoubleC.h"

using namespace std;

DoubleC::DoubleC()
{
    head = NULL;
    tail = NULL;
}

bool DoubleC::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
void DoubleC::insertAttail(int data)
{
    if (isEmpty())
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        tail->set_next(head);
        head->set_previous(tail);
    }
    else
    {
        Node *temp = new Node(data);
        tail->set_next(temp);
        temp->set_previous(tail);
        tail = temp;
        tail->set_next(head);
        head->set_previous(tail);
    }
}
void DoubleC::insertAtHead(int data)
{
    if (isEmpty())
    {
        insertAttail(data);
    }
    else
    {
        Node *temp = new Node(data);
        temp->set_next(head);
        head->set_previous(temp);
        head = temp;
        tail->set_next(head);
        head->set_previous(tail);
    }
}
void DoubleC::insertAtTarget(int toFind, int data)
{
    Node *target = search(toFind);
    if (target == NULL)
    {
        cout << "\nTarget Not Found !!!" << endl;
        return;
    }
    else if (target == head)
    {
        insertAtHead(data);
    }
    else if (target == tail)
    {
        insertAttail(data);
    }
    else
    {
        Node *temp = new Node(data);
        temp->set_next(target->get_next());
        target->set_next(temp);
        temp->set_previous(target);
        temp->get_next()->set_previous(temp);
    }
}
void DoubleC::remove(int toRemove)
{
    Node *targetnode = search(toRemove);

    if (targetnode == NULL)
    {
        cout << "\nTarget Not Found !!!" << endl;
        return;
    }
    else if (targetnode == head)
    {
        head = head->get_next();
        targetnode->set_next(NULL);
        targetnode->set_previous(NULL);

        delete targetnode;

        head->set_previous(tail);
        tail->set_next(head);
    }
    else if (targetnode == tail)
    {
        tail = tail->get_previous();
        targetnode->set_next(NULL);
        targetnode->set_previous(NULL);

        delete targetnode;

        tail->set_next(head);
        head->set_previous(tail);
    }
    else
    {
        Node *previous = targetnode->get_previous();
        Node *next = targetnode->get_next();

        previous->set_next(next);
        next->set_previous(previous);

        targetnode->set_previous(NULL);
        targetnode->set_next(NULL);

        delete targetnode;
    }
}
Node *DoubleC::search(int toSearch)
{
    Node *temp = head;
    do
    {
        if (temp->get_data() == toSearch)
        {
            return temp;
        }
        else
        {
            temp = temp->get_next();
        }
    } while (temp != head);
    return NULL;
}
void DoubleC::printAll()
{
    Node *temp = head;
    do
    {
        cout << temp->get_data() << endl;
        temp = temp->get_next();

    } while (temp != head);
}
void DoubleC::print_reverse()
{
    Node *temp = tail;
    do
    {
        cout << temp->get_data() << endl;
        temp = temp->get_previous();

    } while (temp != tail);
}