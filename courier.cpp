#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "order.h"
#include "User.h"
#include "product.h"


using namespace std;

void COrders ::list_of_orders_delivering()          //List of assigned orders.
{
    char check_status[100] = "Pending delivery !";
    fstream check_corder;
    check_corder.open("order.txt", ios::binary | ios::in);
    if (!check_corder)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tProduct Details";
    cout << "\n\t\t\t*****************************************\n\n";

    cout << setw(15) << setiosflags(ios::left) << "Product Name ";
    cout << setw(15) << "Product Id";
    cout << setw(15) << "Order Number" << endl;
    bool notfound = true;
    while (!check_corder.eof())
    {
        if (check_corder.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {

            if (strcmpi(Ocourier_id, user_obj.user_id) == 0 && strcmpi(Status, check_status) == 0)
            {
                cout << setw(15) << OProduct_name << setw(15) << Oproduct_Id << setw(15) << Order_number << "\n";
                notfound = false;
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product  not found";
    }
    check_corder.close();
}

void COrders ::list_of_orders()             //function to print all completed and delivering ordrers.
{

    fstream check_corders;
    check_corders.open("order.txt", ios::binary | ios::in);
    if (!check_corders)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tProduct Details";
    cout << "\n\t\t\t*****************************************\n\n";

    cout << setw(15) << setiosflags(ios::left) << "Product Name ";
    cout << setw(15) << "Product Id";
    cout << setw(15) << "Order Number";
    cout << setw(15) << "Order Status" << endl;
    bool notfound = true;
    while (!check_corders.eof())
    {
        if (check_corders.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {

            if (strcmpi(Ocourier_id, user_obj.user_id) == 0)
            {
                cout << setw(15) << OProduct_name << setw(15) << Oproduct_Id << setw(15) << Order_number << setw(15) << Status << "\n";
                notfound = false;
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product  not found";
    }
    check_corders.close();
}

void COrders ::update_delivery()            //Function to update the delivery status.
{
    char o_num[50];
    cout << "Enter order number:- ";
    fflush(stdin);
    gets(o_num);
    fstream update_del;
    bool no_order = true;
    update_del.open("order.txt", ios::in | ios::out);
    while (!update_del.eof())
    {
        if (update_del.read((char *)&order_obj, sizeof(COrders)))
        {
            if (strcmpi(o_num, order_obj.Order_number) == 0)
            {
                strcpy(order_obj.Status, "Delivered");
                int pos = -1 * sizeof(order_obj);
                update_del.seekp(pos, ios::cur);
                update_del.write((char *)&order_obj, sizeof(COrders));
                cout << "Status Updated !!";
                no_order = false;
            }
        }
    }

    update_del.close();
}
