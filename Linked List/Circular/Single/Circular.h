#include "Node.h"

using namespace std;

class Circular
{
private:
    Node *head;
    Node *tail;

public:
    Circular();

    bool isEmpty();
    void insertAtTail(int);
    void insertAtHead(int);
    void inserAtTarget(int, int);
    void remove(int);
    Node *search(int);
    void printAll();
};