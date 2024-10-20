#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Product class encapsulating item details
class Product {
private:
    string name;
    int price;
    int code;
public:
    Product(string n, int p, int c) : name(n), price(p), code(c) {}

    // Getters for product details
    string getName() const { return name; }
    int getPrice() const { return price; }
    int getCode() const { return code; }
};

// CartItem class for managing selected products
class CartItem {
private:
    Product product;
    int quantity;

public:
    CartItem(const Product& prod, int qty) : product(prod), quantity(qty) {}

    // Calculate price of the item based on quantity
    int getTotalPrice() const { return product.getPrice() * quantity; }

    // Display item details in the bill
    void displayItem(int serialNumber) const {
        cout << setw(2) << serialNumber << "     " << setw(15) << product.getName()
             << "        " << setw(2) << quantity << "        " << setw(5) << getTotalPrice() << "\n";
    }

    // Save item details to file
    void saveToFile(ofstream& file, int serialNumber) const {
        file << setw(2) << serialNumber << "     " << setw(15) << product.getName()
             << "        " << setw(2) << quantity << "        " << setw(5) << getTotalPrice() << "\n";
    }
};

// Shop class managing inventory and purchases
class Shop {
private:
    vector<Product> products;
    vector<CartItem> cart;
    const float taxRate = 0.09;

public:
    Shop() {
        // Initialize available products
        products = {
            {"Apples", 50, 0}, {"Bananas", 30, 1}, {"Chocolates", 20, 2},
            {"Milkshake", 30, 3}, {"Coffee", 20, 4}, {"Coke", 20, 5},
            {"Potato chips", 30, 6}, {"Ice creams", 20, 7}, {"Rice", 50, 8},
            {"Sugar", 30, 9}, {"Salt", 20, 10}, {"Green gram", 30, 11},
            {"Chilly powder", 20, 12}, {"Maggie", 20, 13}, {"Tomato sauce", 30, 14},
            {"Shampoo", 20, 15}, {"Sandal soap", 50, 16}, {"Soap (Dove)", 30, 17},
            {"Butter", 20, 18}, {"Cheese", 20, 19}, {"Rava", 20, 20},
            {"Biscuit", 20, 21}, {"Lays", 20, 22}, {"Detergent", 30, 23},
            {"Books (100 pages)", 20, 24}, {"Pen (5 piece)", 20, 25}
        };
    }

    // Display available products
    void displayProducts() const {
        cout << "             *  INVENTORY * \n";
        cout << "-------------------------------------------------------------\n";
        cout << "S.N.|    NAME               |  PRICE  |   CODE                 \n";
        cout << "-------------------------------------------------------------\n";
        for (size_t i = 0; i < products.size(); ++i) {
            cout << setw(2) << i + 1 << "     " << setw(16) << products[i].getName()
                 << "        " << setw(2) << products[i].getPrice()
                 << "          " << products[i].getCode() << "\n";
        }
    }

    // Add item to the cart
    void addToCart(int code, int qty) {
        if (code >= products.size()) {
            cout << "You have entered an incorrect code. Please try again.\n";
            return;
        }

        cart.emplace_back(products[code], qty);
        cout << "You have added " << qty << " units of " << products[code].getName()
             << " costing " << products[code].getPrice() * qty << " to the cart.\n";
    }

    // Calculate total price
    float calculateTotal() const {
        float total = 0;
        for (const auto& item : cart) {
            total += item.getTotalPrice();
        }
        return total;
    }

    // Display the final bill
    void displayBill() const {
        float total = calculateTotal();
        float tax = total * taxRate;
        float finalTotal = total + tax;

        cout << "-------------------------------------------------------------\n";
        cout << "S.N.|    NAME           | QUANTITY |  PRICE  |  \n";
        cout << "-------------------------------------------------------------\n";
        for (size_t i = 0; i < cart.size(); ++i) {
            cart[i].displayItem(i + 1);
        }

        cout << "-------------------------------------------------------------\n";
        cout << "Total--------------------------------- " << fixed << setprecision(2) << total << " ----\n";
        cout << "The tax percentage is " << taxRate * 100 << "% (including GST)\n";
        cout << "The tax amount is " << fixed << setprecision(2) << tax << "\n";
        cout << "Final total---------------------------- " << fixed << setprecision(2) << finalTotal << " ----\n";
    }

    // Save the bill to a file
    void saveBillToFile() const {
        ofstream file("smartcart_bill.txt");

        if (!file) {
            cerr << "Error in writing to file!";
            return;
        }

        float total = calculateTotal();
        float tax = total * taxRate;
        float finalTotal = total + tax;

        file << "-------------------------------------------------------------\n";
        file << "S.N.|    NAME           | QUANTITY |  PRICE  |  \n";
        file << "-------------------------------------------------------------\n";
        for (size_t i = 0; i < cart.size(); ++i) {
            cart[i].saveToFile(file, i + 1);
        }

        file << "-------------------------------------------------------------\n";
        file << "Total--------------------------------- " << fixed << setprecision(2) << total << " ----\n";
        file << "The tax percentage is " << taxRate * 100 << "% (including GST)\n";
        file << "The tax amount is " << fixed << setprecision(2) << tax << "\n";
        file << "Final total---------------------------- " << fixed << setprecision(2) << finalTotal << " ----\n";
        
        cout << "The bill has been saved to 'smartcart_bill.txt'.\n";
    }
};

// Login class for handling user authentication
class Login {
public:
    void authenticate() {
        int attempts = 0;
        string uname, pword;
        const string user1 = "lab";
        const string pass1 = "123";
        const string user2 = "dan";
        const string pass2 = "333";

        while (attempts < 3) {
            cout << "\n++++++++++++++++++++++++++++++  LOGIN PORTAL  ++++++++++++++++++++++++++++++\n";
            cout << "\nENTER USERNAME: ";
            cin >> uname;
            cout << "\nENTER PASSWORD: ";
            cin >> pword;

            if ((uname == user1 && pword == pass1) || (uname == user2 && pword == pass2)) {
                cout << "\n\nWELCOME TO SmartCart\n";
                cout << "\nPress any key to continue...\n";
                cin.get();
                cin.get();
                break;
            } else {
                cout << "\nSORRY !!!!  LOGIN IS UNSUCCESSFUL\n";
                attempts++;
            }

            if (attempts == 3) {
                cout << "\nSorry you have entered the wrong username and password three times!!!\n";
                exit(0);
            }
        }
    }
};

int main() {
    Login login;
    login.authenticate();

    Shop shop;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "\t Available Products\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    shop.displayProducts();

    int itemCount;
    cout << "\nHow many items would you like to purchase? ";
    cin >> itemCount;

    for (int i = 0; i < itemCount; ++i) {
        int code, qty;
        cout << "Enter the product code and quantity for item " << i + 1 << ": ";
        cin >> code >> qty;
        shop.addToCart(code, qty);
    }

    shop.displayBill();
    shop.saveBillToFile();

    return 0;
}
