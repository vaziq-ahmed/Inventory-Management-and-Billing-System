#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Stock {
    string name;
    int price;
    int code;
    int qty;
};

struct Details {
    string name;
    int price;
    int code;
    int qnty;
};

vector<Stock> items;
vector<Details> things;

void viewMenu();
void purchase();
void login();
void printBill(int itemCount);

int main() {
    login();
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "\t available products\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    viewMenu();
    purchase();
    return 0;
}

void login() {
    int attempts = 0;
    string uname, pword;
    const string user1 = "lab";
    const string pass1 = "123";
    const string user2 = "vaz";
    const string pass2 = "444";

    while (attempts < 3) {
        cout << "\n++++++++++++++++++++++++++++++  LOGIN PORTAL  ++++++++++++++++++++++++++++++\n";
        cout << "\nENTER USERNAME: ";
        cin >> uname;
        cout << "\nENTER PASSWORD: ";
        cin >> pword;

        if ((uname == user1 && pword == pass1) || (uname == user2 && pword == pass2)) {
            cout << "\n\nWELCOME TO ABC MART\n";
            cout << "\nPress any key to continue...\n";
            cin.get();  // to hold the screen
            cin.get();
            break;
        } else {
            cout << "\nSORRY !!!!  LOGIN IS UNSUCCESSFUL\n";
            attempts++;
        }

        if (attempts == 3) {
            cout << "\nSorry you have entered the wrong username and password for three times!!!\n";
            exit(0);
        }
    }
}

void viewMenu() {
    items = {
        {"Apples", 50, 0, 0}, {"Bananas", 30, 1, 0}, {"Chocolates", 20, 2, 0},
        {"Milkshake", 30, 3, 0}, {"Coffee", 20, 4, 0}, {"Coke", 20, 5, 0},
        {"Potato chips", 30, 6, 0}, {"Ice creams", 20, 7, 0}, {"Rice", 50, 8, 0},
        {"Sugar", 30, 9, 0}, {"Salt", 20, 10, 0}, {"Green gram", 30, 11, 0},
        {"Chilly powder", 20, 12, 0}, {"Maggie", 20, 13, 0}, {"Tomato sauce", 30, 14, 0},
        {"Shampoo", 20, 15, 0}, {"Sandal soap", 50, 16, 0}, {"Soap (Dove)", 30, 17, 0},
        {"Butter", 20, 18, 0}, {"Cheese", 20, 19, 0}, {"Rava", 20, 20, 0},
        {"Biscuit", 20, 21, 0}, {"Lays", 20, 22, 0}, {"Detergent", 30, 23, 0},
        {"Books (100 pages)", 20, 24, 0}, {"Pen (5 piece)", 20, 25, 0}
    };

    cout << "             *  INVENTORY * \n";
    cout << "-------------------------------------------------------------\n";
    cout << "S.N.|    NAME               |  PRICE  |   CODE                 \n";
    cout << "-------------------------------------------------------------\n";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << setw(2) << i + 1 << "     " << setw(16) << items[i].name 
             << "        " << setw(2) << items[i].price 
             << "          " << items[i].code << "\n";
    }
}

void purchase() {
    int itemCount;
    float total = 0;
    float finalTotal = 0;

    cout << "Please choose the things you want to add to your shopping list from the above..\n\n\n";
    cout << "Enter the number of things you want to buy: ";
    cin >> itemCount;

    for (int i = 0; i < itemCount; ++i) {
        int code, qty;
        cout << "Please enter the " << i + 1 << "th item code and the quantity of the item you want to buy: ";
        cin >> code >> qty;

        if (code >= items.size()) {
            cout << "You have entered wrong code of the item. Please enter the right code\n";
            --i;
            continue;
        }

        cout << "You have chosen " << qty << " amount of " << items[code].name 
             << " which costs " << items[code].price * qty << "\n\n";

        things.push_back({items[code].name, items[code].price * qty, items[code].code, qty});
        total += items[code].price * qty;
    }

    finalTotal = total + (total * 0.09);
    cout << "-------------------------------------------------------------\n";
    cout << "S.N.|    NAME           | QUANTITY |  PRICE  |  \n";
    cout << "-------------------------------------------------------------\n";
    for (size_t i = 0; i < things.size(); ++i) {
        cout << setw(2) << i + 1 << "     " << setw(15) << things[i].name 
             << "        " << setw(2) << things[i].qnty 
             << "        " << setw(5) << things[i].price << "\n";
    }

    cout << "-------------------------------------------------------------\n";
    cout << "Total--------------------------------- " << fixed << setprecision(2) << total << " ----\n\n\n";
    cout << "The tax percentage is 9 (including GST)\n";
    cout << "The tax amount is " << fixed << setprecision(2) << (total * 0.09) << "\n\n";
    cout << "Final total---------------------------- " << finalTotal << " ----\n\n\n";

    float amountPaid;
    cout << "Please enter the amount you are paying: ";
    cin >> amountPaid;

    if (amountPaid > finalTotal) {
        cout << "Please collect the change of " << fixed << setprecision(2) << (amountPaid - finalTotal) << "\n\n\n";
    } else if (amountPaid < finalTotal) {
        cout << "You have paid " << fixed << setprecision(2) << (finalTotal - amountPaid) 
             << " rupees less than the total amount. Please pay the due amount \n\n";
    }

    cout << "------------------Thank you for purchasing. Please visit again and have a nice day--------\n\n";
    printBill(itemCount);
}

void printBill(int itemCount) {
    ofstream file("vaziq.txt");

    if (!file) {
        cerr << "Error in writing to file!";
        return;
    }

    float total = 0;
    file << "-------------------------------------------------------------\n";
    file << "S.N.|    NAME           | QUANTITY |  PRICE  |  \n";
    file << "-------------------------------------------------------------\n";

    for (int i = 0; i < itemCount; ++i) {
        file << setw(2) << i + 1 << "     " << setw(15) << things[i].name 
             << "        " << setw(2) << things[i].qnty 
             << "        " << setw(5) << things[i].price << "\n";
        total += things[i].price;
    }

    file << "-------------------------------------------------------------\n";
    file << "Total--------------------------------- " << fixed << setprecision(2) << total << " ----\n\n\n";
    file << "The tax percentage is 9 (including GST)\n";
    file << "The tax amount is " << fixed << setprecision(2) << (total * 0.09) << "\n\n";
    float finalTotal = total + (total * 0.09);
    file << "Final total---------------------------- " << finalTotal << " ----\n\n\n";

    cout << "The bill is generated!";
}