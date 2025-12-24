#include "Cart.h"

using namespace std;

Cart::Cart()
{
    head = NULL;
    tail = NULL;
    itemCount = 0;
}

bool Cart::is_empty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

Item *Cart::search(int itemID)
{
    Item *temp = head;
    while (temp != NULL)
    {
        if (temp->get_itemID() == itemID)
        {
            return temp;
        }
        else
        {
            temp = temp->get_next();
        }
    }
    return NULL;
}

void Cart::addToCart(int itemID, string itemName, double price, int purchasedQuantity)
{
    Item *existing = search(itemID);
    if (existing != NULL)
    {
        cout << "\nItem already exists in cart. Adding quantity..." << endl;
        addExistingToCart(itemID, purchasedQuantity);
        return;
    }
    Item *temp = new Item();
    temp->set_itemID(itemID);
    temp->set_itemName(itemName);
    temp->set_price(price);
    temp->set_purchasedQuantity(purchasedQuantity);
    temp->calculate_total();
    if (is_empty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->set_next(temp);
        tail = temp;
    }
    itemCount++;
    cout << "\nItem added to cart successfully!" << endl;
}

void Cart::addExistingToCart(int itemID, int quantityToAdd)
{
    Item *existing = search(itemID);
    if (existing == NULL)
    {
        cout << "\nItem not found in cart!" << endl;
        return;
    }
    double newQuantity = existing->get_purchasedQuantity() + quantityToAdd;
    existing->set_purchasedQuantity(newQuantity);
    existing->calculate_total();
    cout << "\nQuantity updated successfully!" << endl;
}

void Cart::removeFromCart(int itemToRemove)
{
    if (is_empty())
    {
        cout << "\nCart is empty. Nothing to remove." << endl;
        return;
    }
    Item *target = head;
    Item *previous = NULL;
    while (target != NULL)
    {
        if (target->get_itemID() == itemToRemove)
        {
            break;
        }
        else
        {
            previous = target;
            target = target->get_next();
        }
    }
    if (target == NULL)
    {
        cout << "\nItem not found in cart!" << endl;
        return;
    }
    char confirm;
    cout << "\nAre you sure you want to remove this item? (Y/N): ";
    cin >> confirm;
    if (confirm != 'Y' && confirm != 'y')
    {
        cout << "Remove cancelled." << endl;
        return;
    }
    if (target == head)
    {
        head = target->get_next();
        target->set_next(NULL);
        delete target;
    }
    else if (target == tail)
    {
        tail = previous;
        previous->set_next(NULL);
        delete target;
    }
    else
    {
        previous->set_next(target->get_next());
        target->set_next(NULL);
        delete target;
    }
    itemCount--;
    cout << "\nItem removed successfully!" << endl;
}

void Cart::changeQuantity(int itemID, int newQuantity)
{
    if (newQuantity <= 0)
    {
        removeFromCart(itemID);
        return;
    }
    Item *target = search(itemID);
    if (target == NULL)
    {
        cout << "\nItem not found in cart!" << endl;
        return;
    }
    target->set_purchasedQuantity(newQuantity);
    target->calculate_total();
    cout << "\nQuantity changed successfully!" << endl;
}

double Cart::calculateBill()
{
    if (is_empty())
    {
        return 0.0;
    }
    double total = 0.0;
    Item *temp = head;
    while (temp != NULL)
    {
        total = total + temp->get_totalPrice();
        temp = temp->get_next();
    }
    return total;
}

void Cart::printBill()
{
    if (is_empty())
    {
        cout << "\n*********------------------***********" << endl;
        cout << "           YOUR SHOPPING CART          " << endl;
        cout << "***********------------------***********" << endl;
        cout << "\nYour cart is empty!" << endl;
        cout << "\n--------------------------------------" << endl;
        return;
    }
    cout << "\n*********------------------***********" << endl;
    cout << "           YOUR SHOPPING CART          " << endl;
    cout << "***********------------------***********" << endl;
    Item *temp = head;
    while (temp != NULL)
    {
        cout << "\nItem ID   : " << temp->get_itemID() << endl;
        cout << "Item Name : " << temp->get_itemName() << endl;
        cout << "Price     : $" << temp->get_price() << endl;
        cout << "Quantity  : " << temp->get_purchasedQuantity() << endl;
        cout << "Subtotal  : $" << temp->get_totalPrice() << endl;
        cout << "----------------------------------------" << endl;
        temp = temp->get_next();
    }
    cout << "\n--------------------------------------" << endl;
    cout << "Total Items          : " << itemCount << endl;
    cout << "Total Bill Amount    : $" << calculateBill() << endl;
    cout << "--------------------------------------" << endl;
}

void Cart::viewCart()
{
    if (is_empty())
    {
        cout << "\nYour cart is empty!" << endl;
        return;
    }
    cout << "\n--- View Cart ---" << endl;
    Item *temp = head;
    while (temp != NULL)
    {
        temp->display();
        temp = temp->get_next();
    }
}

void Cart::viewCartByItem()
{
    if (is_empty())
    {
        cout << "\nYour cart is empty!" << endl;
        return;
    }
    Item *current = head;
    while (current != NULL)
    {
        current->display();
        char option;
        cout << "\n[N]ext | [P]revious | [Q]uit: ";
        cin >> option;
        if (option == 'N' || option == 'n')
        {
            if (current->get_next() != NULL)
            {
                current = current->get_next();
            }
            else
            {
                cout << "\nThis is the last item in cart!" << endl;
            }
        }
        else if (option == 'P' || option == 'p')
        {
            Item *temp = head;
            Item *prev = NULL;
            while (temp != NULL && temp != current)
            {
                prev = temp;
                temp = temp->get_next();
            }
            if (prev != NULL)
            {
                current = prev;
            }
            else
            {
                cout << "\nThis is the first item in cart!" << endl;
            }
        }
        else if (option == 'Q' || option == 'q')
        {
            break;
        }
        else
        {
            cout << "\nInvalid option!" << endl;
        }
    }
}
