
# Supermarket Billing System

## Overview
The **Supermarket Billing System** is a console-based application developed in C++. This project demonstrates essential C++ programming skills, including object-oriented programming, file handling, and control structures. The system allows users to manage a supermarket's billing process by adding items to an inventory, generating bills based on customer purchases, and keeping track of item quantities.

## Features
- **Add Items to Inventory:** Add new items to the supermarket's inventory with details such as item name, rate, and quantity.
- **Generate Bills:** Calculate the total bill based on customer purchases. The system checks for item availability and quantity before finalizing the bill.
- **Persistent Data Storage:** Item information is stored in a text file, allowing the data to persist across multiple sessions.
- **User-Friendly Interface:** The program offers a simple, menu-driven interface that guides the user through various operations.

## Technologies Used
- **C++ Programming Language:** Core logic implementation using classes, objects, and control structures.
- **File Handling:** Persistent storage of item details using file input/output operations.
- **Windows System Commands:** Use of system commands like `cls` and `Sleep()` for a smoother console experience.

## How It Works
1. **Main Menu:**
   - The program starts with a menu offering three options:
     1. Add items to the inventory.
     2. Generate a bill for customer purchases.
     3. Exit the application.
   
2. **Adding Items:**
   - When adding an item, the user is prompted to enter the item's name, rate, and quantity. This data is then stored in a text file (`Bill_Print.txt`).

3. **Generating Bills:**
   - The user can input the item name and quantity they wish to purchase.
   - The program checks if the item exists and if the requested quantity is available.
   - If the conditions are met, the item’s cost is calculated and added to the total bill.
   - The program updates the item quantity in the file to reflect the purchase.

4. **Exiting the Program:**
   - The program can be safely exited via the menu, ensuring all data is saved and the application is closed properly.

## File Structure
- **Bill_Print.txt:** Stores the item details (name, rate, quantity) for persistent storage.
- **Bill_Temp.txt:** A temporary file used during the bill generation process to update item quantities.

## Installation and Usage
1. **Clone the Repository:**
   ```sh
   git clone https://github.com/yourusername/supermarket-billing-system.git
   ```
2. **Compile the Code:**
   - Use a C++ compiler like g++ to compile the `main.cpp` file.
   ```sh
   g++ main.cpp -o billing_system
   ```
3. **Run the Program:**
   - Execute the compiled binary to start the billing system.
   ```sh
   ./billing_system
   ```

## Contributing
This project is open-source and welcomes contributions. Feel free to fork the repository, make enhancements, and submit a pull request. Whether you want to add new features, fix bugs, or optimize the code, your contributions are appreciated.

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.
