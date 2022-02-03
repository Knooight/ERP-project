#include <iostream>
#include <string>
using namespace std;

//global product strings
string product_name[4] = {"Milks", "Juice", "Bread", "chips"};
int product_code[4] = {15, 30, 10, 50};
int product_stock[4] = {20, 50, 25, 40};
float product_price[4] = {20, 40, 35, 50};

//global cart strings for purchase management
int product_quan;
int idx = 0;

string cart[1000];
int quan[1000];
float price[1000];
float total = 0;

// function declarations
int checkEntry(int ID, int PASSWORD);
void managment(int option);
void editMNGMT(int option);
void editPURCHASE(int product_indx);
void TOTALcalc();

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

                if (opt == 1 || opt == 2 || opt == 3)
                {
                    managment(opt);
                }

                else if (opt == 0)
                {
                    break;
                }

                else
                {
                    cout << "Wrong option, try again...";
                }
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
    //admin management
    if (option == 1)
    {
        while (true)
        {
            cout << endl
                 << "+--PRODUCT NAME & CODE--+----- STOCK----+---PRICE---+" << endl;
            cout << "+-----------------------+---------------+-----------+";
            for (int i = 0; i < 4; i++)
            {
                cout << endl
                     << "|" << i + 1 << "." << product_name[i] << "(" << product_code[i] << ")\t"
                     << "\t|\t" << product_stock[i] << "\t|\t" << product_price[i] << "  |" << endl;
                cout << "+-----------------------+---------------+-----------+";
            }

            int admin_opt;
            cout << endl
                 << "1. ADD STOCK \t 2. REMOVE STOCK \t 3. UPDATE PRICE" << endl
                 << "Type 0 to go BACK" << endl
                 << "Enter option: ";
            cin >> admin_opt;

            if (admin_opt == 1 || admin_opt == 2 || admin_opt == 3)
            {
                editMNGMT(admin_opt);
            }

            else if (admin_opt == 0)
            {
                break;
            }

            else
            {
                cout << "Wrong option, try again...";
            }
        }
    }

    //purchase management
    if (option == 2)
    {
        int product_indx;

        while (true)
        {
            cout << endl
                 << "+--PRODUCT NAME & CODE--+----- STOCK----+---PRICE---+" << endl;
            cout << "+-----------------------+---------------+-----------+";
            for (int i = 0; i < 4; i++)
            {
                cout << endl
                     << "|" << i + 1 << "." << product_name[i] << "(" << product_code[i] << ")\t"
                     << "\t|\t" << product_stock[i] << "\t|\t" << product_price[i] << "  |" << endl;
                cout << "+-----------------------+---------------+-----------+";
            }
            while (true)
            {
                cout << endl
                    << "poroduct number to buy(0 to exit): ";
                cin >> product_indx;

                if (product_indx == 0)
                {
                    break;
                }
                
                else if (product_indx > 4 || product_indx < 1)
                {
                    cout << "Invalid serial number, try again...";
                }

                else
                {
                    editPURCHASE(product_indx);
                }
            }

            TOTALcalc();
        }
    }

    if (option == 0)
    {
        exit(0);
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
        cout << "numbers of products to add: ";
        cin >> stock_up;

        product_stock[product_indx - 1] = product_stock[product_indx - 1] + stock_up;
        cout << "new stock for " << product_name[product_indx - 1] << "= " << product_stock[product_indx - 1] << endl;
    }

    //removes stock
    else if (option = 2)
    {
        cout << "product number to add stock: ";
        cin >> product_indx;
        cout << "numbers of products to add: ";
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
        cout << "new price: ";
        cin >> price_new;

        product_price[product_indx - 1] = price_new;
        cout << endl
             << "updated price for " << product_name[product_indx - 1] << "= " << product_price[product_indx - 1];
    }
}

void editPURCHASE(int product_indx)
{
    cart[idx] = product_name[product_indx - 1];
    cout << "Number of products of buy: ";
    cin >> product_quan;

    if (product_quan > product_stock[product_indx - 1])
    {
        cout << endl
                << "!! INSUFFICIENT STOCK !!" << endl;
    }

    else
    {
        product_stock[product_indx - 1] = product_stock[product_indx - 1] - product_quan;
        price[idx] = product_price[product_indx - 1];
        quan[idx] = product_quan;
        idx++;
    }
}

void TOTALcalc()
{
    //sum of total price
    for (int i = 0; i < idx; i++)
    {
        total = total + price[i] * quan[i];
    }

    //reception letter
    cout << endl
         << "[NAME]\t [QUANTITY]\t [PRICE]";

    for (int i = 0; i < idx; i++)
    {
        cout << endl
             << cart[i] << "\t" << quan[i] << "\t" << price[i] * quan[i];
    }

    cout << endl
         << "TOTAL: " << total << " BDT";

    total = 0;
}