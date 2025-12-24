#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    int itemID;
    string itemName;
    double price;
    double purchasedQuantity;
    double totalPrice;
    Item *next;

public:
    Item();
    Item(Item &);

    int get_itemID();
    void set_itemID(int);
    string get_itemName();
    void set_itemName(string);
    double get_price();
    void set_price(double);
    double get_purchasedQuantity();
    void set_purchasedQuantity(double);
    double get_totalPrice();
    void set_totalPrice(double);
    Item *get_next();
    void set_next(Item *);
    void calculate_total();

    void display();
};
