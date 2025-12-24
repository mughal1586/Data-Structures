#include "Node.h"

using namespace std;

class Queue{
private:
    Node *front;
    Node *rear;
public:
    Queue();

    bool isEmpty();
    void enqueue(int);
    void dequeue();
    Node* search(int);
    void printAll();
};
