#include "Node.h"

using namespace std;

Node::Node()
{
    data = -1;
    next = NULL;
}
Node::Node(int data)
{
    this->data = data;
    next = NULL;
}

int Node::get_data()
{
    return data;
}
void Node::set_data(int data)
{
    this->data = data;
}

Node *Node::get_next()
{
    return next;
}
void Node::set_next(Node *next)
{
    this->next = next;
}