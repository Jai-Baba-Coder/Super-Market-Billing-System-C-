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
        cout << endl << "Enter choice >> " << endl;
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

            cout << "Enter total number of items >> " << endl;
            cin >> Quantity;

            b.setQuantity(Quantity);

            ofstream out("D:/codeGround/Project_2/Bill_Print.txt", ios :: app);
            
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

void printBill () {
    system("cls");
    int count = 0;
    bool close = false;

    while(!close) {
        system("cls");
        int choice;

        cout << "1. Add bill" << endl;
        cout << "2. Close session" << endl;

        cout << endl << "Enter choice >>" << endl;
        cin >> choice;

        if(choice == 1) {
            string item;
            int quant;

            cout << "Enter item >> " << endl;
            cin >> item;

            cout << "Enter total number of items >> " << endl;
            cin >> quant;

            ifstream in("D:/codeGround/Project_2/Bill_Print.txt");
            ofstream out("D:/codeGround/Project_2/Bill_Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss;
                ss << line;

                string name;
                int itemRate, itemQuant;
                char delimiter;
                ss >> name >> delimiter >> itemRate >> delimiter >> itemQuant;

                if(item == name) {
                    found = true;
                    if(quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "Item | Rate | Quantity | Amount" << endl;
                        cout << name << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;

                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;

                        count = count + amount;

                        out << name << " : " << itemRate << " : " << itemQuant << endl << endl;

                    }
                    else {
                        cout << "Sorry! " << name << " not available as required!" << endl;
                    }
                }
                else {
                    out << line<< endl;
                }
            }
            if(!found) {
                cout << "Item not available!" << endl;
            }
            out.close();
            in.close();
            remove("D:/codeGround/Project_2/Bill_Print.txt");
            rename("D:/codeGround/Project_2/Bill_Temp.txt", "D:/codeGround/Project_2/Bill_Print.txt");
        }
        else if(choice == 2) {
            close = true;
            cout << "Counting total bill..." << endl;
        }
        Sleep(5000);
    }
    system("cls");
    cout << endl << endl;
    cout << "Total bill--------------" << count << endl << endl;
    cout << "Thanks for shopping with us!" << endl;
    Sleep(3000);
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

        cout << endl << endl;

        cout << "1. Add items" << endl;
        cout << "2. Print bill" << endl;
        cout << "3. Exit" << endl;

        cout << endl;
        cout << endl;

        cout << endl << "Enter choice >> " << endl;
        cin >> val;

        if(val == 1) {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if(val == 2) {
            printBill();
        }
        else if(val == 3) {
            system("cls");
            exit = true;

            cout << "*** Software closed! ***" << endl;
            Sleep(3000);
        }
        else {
            cout << "Please choose a valid option! Thank you" << endl;
        }
    }
}