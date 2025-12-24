#include "Node.h"

using namespace std;

class DoubleC
{
private:
    Node *head;
    Node *tail;

public:
    DoubleC();

    bool isEmpty();
    void insertAttail(int);
    void insertAtHead(int);
    void insertAtTarget(int, int);
    void remove(int);
    Node *search(int);
    void printAll();
    void print_reverse();
};