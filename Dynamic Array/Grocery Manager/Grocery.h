#include<iostream>
using namespace std;

class GroceryList{
private:

int capacity;
int size;
string* items;

public:
/**************************************************** -- Constructor --  ****************************************************/
GroceryList(int);
/**************************************************** -- Getter/Setter --  ****************************************************/
int get_capacity();
void set_capacity(int);
int get_size();
void set_size(int);
/**************************************************** -- Others --  ****************************************************/
void insert(string);
void resize();
void display();

};