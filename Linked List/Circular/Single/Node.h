#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node();
    Node(int);

    int get_data();
    void set_data(int);

    Node *get_next();
    void set_next(Node *);
};