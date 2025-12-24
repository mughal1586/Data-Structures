#include "Grocery.h"
using namespace std;

/**************************************************** -- Constructor --  ****************************************************/
GroceryList::GroceryList(int capacity) {
    this->capacity = capacity;
    size = 0;
    items = new string[capacity];
}

/**************************************************** -- Getter/Setter --  ****************************************************/
int GroceryList::get_capacity() {
    return capacity;
}

void GroceryList::set_capacity(int capacity) {
    this->capacity = capacity;
}

int GroceryList::get_size() {
    return size;
}

void GroceryList::set_size(int size) {
    this->size = size;
}

/**************************************************** -- Others --  ****************************************************/
void GroceryList::insert(string name) {
    if (size == capacity) {
        resize();
    }
    items[size] = name;
    size++;
}

void GroceryList::resize() {
    capacity *= 2;
    string* newitems = new string[capacity];
    for (int i = 0; i < size; i++) {
        newitems[i] = items[i];
    }
    delete[] items;
    items = newitems;
}

void GroceryList::display() {
    cout << "\n******** -- Grocery List -- ********" << endl;
    for (int i = 0; i < size; i++) {
        cout << items[i] << endl;
    }
}
