# Inventory-Management-and-Billing-System
## Overview

SmartCart is a simple console-based shopping cart application written in C++. It allows users to login, view available products, add items to a cart, and generate a bill. The system applies a tax rate on the final amount and saves the bill to a file for record-keeping. The project incorporates Object-Oriented Programming (OOP) concepts to manage products, the shopping cart, billing, and user authentication.

## Features

- User login with basic authentication.
- Product inventory listing with prices and codes.
- Ability to select multiple items for purchase.
- Automated calculation of total price, including tax.
- Bill generation with an option to save the bill to a file.
- Error handling for invalid product codes or insufficient payment.

## Technologies

- **C++**
- **Object-Oriented Programming (OOP)**

## Structure

### Classes

1. **`Product`**: Represents individual products available for purchase.
   - Attributes: `name`, `price`, `code`
   - Methods: Getters for product details.

2. **`CartItem`**: Manages products added to the cart and calculates total price.
   - Attributes: `product`, `quantity`
   - Methods: Calculates total price and displays/saves item details.

3. **`Shop`**: Manages the inventory, shopping process, and billing.
   - Methods: Displays products, adds items to cart, generates bill, saves bill to file.

4. **`Login`**: Handles user authentication with predefined usernames and passwords.
   - Methods: User login with a maximum of three attempts.

## How to Run

### Prerequisites

- A C++ compiler (e.g., `g++` or any IDE that supports C++)
- Basic knowledge of running console applications

### Compilation and Execution

1. Clone or download the project files.
2. Open a terminal or command prompt in the project directory.
3. Compile the code using the following command (if using `g++`):

   ```bash
   g++ -o SmartCart main.cpp



## Sample bill
-------------------------------------------------------------
S.N.|    NAME           | QUANTITY |  PRICE  |  
-------------------------------------------------------------
1     Apples            2         100
2     Coffee            3         60
-------------------------------------------------------------
Total--------------------------------- 160 ----
The tax percentage is 9 (including GST)
The tax amount is 14.40
Final total---------------------------- 174.40 ----
