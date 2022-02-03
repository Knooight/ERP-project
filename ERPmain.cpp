#include <iostream>
#include <string>
using namespace std;

//global product strings
string product_name[4] = {"Milk", "Choclates", "Bread", "chips"};
int product_code[4] = {15, 30, 10, 50};
int product_stock[4] = {20, 50, 25, 40};
float product_price[4] = {20, 40, 100, 50};

// function call
int checkEntry(int ID, int PASSWORD);
void managment(int option);
void editMNGMT(int option);
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

                managment(opt);
            }
        }
    }

    return 0;
}

//login window
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

//admin and customer mananagement option 
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
                 << "Type 0 to go BACK" << endl
                 << "Enter option: ";
            cin >> admin_opt;

            editMNGMT(admin_opt);
        }
    }
}

void editMNGMT(int option)
{
    int product_indx, stock_up, stock_rmv;
    float price_new;

    // adds stock
    if (option = 1)
    {
        cout << "product number to add stock: ";
        cin >> product_indx;
        cout  << "numbers of products to add: ";
        cin >> stock_up;

        product_stock[product_indx - 1] = product_stock[product_indx - 1] + stock_up;
        cout << "new stock for " << product_name[product_indx - 1] << "= " << product_stock[product_indx - 1] << endl;
    }

    //removes stock
    else if (option = 2)
    {
        cout << "product number to add stock: ";
        cin >> product_indx;
        cout  << "numbers of products to add: ";
        cin >> stock_rmv;
        
        if (product_stock[product_indx - 1] < stock_rmv)
        {
            product_stock[product_indx - 1] = 0;
        }

        else
        {
            product_stock[product_indx - 1] = product_stock[product_indx - 1] - stock_rmv;
        }
    }

    //updates price
    else if (option = 3)
    {
        cout << "product number to update price: ";
        cin >> product_indx;
        cout  << "new price: ";
        cin >> price_new;

        product_price[product_indx - 1] = price_new;
        cout << endl << "updated price for " << product_name[product_indx - 1] << "= " << product_price[product_indx - 1];
    }

    else if (option = 0)
    {
        exit(1);
    }

    else
    {
        cout << "wrong option number. try again";
    }
}
