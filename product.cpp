#include "product.h"
#include "order.h"
#include "User.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void CProduct ::add_product()           //Function to add new product to the list.
{

    int Type;
    fstream getpid;
    getpid.open("product.txt", ios::binary | ios::in);
    while (!getpid.eof())
    {
        if (getpid.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            int int_prd_id = stoi(product_Id);
            int_prd_id++;
            std::sprintf(product_Id, "%d", int_prd_id);
        }
    }
    getpid.close();


    cout << "Enter the Product Name\n";
    fflush(stdin);
    gets(product_Name);
    cout << "\nEnter the Product catogory\n";
    cout << "\n1:Electronics \n2:Fashion \n3:Grocery \n4:Sports\n";
    cin >> Type;
    if (Type == 1)
    {
        strcpy(product_Type, "Electronics");
    }
    else if (Type == 2)
    {
        strcpy(product_Type, "Fashion");
    }
    else if (Type == 3)
    {
        strcpy(product_Type, "Grocery");
    }
    else if (Type == 4)
    {
        strcpy(product_Type, "Sports");
    }
    cout << "Enter the Quantity\n";
    fflush(stdin);
    gets(product_Quantity);
    cout << "Enter the Price \n";
    fflush(stdin);
    gets(product_Price);
    
    fflush(stdin);
    strcpy(merchant_Id,user_obj.user_id);
    fstream prwrite;
    prwrite.open("product.txt", ios::app | ios::out);
    prwrite.write((char *)this, sizeof(CProduct));
    prwrite.close();
    cout <<"Product added successfully";
}


void CProduct ::search_product_name()           //function to search for products by name.
{
    char check_prdname[100];
    fflush(stdin);
    cout << "Enter the product name to search";
    fflush(stdin);
    gets(check_prdname);

    fstream check_pname;
    check_pname.open("product.txt", ios::binary | ios::in);
    if (!check_pname)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tProduct Details";
    cout << "\n\t\t\t*****************************************\n\n";   
	cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Product Name ";
    cout<<setw(15)<<"Product Price";
    cout<<setw(15)<<"Product Quantity";
    cout<<setw(15)<<"Product Id"<<endl;
    

    bool notfound = true;
    while (!check_pname.eof())
    {
        if (check_pname.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            if (strcmpi(check_prdname, product_Name) == 0 && strcmpi(user_obj.user_id,merchant_Id)==0)
            {
                notfound = false;
                cout << setw(15)<<product_Name << setw(15)
                     << setw(15) << product_Price << setw(15) << product_Quantity << setw(15) << product_Type<<setw(15) << product_Id << "\n";
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product not found";
    }
    
    check_pname.close();
}

void CProduct ::search_product_by_type()            //function to search for products by type
{
    fflush(stdin);
    char check_prdtype[100];
    int cat_sel;
    cout << "Enter the product type to search\n";
    fflush(stdin);

    cout << "\n1:Electronics \n2:Fashion \n3:Grocery \n4:Sports\n";
    cin>>cat_sel;

    if (cat_sel==1)
    {
        strcpy(check_prdtype,"Electronics");
    }

    else if (cat_sel==2)
    {
        strcpy(check_prdtype,"Fashion");
    }
    else if (cat_sel==3)
    {
        strcpy(check_prdtype,"Grocery");
    }
    else if (cat_sel==4)
    {
        strcpy(check_prdtype,"Sports");
    }
    
    
    fstream check_ptype;
    check_ptype.open("product.txt", ios::binary | ios::in);
    if (!check_ptype)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tProduct Details";
    cout << "\n\t\t\t*****************************************\n\n";
    cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Product Name ";
    cout<<setw(15)<<"Product Price";
    cout<<setw(15)<<"Product Quantity";
    cout<<setw(15)<<"Product Id"<<endl;
    bool notfound = true;
    while (!check_ptype.eof())
    {
        if (check_ptype.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            if (strcmpi(check_prdtype, product_Type) == 0&& strcmpi(user_obj.user_id,merchant_Id)==0)
            {
                cout <<setw(15)<< product_Name << setw(15)
                     << setw(15) << product_Price << setw(15) << product_Quantity <<setw(15)<< product_Id << "\n";
                notfound = false;
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product  not found";
    }
    
    check_ptype.close();
}


void CProduct ::prod_under_a_count()            //function to view products below a particular count
{
    int prd_ucount;
    fflush(stdin);
    cout << "Enter the Particular Count to view Product under count\n";
    fflush(stdin);
    cin >> prd_ucount;
    fstream punder_count;
    punder_count.open("product.txt", ios::binary | ios::in);
    if (!punder_count)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tProduct Details";
    cout << "\n\t\t\t*****************************************\n\n";
    cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Product Name ";
    cout<<setw(15)<<"Product Price";
    cout<<setw(15)<<"Product Quantity";
    cout<<setw(15)<<"Product Category"<<endl;
    bool notfound = true;
    while (!punder_count.eof())
    {
        if (punder_count.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            int Product_q = stoi(product_Quantity);
            if (Product_q < prd_ucount)
            {
                cout<<setw(15) << product_Name << setw(15)
                     << product_Price << setw(15) << product_Quantity << setw(15) << product_Type << "\n";
                notfound = false;
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product  not found\n";
    }
    
    punder_count.close();
}

void CProduct::assign_courier()         //Function to assign a courier person.
{
    fstream courier_check;
    courier_check.open("order.txt",ios::in | ios::out);
    if (!courier_check)
    {
        cout<<"File doesmot exist";
    }

    bool nopending_assign=true;
    char assign_check[100];
    strcpy(assign_check,"not assigned");

    cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Order ID ";
    cout<<setw(15)<<"Product Name";
    cout<<setw(15)<<"Order Status"<<endl;
    while(!courier_check.eof())
    {
        if (courier_check.read((char*)&order_obj,sizeof(COrders)))
        {
            if (strcmpi(order_obj.courier_status,assign_check)==0 && strcmpi(order_obj.OMerchant_id,user_obj.user_id)==0)
            {
                nopending_assign=false;
                cout<<setw(15)<<order_obj.Order_number<<setw(15)<<order_obj.OProduct_name<<setw(15)<<order_obj.courier_status;
                cout<<"\n";
            }
        }
    }
    courier_check.close();
    if (nopending_assign==true)
    {
        cout << "no pending orders to assign courier person";
    }

    fstream courier_show;
    courier_show.open("courier.txt",ios::binary | ios::in);
    if (!courier_show)
    {
        cout << "File does not exist";
    }
    bool nocourier =true;
    cout << "The details of courier person are:";
    cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"User ID ";
    cout<<setw(15)<<"User Name";
    cout<<setw(15)<<"Preferred Area"<<endl;
    while (!courier_show.eof())
    {
        if (courier_show.read((char *)&user_obj,sizeof(CUser)))
        {
            cout<<setw(15)<<user_obj.user_id<<setw(15)<<user_obj.user_name<<setw(15)<<user_obj.cour_area<<"\n";
            nocourier=false;
        }
    }

    courier_show.close();
    char getord_id[100];
    char getcor_id[100];
    cout <<"\t\t Enter the Id of the order you want to assign courier person to : ";
    fflush(stdin);
    gets(getord_id);
    cout <<"\n\n\t\t Enter the User Id of the courier person you want to assign to this order ";
    gets(getcor_id);

    fstream add_courier;
    add_courier.open("order.txt",ios::in |ios::out);
    bool cannot_add_courier=true;
    while(!add_courier.eof())
    {
        if (add_courier.read((char *)&order_obj,sizeof(COrders)))
        {
            if (strcmpi(getord_id,order_obj.Order_number)==0)
            {
                strcpy(order_obj.courier_status,"assigned");
                strcpy(order_obj.Ocourier_id,getcor_id);
                int pos = -1*sizeof(order_obj);
                add_courier.seekp(pos,ios::cur);
                add_courier.write((char *)&order_obj,sizeof(COrders));
                cout << " Assigned courier person successfully";
                cannot_add_courier =false;

            }
        }
        
    }
    add_courier.close();
    if(cannot_add_courier==true)
    {
        cout << "Sorry we are not able to assign courier person.";
    }
    

}

void CProduct ::list_cancel_orders()            //Function show the canceled orders.
{
    char check_status[100] = "Order cancelled";
    fstream check_pcancel;
    check_pcancel.open("order.txt", ios::binary | ios::in);
    if (!check_pcancel)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\t Details";
    cout << "\n\t\t\t*****************************************\n\n";


    cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Order ID ";
    cout<<setw(15)<<"Product Name";
    cout<<setw(15)<<"Order Status"<<endl;
    bool notfound = true;
    while (!check_pcancel.eof())
    {
        if (check_pcancel.read((char *)&order_obj, sizeof(COrders)))
        {
            if (strcmpi(order_obj.OMerchant_id, user_obj.user_id) == 0 && strcmpi(order_obj.Status, check_status) == 0)
            {
                notfound = false;
                cout <<setw(15)<< order_obj.Order_number << setw(15)
                     << order_obj.OProduct_name << setw(15) << order_obj.Status << "\n";
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product  not found\n";
    }
  
    check_pcancel.close();
}
void CProduct ::status_of_order()           //Function to see the status of an order.
{
    fstream check_pstatus;
    check_pstatus.open("order.txt", ios::binary | ios::in);
    if (!check_pstatus)
    {
        cout << "File doesnot exist";
    }
    cout << "\t\t\t\t\t\t " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tProduct Details";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Product Name\tProduct Price\tProduct Quantity\n";


    cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Product Name ";
    cout<<setw(15)<<"Product Price";
    cout<<setw(15)<<"Product Quantity";
    cout << setw(15)<<"Order Status"<<endl;
    bool notfound = true;
    while (!check_pstatus.eof())
    {
        if (check_pstatus.read((char *)&order_obj, sizeof(COrders)))
        {
            if (strcmpi(order_obj.OMerchant_id, user_obj.user_id) == 0)
            {
                notfound = false;
                cout<<setw(15) << order_obj.OProduct_name << setw(15)
                     << order_obj.Oproduct_price << setw(15)<< order_obj.Oproduct_quantity << setw(15)<<
                     order_obj.Status<<"\n";
            }
        }
    }
    if (notfound == true)
    {
        cout << "Product  not found\n";
    }
    
    check_pstatus.close();
}
