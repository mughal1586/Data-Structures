#include "Stack.h"

using namespace std;

Stack::Stack(){
    top = -1;
}
bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}
bool Stack::isFull(){
    if(top == 99){
        return true;
    }
    return false;
}
void Stack::push(int data){
    if(isFull()){
        cout<<"Stack Overflow !!!\nCan't push node"<<endl;
    }
    else{
        top++;
        arr[top].set_data(data);
        cout<<data<<" pushed to stack"<<endl;
    }
}
void Stack::pop(){
    if(isEmpty()){
        cout<<"Stack Underflow !!!\nCan't pop node"<<endl;
    }
    else{
        cout<<arr[top].get_data()<<" popped from stack"<<endl;
        arr[top].set_data(-1);
        top --;
    }
}
void Stack::display(){
    if(isEmpty()){
        cout<<"Stack is Empty ..."<<endl;
    }
    else{
        for(int i=top; i>=0; i--){
            cout<<arr[i].get_data()<<endl;
        }
    }
}
int Stack::search(int data){
    if(isEmpty()){
        cout<<"Stack is Empty ..."<<endl;
        return -1;
    }
    else{
        for(int i=top; i>=0; i--){
            if(arr[i].get_data() == data){
                return i;
            }
        }
    }
    return -1;
}
