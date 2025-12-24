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
    int getdata();
    void setdata(int);
    Node *getnext();
    void setnext(Node *);
};