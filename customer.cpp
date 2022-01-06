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

void CUser ::Search_Product()  //Function to search for a product
{
    char Product_Search[100];
    fflush(stdin);
    cout << "\nEnter the product to search:-";
    gets(Product_Search);
    fstream checkfile;
    checkfile.open("product.txt", ios::in | ios::out);
    if (!checkfile)
    {
        cout << "File doesnot exist";
    }
    bool noproduct = true;

    cout << setw(15) << setiosflags(ios::left) << "Product Name ";
    cout << setw(15) << "Product Price";
    cout << setw(15) << "Product Type";
    cout << setw(15) << "Product Id";
    cout << setw(15) << "Merchant Id";
    cout << setw(15) << "Product Quantity" << endl;
    bool notfound = true;
    while (!checkfile.eof())
    {
        if (checkfile.read((char *)&prod_obj, sizeof(CProduct)))
        {
            if (strcmpi(Product_Search, prod_obj.product_Name) == 0)
            {
                cout << setw(15) << prod_obj.product_Name << setw(15)
                     << prod_obj.product_Price << setw(15)
                     << prod_obj.product_Type << setw(15)
                     << prod_obj.product_Id << setw(15)
                     << prod_obj.merchant_Id <<setw(15)
                     << prod_obj.product_Quantity<< "\n";
                noproduct = false;
            }
        }
    }
    checkfile.close();
    if (noproduct == true)
    {
        cout << "Product not found..!";
        Search_Product();
    }
}

void COrders ::Buy_Product()        //Function to buy product
{
    int user_choice = 0;
    int buy_choice;
    while (user_choice != 4)
    {
        cout << "\n\n1.Search product \t\t\t2.Cancel Order \t\t\t3.View Orders \t\t\t 4. Exit";
        cout << "\nEnter the choice:-";
        cin >> user_choice;
        switch (user_choice)
        {
        case 1:
            user_obj.Search_Product();
            cout << "\n1.Buy the product\t\t2.Go back";
            fflush(stdin);
            cout << "\nEnter the choice:- ";
            cin >> buy_choice;
            switch (buy_choice)
            {
            case 1:
                order_obj.Addto_file();
                break;
            case 2:
                cout << "back";
                break;
            }
            break;
        case 2:
            order_obj.Cancel_Product();
            break;
        case 3:
            order_obj.View_Status();
            break;
        case 4:
            cout << "Exiting";
            break;
        default:
            cout << "Invalid input.";
            break;
        }
    }
}
void COrders ::Addto_file()     //Function to add order details to curresponding file.
{
    fstream getord_id;
    getord_id.open("order.txt", ios::binary | ios::in);
    while (!getord_id.eof())
    {
        if (getord_id.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            int int_ord_id = stoi(Order_number);
            int_ord_id++;
            std::sprintf(Order_number, "%d", int_ord_id);
        }
    }
    getord_id.close();
    int pr_q, opr_q, new_prq;
    char new_char;
    cout << "\nEnter the product Id:-";
    fflush(stdin);
    gets(order_obj.Oproduct_Id);
    bool noproduct = true;
    fstream checkproduct;
    checkproduct.open("product.txt", ios::in | ios::out);
    bool notenough = true;
    while (!checkproduct.eof())
    {
        if (checkproduct.read((char *)&prod_obj, sizeof(CProduct)))
        {
            if (strcmp(order_obj.Oproduct_Id, prod_obj.product_Id) == 0)
            {
                noproduct = false;
                cout << "Enter the quantity :-";
                gets(order_obj.Oproduct_quantity);
                pr_q = stoi(prod_obj.product_Quantity);
                opr_q = stoi(order_obj.Oproduct_quantity);
                if (opr_q <= pr_q)
                {
                    notenough = false;
                    strcpy(order_obj.Ouser_id, user_obj.user_id);
                    strcpy(order_obj.OMerchant_id, prod_obj.merchant_Id);
                    strcpy(order_obj.OProduct_name, prod_obj.product_Name);
                    strcpy(order_obj.Oproduct_price, prod_obj.product_Price);
                    // strcpy(order_obj.Order_number, "34567");                     //Used to initialize the first order number.
                    strcpy(order_obj.Status, "Pending delivery !");
                    strcpy(order_obj.courier_status, "not assigned");
                    new_prq = pr_q - opr_q;
                }
            }
        }
    }
    checkproduct.close();
    if (noproduct == true)
    {
        cout << "No such product.";
    }
    else if (notenough == true)
    {
        cout << "Currently out of stock  !!";
    }
    else
    {
        fstream reduce_count;
        reduce_count.open("product.txt", ios::in | ios::out);
        bool cannot_reduce_count = true;
        while (!reduce_count.eof())
        {
            if (reduce_count.read((char *)&prod_obj, sizeof(CProduct)))
            {
                if (strcmpi(order_obj.Oproduct_Id, prod_obj.product_Id) == 0)
                {
                    sprintf(prod_obj.product_Quantity, "%d", new_prq);
                    int pos = -1 * sizeof(prod_obj);
                    reduce_count.seekp(pos, ios::cur);
                    reduce_count.write((char *)&prod_obj, sizeof(CProduct));
                    cannot_reduce_count = false;
                }
            }
        }
        reduce_count.close();
    }

    if (noproduct == false && notenough == false)
    {
        fstream tofile;
        tofile.open("order.txt", ios::app | ios::out);
        tofile.write((char *)&order_obj, sizeof(COrders));
        tofile.close();
        cout << "Successfully placed your order";
    }
}
void COrders ::Cancel_Product()         //Function to cancel an order.
{
    char cancel_product[100];
    char inc_pro[100];
    int qty_pro, ord_qty, new_qty_pro;
    cout << "Enter the order number:- ";
    fflush(stdin);
    gets(cancel_product);
    fstream cancelproduct;
    cancelproduct.open("order.txt", ios::in | ios::out);
    bool invalidorder = true;
    while (!cancelproduct.eof())
    {
        if (cancelproduct.read((char *)&order_obj, sizeof(COrders)))
        {
            if (strcmpi(cancel_product, order_obj.Order_number) == 0)
            {
                strcpy(order_obj.Status, "Order Cancelled");
                int pos = -1 * sizeof(order_obj);
                cancelproduct.seekp(pos, ios::cur);
                cancelproduct.write((char *)&order_obj, sizeof(COrders));
                cout << "Order cancelled Successfully";
                invalidorder = false;
                strcpy(inc_pro, order_obj.Oproduct_Id);
                ord_qty = stoi(order_obj.Oproduct_quantity);
            }
        }
    }
    if (invalidorder == true)
    {
        cout << "\nInvalid Order number.";
    }
    cancelproduct.close();

    fstream increase_count;
    increase_count.open("product.txt", ios::in | ios::out);
    bool cannot_increase_count = true;
    while (!increase_count.eof())
    {
        if (increase_count.read((char *)&prod_obj, sizeof(CProduct)))
        {
            if (strcmpi(inc_pro, prod_obj.product_Id) == 0)
            {
                qty_pro = stoi(prod_obj.product_Quantity);
                new_qty_pro = qty_pro + ord_qty;
                std::sprintf(prod_obj.product_Quantity, "%d", new_qty_pro);
                int pos = -1 * sizeof(prod_obj);
                increase_count.seekp(pos, ios::cur);
                increase_count.write((char *)&prod_obj, sizeof(CProduct));
                cannot_increase_count = false;
            }
        }
    }
    increase_count.close();
    Buy_Product();
}

void COrders ::View_Status()            //Function to view the status of an order.
{
    fstream viewstat;
    bool noorder = true;
    viewstat.open("order.txt", ios::binary | ios::in);

    cout << setw(15) << setiosflags(ios::left) << "Order Number ";
    cout << setw(15) << "Product Name";
    cout << setw(15) << "Order Status";
    cout << setw(15) << "Product Quantity" << endl;
    while (!viewstat.eof())
    {
        if (viewstat.read((char *)&order_obj, sizeof(COrders)))
        {
            if (strcmpi(user_obj.user_id, order_obj.Ouser_id) == 0)
            {
                cout<< setw(15) << order_obj.Order_number<< setw(15)
                << order_obj.OProduct_name << setw(15)
                <<order_obj.Status<<setw(15)<<order_obj.Oproduct_quantity<<"\n";
                bool noorder = false;
            }
        }
    }

    viewstat.close();
}