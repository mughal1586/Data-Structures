#include "Node.h"

using namespace std;

class Stack{
private:
    Node arr[100];
    int top;
public:
    Stack();

    bool isEmpty();
    bool isFull();

    void push(int);
    void pop();
    void display();

    int search(int);
};
