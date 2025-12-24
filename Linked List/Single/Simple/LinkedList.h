#include "Node.h"
using namespace std;

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    void insertAttail(int);
    void insertAthead(int);
    void insertAttarget(int, int);
    void remove(int);
    bool isEmpty();
    void printAll();
    Node *search(int);
};