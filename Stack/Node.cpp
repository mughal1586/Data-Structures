#include "Node.h"

using namespace std;

Node::Node(){
    data = -1;
}
Node::Node(int data){
    this->data = data;
}
int Node::get_data(){
    return data;
}
void Node::set_data(int data){
    this->data = data;
}
