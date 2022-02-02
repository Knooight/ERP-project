#include <iostream>
#include <string>
using namespace std;

int checkEntry(int ID, int PASSWORD);

int main()
{
    string product_name[4] = {"Milk", "Choclates", "Bread", "chips"};
    int product_code[4] = {15, 30, 10, 50};
    float product_price[4] = {20, 40, 100, 50};

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

                cout << endl << "--------------------";
                cout << "1. ADMIN MANAGMENT" << endl;
                cout << "2. PURCHASE MANAGEMENT" << endl << endl;
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
    }
    
    /*else if (ID == 0 && PASSWORD == 0)
    {
        cout << "Program Terminated";
    }*/
}
