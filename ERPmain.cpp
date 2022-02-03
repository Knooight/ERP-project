#include <iostream>
#include <string>
using namespace std;

string product_name[4] = {"Milk", "Choclates", "Bread", "chips"};
int product_code[4] = {15, 30, 10, 50};
int product_stock[4] = {20, 50, 25, 40};
float product_price[4] = {20, 40, 100, 50};

int checkEntry(int ID, int PASSWORD);
void managment(int option);

int main()
{
    int id, password;

    while (true)
    {
        cout << endl
             << "User ID: ";
        cin >> id;
        cout << "password: ";
        cin >> password;

        if (checkEntry(id, password) == 1)
        {
            while (true)
            {
                int opt;

                cout << endl
                     << "--------------------" << endl;
                cout << "1. ADMIN MANAGMENT" << endl;
                cout << "2. PURCHASE MANAGEMENT" << endl
                     << endl;
                cout << "Type 0 to EXIT the program" << endl;
                cout << "--------------------" << endl;
                cout << "ENTER YOU OPTION: ";
                cin >> opt;

                
            }
        }
    }

    return 0;
}

int checkEntry(int ID, int PASSWORD)
{
    const int adminID = 1234;
    const int adminPASS = 2345;
    int tracker = 1;

    if (ID == adminID && PASSWORD == adminPASS)
    {
        cout << endl
             << "[Login Successful]" << endl;
        return tracker;
    }

    else if (ID != adminID || PASSWORD != adminPASS)
    {
        cout << "Wrong Password or Username";
        tracker = 0;
        return tracker;
    }
}

void managment(int option)
{
    if (option == 1)
    {
        while (true)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << "| " << product_name[i] << "(" << product_code << ")"
                     << "|" << product_stock[i] << "|" << product_price << endl;
            }

            int admin_opt;
            cout << "1. ADD STOCK \t 2. REMOVE STOCK \t 3. UPDATE PRICE" << endl
                 << "Type 0 to go BACK";
        }
    }
}