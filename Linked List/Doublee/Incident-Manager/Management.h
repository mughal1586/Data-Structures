#include "Node.h"

using namespace std;

class Management
{
private:
    Node *head;
    Node *tail;

public:
    Management();

    void insertAtHead(Node &);
    void insertAtTail(Node &);
    void insertAtTarget(Node &, Node &);
    void remove_incident(int);

    void highest_severity(string, string);
    Node *get_tail();

    Node *search(int);
    bool isEmpty();
    void printAll();
    void printReverse();
};
