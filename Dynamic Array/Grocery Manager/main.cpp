#include"Grocery.h"
using namespace std;

int main(){
    GroceryList g1(3);

    g1.insert("Milk");
    g1.insert("Bread");
    g1.insert("Egg");

    g1.insert("Butter");
    g1.insert("Jam");
    g1.insert("Meat");
    g1.insert("Flour");

    g1.display();

    return 0;
}