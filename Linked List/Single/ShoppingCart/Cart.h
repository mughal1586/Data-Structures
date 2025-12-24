#include "Item.h"

using namespace std;

class Cart
{
private:
    Item *head;
    Item *tail;
    int itemCount;

public:
    Cart();
    void addToCart(int, string, double, int);
    void addExistingToCart(int, int);
    void removeFromCart(int);
    void changeQuantity(int, int);
    double calculateBill();
    void printBill();
    void viewCartByItem();
    void viewCart();
    bool is_empty();
    Item *search(int);
};
