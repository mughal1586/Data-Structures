#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *previous;

public:
    Node();
    Node(int);

    int get_data();
    void set_data(int);

    Node *get_next();
    void set_next(Node *);

    Node *get_previous();
    void set_previous(Node *);
};