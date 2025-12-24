#include "Item.h"

using namespace std;

Item::Item()
{
    itemID = -1;
    itemName = "";
    price = 0.0;
    purchasedQuantity = 0.0;
    totalPrice = 0.0;
    next = NULL;
}

Item::Item(Item &item)
{
    itemID = item.itemID;
    itemName = item.itemName;
    price = item.price;
    purchasedQuantity = item.purchasedQuantity;
    totalPrice = item.totalPrice;
    next = NULL;
}

int Item::get_itemID()
{
    return itemID;
}

void Item::set_itemID(int id)
{
    itemID = id;
}

string Item::get_itemName()
{
    return itemName;
}

void Item::set_itemName(string name)
{
    itemName = name;
}

double Item::get_price()
{
    return price;
}

void Item::set_price(double p)
{
    price = p;
}

double Item::get_purchasedQuantity()
{
    return purchasedQuantity;
}

void Item::set_purchasedQuantity(double quantity)
{
    purchasedQuantity = quantity;
}

double Item::get_totalPrice()
{
    return totalPrice;
}

void Item::set_totalPrice(double total)
{
    totalPrice = total;
}

Item *Item::get_next()
{
    return next;
}

void Item::set_next(Item *nxt)
{
    next = nxt;
}

void Item::calculate_total()
{
    totalPrice = price * purchasedQuantity;
}

void Item::display()
{
    cout << "----------------------------------------" << endl;
    cout << "Item ID              : " << itemID << endl;
    cout << "Item Name            : " << itemName << endl;
    cout << "Price per Unit       : $" << price << endl;
    cout << "Purchased Quantity   : " << purchasedQuantity << endl;
    cout << "Total Price          : $" << totalPrice << endl;
    cout << "----------------------------------------" << endl;
}
