/*
* this ERP system have to parts: 1. admin 2. customer

* ADMIN:
* admin can create user account.
* max admin are 3.
* admins can add new products, update their stock, change the price, remove products from the stock

* CUSTOMER:
* customers can only choose their products to buy from the stock
* they can have the recipt and total 
* customers can buy maximum 15 of any product.
*/


#include <iostream>
#include <string>
using namespace std;

// global product variables
string product_name[100];
int product_stock[100];
float product_price[100];

class ERP_User
{
    public:
        void userAcc(string name, string email, int password)
        {
            user_name = name;
            user_email = email;
            user_password = password;
        }

        string getName()
        {
            return user_name;
        }

        string getemail()
        {
            return user_email;
        }

        int getPassword()
        {
            return user_password;
        }

    private:
        string user_name;
        string user_email;
        int user_password; 
};

class ProductsAdd
{
    public:
        void newProduct(int productSlot, string new_name, int new_stock, float new_price)
        {
            int &i = productSlot;

            Name = new_name;
            Stock = new_stock;
            Price = new_price;

            product_name[i] = Name;
            product_stock[i] = Stock;
            product_price[i] = Price;
        }
    private:
        string Name;
        int Stock;
        float Price;
};

int login(string EMAIL, int PASSWORD);
void adminManage();

int main()
{
    int startOpt, loginOpt;

    string userName, userEmail;
    int userPassword;

    while(true)
    {
        cout << "1. Admin" << endl
             << "2. Customer" << endl
             << endl
             << "Option[1/2] : ";
        cin >> startOpt;


        if (startOpt == 1)
        {
            // create account or login window
            cout << "1. Create account" << endl
                 << "2. Login" << endl
                 << endl
                 << "Press 0 to go back" << endl
                 << "Option[1/2/0] : ";
            cin >> loginOpt;

            while(true)
            {
                bool created = false;

                if (loginOpt == 1)
                {
                    cout << endl 
                        << "Username: ";
                    cin >> userName;
                    cout << "Email: ";
                    cin >> userEmail;
                    cout << "Password: ";
                    cin >> userPassword;

                    ERP_User user;
                    user.userAcc(userName, userEmail, userPassword);

                    created = true;
                    break;
                }

                else if(loginOpt == 2 || created == true)
                {
                    cout << "Useremail: ";
                    cin >> userEmail;
                    cout << "Password: ";
                    cin >> userPassword;

                    if (login(userEmail, userPassword) == 0)
                    {
                        
                    }
                }
            }
        }

        else if (startOpt == 2)
        {
            /* code */
        }

        else if (startOpt == 0)
        {
            /* code */
        }
        
    }

    return 0;
}

int login(string EMAIL, int PASSWORD)
{
    ERP_User user;

    if (EMAIL == user.getemail() && PASSWORD == user.getPassword())
    {
        cout << endl
             << "[Login Successful]" << endl;
        return EXIT_SUCCESS;
    }

    else if (EMAIL != user.getemail() || PASSWORD != user.getPassword())
    {
        cout << "Wrong Password or email";
        return EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}

void adminManage()
{
    // Add product
    int opt;
    cin >> opt;

    while(true)
    {
        if (opt == 1)
        {
            int Slot;
            string ProductName;
            int ProductStock;
            float ProductPrice;

            cin >> Slot;
            cin >> ProductName;
            cin >> ProductStock;
            cin >> ProductPrice;

            ProductsAdd add;
            add.newProduct(Slot, ProductName, ProductStock, ProductPrice);
        }
    }
    // update stock
    // update price
}