#include "ShoppingCart.h"
using namespace std;

int main()
{
    ShoppingCart cart(2);

    cart.add_product(101, "Laptop");
    cart.add_product(102, "Mouse");
    cart.display();

    cart.add_product(103, "Keyboard");
    cart.display();

    cart.remove_product(102);
    cart.display();

    cart.add_product(104, "Headphones");
    cart.add_product(105, "USB Drive");
    cart.add_product(106, "Monitor");
    cart.display();

    cart.clear_cart();
    cart.display();

    return 0;
}