#include "Cart.h"

using namespace std;

int main()
{
    Cart myCart;
    int choice;
    do
    {
        cout << "\n********** -- Shopping Cart Menu -- **********" << endl;
        cout << "1. Add Item to Cart" << endl;
        cout << "2. Remove Item from Cart" << endl;
        cout << "3. Change Item Quantity" << endl;
        cout << "4. View Cart" << endl;
        cout << "5. View Cart by Item" << endl;
        cout << "6. Calculate Bill" << endl;
        cout << "7. Print Bill" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int itemID;
            string itemName;
            double price;
            int quantity;
            cout << "\nEnter Item ID: ";
            cin >> itemID;
            cout << "Enter Item Name: ";
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter Price: $";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> quantity;
            myCart.addToCart(itemID, itemName, price, quantity);
            break;
        }
        case 2:
        {
            int itemID;
            cout << "\nEnter Item ID to remove: ";
            cin >> itemID;
            myCart.removeFromCart(itemID);
            break;
        }
        case 3:
        {
            int itemID, newQuantity;
            cout << "\nEnter Item ID: ";
            cin >> itemID;
            cout << "Enter new Quantity (0 to remove): ";
            cin >> newQuantity;
            myCart.changeQuantity(itemID, newQuantity);
            break;
        }
        case 4:
        {
            myCart.viewCart();
            break;
        }
        case 5:
        {
            myCart.viewCartByItem();
            break;
        }
        case 6:
        {
            double total = myCart.calculateBill();
            cout << "\nTotal Bill: $" << total << endl;
            break;
        }
        case 7:
        {
            myCart.printBill();
            break;
        }
        case 0:
            cout << "\nExiting Program..." << endl;
            break;
        default:
            cout << "\nInvalid choice !!! \nTry again." << endl;
        }
    } while (choice != 0);
    return 0;
}
