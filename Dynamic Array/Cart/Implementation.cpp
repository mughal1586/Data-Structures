#include "ShoppingCart.h"
using namespace std;

Product::Product()
{
    id = 0;
    name = "";
}

Product::Product(int id, string name)
{
    this->id = id;
    this->name = name;
}

int Product::get_id()
{
    return id;
}

void Product::set_id(int id)
{
    this->id = id;
}

string Product::get_name()
{
    return name;
}

void Product::set_name(string name)
{
    this->name = name;
}

ShoppingCart::ShoppingCart(int capacity)
{
    this->capacity = capacity;
    products = new Product[capacity];
    size = 0;
}

int ShoppingCart::get_capacity()
{
    return capacity;
}
void ShoppingCart::set_capacity(int capacity)
{
    this->capacity = capacity;
}
int ShoppingCart::get_size()
{
    return size;
}
void ShoppingCart::set_size(int)
{
    this->size = size;
}

void ShoppingCart::add_product(int id, string name)
{
    if (size == capacity)
    {
        resize();
    }
    products[size] = Product(id, name);
    size++;
}
void ShoppingCart::remove_product(int id)
{
    int index = search_product(id);
    if (index == -1)
    {
        cout << "Not found !!!" << endl;
    }
    else
    {
        products[index].set_id(-1);
        products[index].set_name("");
        shift(index);
        size--;
    }
}
int ShoppingCart::search_product(int id)
{
    for (int i = 0; i < size; i++)
    {
        if (products[i].get_id() == id)
        {
            return i;
        }
    }
    return -1;
}
void ShoppingCart::resize()
{
    capacity = capacity * 2;
    Product *newproducts = new Product[capacity];
    for (int i = 0; i < size; i++)
    {
        newproducts[i] = products[i];
    }
    delete[] products;
    products = newproducts;
}
void ShoppingCart::shift(int index)
{
    for (int i = index; i < size - 1; i++)
    {
        products[i].set_id(products[i + 1].get_id());
        products[i].set_name(products[i + 1].get_name());
    }
}
void ShoppingCart::display()
{
    if (size == 0)
    {
        cout << "The cart is empty." << endl;
    }
    else
    {
        cout << "\n****** -- Cart Contents -- ******" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "ID: " << products[i].get_id() << ", Name: " << products[i].get_name() << endl;
        }
    }
}
void ShoppingCart::clear_cart()
{
    size = 0;
    capacity = 2;
    delete[] products;
    products = new Product[capacity];
}