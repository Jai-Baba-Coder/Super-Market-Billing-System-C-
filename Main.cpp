#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>

using namespace std;

class Bill {
    private: 
        string itemName;
        int Rate, Quantity;
    public:
        Bill(): itemName(""), Rate(0), Quantity(0) {

        }
        void setItem(string item) {
            itemName = item;
        }
        void setRate(int rate) {
            Rate = rate;
        }
        void setQuantity(int quantity) {
            Quantity = quantity;
        }
        string getItem() {
            return itemName;
        }
        int getRate() {
            return Rate;
        }
        int getQuantity() {
            return Quantity;
        }
};

void addItem (Bill b) {
    bool close = false;

    while(!close) {
        int choice;

        cout << "1. Add item" << endl;
        cout << "2. Close" << endl;
        cout << "Enter choice >> " << endl;
        cin >> choice;

        if(choice == 1) {
            system("cls");

            string itemName;
            int Rate, Quantity;

            cout << "Enter item name >> " << endl;
            cin >> itemName;

            b.setItem(itemName);


            cout << "Enter total price of item >> " << endl;
            cin >> Rate;

            b.setRate(Rate);

            cout << "Enter total number of items brought >> " << endl;
            cin >> Quantity;

            b.setQuantity(Quantity);

            ofstream out("D:/codeGround/Project_2", ios :: app);
            
            if(!out) cout << "Error! file can't open temporarily :(" << endl;
            else {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl << endl;
                cout << "Item added succesfully" << endl;
                Sleep(3000);
            }
            out.close();
        }
        else if(choice == 2) {
            system("cls");
            close = true;
            cout << "Back to main menu" << endl;
            Sleep(3000);
        }
    }
}

int main() {
    Bill b;
    bool exit = false;

    while(!exit) {
        system("cls");
        int val;

        cout<< "*****************************************" << endl;
        cout << "** Welcome to Supermarket Billing Software **" << endl;
        cout<< "*****************************************" << endl;

        cout << "1. Add items" << endl;
        cout << "2. Print bill" << endl;
        cout << "3. Exit" << endl;

        cout << endl;
        cout << endl;

        cout << "Enter choice >> " << endl;
        cin >> val;

        if(val == 1) {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
    }
}