#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}
void LinkedList::insertAttail(int data)
{
    if (isEmpty())
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->setnext(temp);
        tail = temp;
    }
}
void LinkedList::insertAthead(int data)
{
    if (isEmpty())
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->setnext(head);
        head = temp;
    }
}
void LinkedList::insertAttarget(int toFind, int value)
{
    Node *target = search(toFind);
    if (target == NULL)
    {
        cout << "Not Found !!!" << endl;
        return;
    }
    else
    {
        if (target == tail)
        {
            insertAttail(value);
        }
        else
        {
            Node *temp = new Node(value);
            temp->setnext(target->getnext());
            target->setnext(temp);
        }
    }
}
void LinkedList::remove(int targetvalue)
{
    Node *targetnode = head;
    Node *previous = NULL;
    while (targetnode != NULL)
    {
        if (targetnode->getdata() == targetvalue)
        {
            break;
        }
        else
        {
            previous = targetnode;
            targetnode = targetnode->getnext();
        }
    }
    if (targetnode == NULL)
    {
        cout << "Not Found !!!" << endl;
    }
    else if (targetnode == head)
    {
        head = targetnode->getnext();
        targetnode->setnext(NULL);
        delete targetnode;
    }
    else if (targetnode == tail)
    {
        previous->setnext(NULL);
        tail = previous;
        delete targetnode;
    }
    else
    {
        previous->setnext(targetnode->getnext());
        targetnode->setnext(NULL);
        delete targetnode;
    }
}
bool LinkedList::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }

    return false;
}
Node *LinkedList::search(int toSearch)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->getdata() == toSearch)
        {
            return temp;
        }
        else
        {
            temp = temp->getnext();
        }
    }
    return NULL;
}
void LinkedList::printAll()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->getdata() << endl;
        temp = temp->getnext();
    }
}