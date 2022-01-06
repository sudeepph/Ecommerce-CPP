#include "User.h"
#include "product.h"
#include "order.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void CUser ::add_user()         //Function to add a new user.
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 Account Creation  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ENTER THE DETAILS ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cout << "\n\t\t 1. Customer \t 2. Merchant \t 3. Courier";
    cout << "\n\t\t Choose the type of User";
    cin >> user_type;

    if (user_type == 1)         //Used to autoincrement the customer ID.
    {
        fstream getid;
        getid.open("customer.txt", ios::binary | ios::in);
        while (!getid.eof())
        {
            if (getid.read(reinterpret_cast<char *>(this), sizeof(*this)))
            {
                int int_user_id = stoi(user_id);
                int_user_id++;
                std::sprintf(user_id, "%d", int_user_id);
            }
        }
        getid.close();
    }
    else if (user_type == 2)            //Used to autoincrement the merchant ID.
    {
        fstream getmid;
        getmid.open("merchant.txt", ios::binary | ios::in);
        while (!getmid.eof())
        {
            if (getmid.read(reinterpret_cast<char *>(this), sizeof(*this)))
            {
                int int_user_id = stoi(user_id);
                int_user_id++;
                std::sprintf(user_id, "%d", int_user_id);
            }
        }
        getmid.close();
    }
    else if (user_type == 3)            //Used to autoincrement the merchant ID.
    {

        fstream getcid;
        getcid.open("courier.txt", ios::binary | ios::in);
        while (!getcid.eof())
        {
            if (getcid.read(reinterpret_cast<char *>(this), sizeof(*this)))
            {
                int int_user_id = stoi(user_id);
                int_user_id++;
                std::sprintf(user_id, "%d", int_user_id);
            }
        }
        getcid.close();
    }

    fflush(stdin);

    cout << "\n\t\t Enter your name :-  ";
    gets(user_name);
    fflush(stdin);

    cout << "\n\t\t Enter your Mobile number :- ";
    gets(user_contact_num);
    cout << "\n\t\t Enter your Email :- ";
    gets(user_mail);
    cout << "\n\t\t Enter password :-  ";
    gets(passwd);

    if (user_type == 1)
    {
        cout << "\n\t\t Enter your Shipping Address :- ";
        gets(cust_address);
        fstream outin;
        outin.open("customer.txt", ios::app | ios::out);
        outin.write((char *)this, sizeof(CUser));
        outin.close();
        cout << "You have been registered successfully as customer and your ID is:- " << user_id;
    }
    else if (user_type == 2)
    {
        cout << "\n\t\t Enter your Garage location :- ";
        gets(merch_location);
        fstream outin;
        outin.open("merchant.txt", ios::app | ios::out);
        outin.write((char *)this, sizeof(CUser));
        cout << "You have been registered successfully as merchant and your ID is:- " << user_id;
    }

    else if (user_type == 3)
    {
        cout << "\n\t\t Enter your preferred delivery area :- ";
        gets(cour_area);
        fstream outin;
        outin.open("courier.txt", ios::app | ios::out);
        outin.write((char *)this, sizeof(CUser));
        cout << "You have been registered successfully as courier person and your ID is:- " << user_id;
    }
}

void CUser ::login_user()           //Function used for the authentication.
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 User Login  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ENTER THE LOGIN CREDENTIALS ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    char user_check[100];
    int type_user;
    cout << "\n\t\t 1. Customer \t 2. Merchant \t 3. Courier";
    cout << "\n\t\t Choose the type of User";
    cin >> type_user;
    cout << "\n\t\t Enter your User Id :-  ";
    fflush(stdin);
    gets(user_check);

    if (type_user == 1)
    {
        fstream checkfile;
        checkfile.open("customer.txt", ios::binary | ios::in);
        if (!checkfile)
        {
            cout << "File doesnot exist";
        }
        cout << "\t\t\t\t\t\t " << endl
             << endl;
        cout << "\n\t\t\t*****************************************\n";
        cout << "\n\t\t\t*****************************************\n\n";
        bool notfound = true;
        while (!checkfile.eof())
        {
            if (checkfile.read(reinterpret_cast<char *>(this), sizeof(*this)))
            {
                if (strcmpi(user_check, user_id) == 0)
                {
                    notfound = false;
                    cout << "Successfuly logged in\n";
                    order_obj.Buy_Product();
                }
            }
        }
        if (notfound == true)
        {
            cout << "User not found";
        }

        
        checkfile.close();
    }

    if (type_user == 2)
    {
        fstream checkfile;
        checkfile.open("merchant.txt", ios::binary | ios::in);
        if (!checkfile)
        {
            cout << "File doesnot exist";
        }
        cout << "\t\t\t\t\t\t " << endl
             << endl;
        cout << "\n\t\t\t*****************************************\n";
        cout << "\n\t\t\t*****************************************\n\n";
        bool notfound = true;
        while (!checkfile.eof())
        {
            if (checkfile.read(reinterpret_cast<char *>(this), sizeof(*this)))
            {
                if (strcmpi(user_check, user_id) == 0)
                {
                    notfound = false;
                    int merch_choice = 0;
                    while (merch_choice != 8)
                    {
                        cout << "\n\n***********************************\n";
                        cout << "\tE-You are loggined as Merchant\n";
                        cout << "***********************************\n";
                        cout << "\t1. Add Product\n\n";
                        cout << "\t2. Search Product By Name\n\n";
                        cout << "\t3. Search Product By Type\n\n";
                        cout << "\t4. View Product Under a Particular Count\n\n";
                        cout << "\t5. Assign a Product to a Courier Person\n\n";
                        cout << "\t6. Dispaly cancelled Orders\n\n";
                        cout << "\t7. See the status of orders\n\n";
                        cout << "\t8. Exit\n\n";

                        cout << "Enter the merch_choice : \n";
                        cin >> merch_choice;

                        switch (merch_choice)
                        {
                        case 1:
                            cout << "Add a Product\n";
                            prod_obj.add_product();
                            break;
                        case 2:
                            cout << "Search a Product By Name \n ";
                            prod_obj.search_product_name();
                            break;
                        case 3:
                            cout << "Search  a Product By Type\n";
                            prod_obj.search_product_by_type();
                            break;
                        case 4:
                            cout << "Products under a particular Count\n";
                            prod_obj.prod_under_a_count();
                            break;
                        case 5:
                            cout << "assign orsders to courier person";
                            prod_obj.assign_courier();
                            break;

                        case 6:
                            cout << "see Cancel Orders\n";
                            prod_obj.list_cancel_orders();
                            break;
                        case 7:
                            cout << "see status\n";
                            prod_obj.status_of_order();
                            break;
                        case 8:
                            cout << "exiting";
                            break;
                        default:
                            cout << "Wrong choice\n";
                            break;
                        }
                    }
                }
            }
        }
        if (notfound == true)
        {
            cout << "User not found";
        }
        
        checkfile.close();
    }

    if (type_user == 3)
    {
        fstream checkfile;
        checkfile.open("courier.txt", ios::binary | ios::in);
        if (!checkfile)
        {
            cout << "File doesnot exist";
        }
        cout << "\t\t\t\t\t\t " << endl
             << endl;
        cout << "\n\t\t\t*****************************************\n";
        cout << "\n\t\t\t*****************************************\n\n";
        bool notfound = true;
        while (!checkfile.eof())
        {
            if (checkfile.read(reinterpret_cast<char *>(this), sizeof(*this)))
            {
                if (strcmpi(user_check, user_id) == 0)
                {
                    notfound = false;
                    int courier_choice = 0;
                    while (courier_choice != 4)
                    {
                        cout << "\n\n***********************************\n";
                        cout << "\tE-You are loggined as Courier Person\n";
                        cout << "***********************************\n";
                        cout << "\t1. See the pending orders\n";
                        cout << "\t2. Update the Delivery Status Of an Order\n";
                        cout << "\t3. List of all orders assigned\n\n";
                        cout << "\t4. Exit\n\n";

                        cout << "Enter the choice : \n";
                        cin >> courier_choice;

                        switch (courier_choice)
                        {
                        case 1:
                            cout << "Assigned Orders \n";
                            order_obj.list_of_orders_delivering();
                            break;
                        case 2:
                            cout << "Changing Status\n ";
                            order_obj.update_delivery();
                            exit(0);
                            break;
                        case 3:
                            cout << "All Orders";
                            order_obj.list_of_orders();
                            break;
                        case 4:
                            cout << "Exiting";
                            break;
                        default:
                            cout << "Wrong choice";
                            break;
                        }
                    }
                }
            }
        }
        if (notfound == true)
        {
            cout << "User not found";
        }
        else if (notfound == false)
        {
            cout << "User found";
            cout << user_id;
        }
        checkfile.close();
    }
}
