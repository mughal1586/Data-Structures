#include "Circular.h"

using namespace std;

Circular::Circular()
{
    head = NULL;
    tail = NULL;
}

bool Circular::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
void Circular::insertAtTail(int data)
{
    if (isEmpty())
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        tail->set_next(head);
    }
    else
    {
        Node *temp = new Node(data);
        tail->set_next(temp);
        tail = temp;
        tail->set_next(head);
    }
}
void Circular::insertAtHead(int data)
{
    if (isEmpty())
    {
        insertAtTail(data);
    }
    else
    {
        Node *temp = new Node(data);
        temp->set_next(head);
        head = temp;
        tail->set_next(head);
    }
}
void Circular::inserAtTarget(int toFind, int data)
{
    Node *target = search(toFind);
    if (target == NULL)
    {
        cout << "\nNot Found !!!" << endl;
        return;
    }
    else if (target == head)
    {
        insertAtHead(data);
    }
    else if (target == tail)
    {
        insertAtTail(data);
    }
    else
    {
        Node *temp = new Node(data);
        temp->set_next(target->get_next());
        target->set_next(temp);
    }
}
void Circular::remove(int data)
{
    Node *targetnode = head;
    Node *previous = NULL;
    do
    {
        if (targetnode->get_data() == data)
        {
            break;
        }
        else
        {
            previous = targetnode;
            targetnode = targetnode->get_next();
        }

    } while (targetnode != head);

    if (targetnode == NULL)
    {
        cout << "\nNot Found !!!" << endl;
        return;
    }
    else if (targetnode == head)
    {
        head = head->get_next();
        targetnode->set_next(NULL);
        delete targetnode;
        tail->set_next(head);
    }
    else if (targetnode == tail)
    {
        tail = previous;
        tail->set_next(head);
        delete targetnode;
    }
    else
    {
        previous->set_next(targetnode->get_next());
        targetnode->set_next(NULL);
        delete targetnode;
    }
}
Node *Circular::search(int data)
{
    Node *temp = head;
    do
    {
        if (temp->get_data() == data)
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
void Circular::printAll()
{
    if (isEmpty())
    {
        cout << "\nList is Empty ..." << endl;
        return;
    }
    Node *temp = head;
    do
    {

        cout << temp->get_data() << endl;
        temp = temp->get_next();

    } while (temp != head);
}