#include "DoubleeLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
}

bool DoubleLinkedList::is_empty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
void DoubleLinkedList::insertAtTail(int data)
{
    if (is_empty())
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->set_next(temp);
        temp->set_previous(tail);
        tail = temp;
    }
}
void DoubleLinkedList::insertAtHead(int data)
{
    if (is_empty())
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->set_next(head);
        head->set_previous(temp);
        head = temp;
    }
}
void DoubleLinkedList::insertAtTarget(int toSearch, int data)
{
    Node *target = search(toSearch);
    if (target == NULL)
    {
        cout << "\nTarget not Found !!!" << endl;
        return;
    }
    else if (target == head)
    {
        insertAtHead(data);
    }
    else
    {
        Node *temp = new Node(data);
        Node *previous = target->get_previous();

        target->set_previous(temp);   // Set temp address to target's previous      Connection : (Target ---> Temp)
        previous->set_next(temp);     // Set temp address to previous block's next   Connection : (Previous ---> Temp)
        temp->set_previous(previous); // Set previous address to temp's previous              Connection : (Temp ---> Previous)
        temp->set_next(target);       // Set target address to temp's next              Connection : (Temp ---> Target)
    }
}
void DoubleLinkedList::remove(int target)
{
    Node *targetNode = search(target);
    if (targetNode == NULL)
    {
        cout << "\nNot found !!!" << endl;
        return;
    }
    else if (targetNode == head)
    {
        head = head->get_next();
        head->set_previous(NULL);
        targetNode->set_next(NULL);
        delete targetNode;
    }
    else if (targetNode == tail)
    {
        tail = tail->get_previous();
        tail->set_next(NULL);
        targetNode->set_previous(NULL);
        delete targetNode;
    }
    else
    {
        Node *prev = targetNode->get_previous();
        Node *next = targetNode->get_next();

        prev->set_next(next);
        next->set_previous(prev);
        targetNode->set_next(NULL);
        targetNode->set_previous(NULL);

        delete targetNode;
    }
}
Node *DoubleLinkedList::search(int data)
{
    Node *temp = head;
    while (head != NULL)
    {
        if (temp->get_data() == data)
        {
            return temp;
        }
        else
        {
            temp = temp->get_next();
        }
    }
    return NULL;
}
void DoubleLinkedList::printAll()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->get_data() << endl;
        temp = temp->get_next();
    }
}
void DoubleLinkedList::printReverse()
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->get_data() << endl;
        temp = temp->get_previous();
    }
}
