#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class ShoppingCart {
private:
    vector<string> items;
    vector<double> prices;
    double total;

public:
    ShoppingCart() {
        total = 0;
    }

    void addItem(string item, double price) {
        items.push_back(item);
        prices.push_back(price);
        total += price;
        cout << item << " added to cart. Price: $" << price << endl;
    }

    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            cout << items[index] << " removed from cart.\n";
            total -= prices[index];
            items.erase(items.begin() + index);
            prices.erase(prices.begin() + index);
        }
        else {
            cout << "Invalid index!\n";
        }
    }

    void showCart() {
        cout << "\n--- Your Shopping Cart ---\n";
        if (items.empty()) {
            cout << "Cart is empty.\n";
        }
        else {
            for (int i = 0; i < items.size(); i++) {
                cout << i + 1 << ". " << items[i] << " - $" << fixed << setprecision(2) << prices[i] << endl;
            }
        }
        cout << "Total Bill: $" << fixed << setprecision(2) << total << endl;
    }

    void applyDiscount() {
        if (total >= 50) {
            double discount = total * 0.10;
            total -= discount;
            cout << "10% Discount Applied! New Total: $" << fixed << setprecision(2) << total << endl;
        }
        else {
            cout << "No discount applied. Spend $50+ for 10% discount.\n";
        }
    }
};

int main() {
    ShoppingCart cart;
    string name;
    int choice;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Welcome, " << name << "! Start shopping.\n";

    do {
        cout << "\n1. Add Item\n2. Remove Item\n3. View Cart\n4. Apply Discount\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string item;
            double price;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, item);
            cout << "Enter item price: ";
            cin >> price;
            cart.addItem(item, price);
            break;
        }
        case 2: {
            int index;
            cart.showCart();
            cout << "Enter item number to remove: ";
            cin >> index;
            cart.removeItem(index - 1);
            break;
        }
        case 3:
            cart.showCart();
            break;
        case 4:
            cart.applyDiscount();
            break;
        case 5:
            cout << "Thank you for shopping, " << name << "! Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
