#include "Queue.h"

using namespace std;

    Queue::Queue(){
        front=NULL;
        rear=NULL;
    }

    bool Queue::isEmpty(){
    if(front==NULL){
        return true;
    }
    return false;
    }

    void Queue::enqueue(int data){
        if(isEmpty()){
            Node *temp=new Node(data);
            front=temp;
            rear=temp;
        }
        else{
            Node *temp=new Node(data);
            rear->set_next(temp);
            rear=temp;
        }
    }

    void Queue::dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty !!!"<<endl;
        }
        else{
            Node *temp=front;
            front=front->get_next();

            if (front == NULL){
                rear = NULL;
            }

            delete temp;
        }
    }

    Node* Queue::search(int data){
        Node *temp=front;
        while(temp !=NULL){
            if(temp->get_data() == data){
                return temp;
            }
            else{
                temp = temp->get_next();
            }
        }
        return NULL;
    }

    void Queue::printAll(){
        Node *temp=front;
        if(isEmpty()){
            cout<<"Queue is empty !!!"<<endl;
        }
        else{
        while(temp !=NULL){
                cout<<temp->get_data()<<endl;
                temp = temp->get_next();
            }
        }
    }
