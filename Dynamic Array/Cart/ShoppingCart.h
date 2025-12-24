#include "Product.h"

using namespace std;

class ShoppingCart
{
private:
    int capacity;
    int size;
    Product *products;

public:
    ShoppingCart(int);

    int get_capacity();
    void set_capacity(int);
    int get_size();
    void set_size(int);

    void add_product(int, string);
    void remove_product(int);
    int search_product(int);
    void resize();
    void shift(int);
    void display();
    void clear_cart();
};