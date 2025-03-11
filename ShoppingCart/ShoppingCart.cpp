#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class ShoppingCart {
private:
    vector<string> items;
    vector<double> prices;
    double total;
    const string filename = "cart_data.txt";

public:
    ShoppingCart() {
        total = 0;
        loadCart();
    }

    void addItem(string item, double price) {
        items.push_back(item);
        prices.push_back(price);
        total += price;
        cout << item << " added to cart. Price: $" << price << endl;
        saveCart();
    }

    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            cout << items[index] << " removed from cart.\n";
            total -= prices[index];
            items.erase(items.begin() + index);
            prices.erase(prices.begin() + index);
            saveCart();
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
            saveCart();
        }
        else {
            cout << "No discount applied. Spend $50+ for 10% discount.\n";
        }
    }

    void checkout() {
        if (items.empty()) {
            cout << "Your cart is empty. Add items before checkout.\n";
            return;
        }
        cout << "\nProceeding to checkout...\n";
        showCart();
        cout << "Thank you for your purchase! Your order has been placed.\n";
        items.clear();
        prices.clear();
        total = 0;
        saveCart();
    }

    void saveCart() {
        ofstream file(filename);
        if (file.is_open()) {
            file << total << endl;
            for (size_t i = 0; i < items.size(); i++) {
                file << items[i] << "," << prices[i] << endl;
            }
            file.close();
        }
    }

    void loadCart() {
        ifstream file(filename);
        if (file.is_open()) {
            items.clear();
            prices.clear();
            file >> total;
            file.ignore(); // Ignore newline
            string line;
            while (getline(file, line)) {
                size_t commaPos = line.find(',');
                if (commaPos != string::npos) {
                    string item = line.substr(0, commaPos);
                    double price = stod(line.substr(commaPos + 1));
                    items.push_back(item);
                    prices.push_back(price);
                }
            }
            file.close();
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
        cout << "\n1. Add Item\n2. Remove Item\n3. View Cart\n4. Apply Discount\n5. Checkout\n6. Exit\nEnter choice: ";
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
            cart.checkout();
            break;
        case 6:
            cout << "Thank you for shopping, " << name << "! Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
