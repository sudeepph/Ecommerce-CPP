#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class CProduct          //Product class
{
public:
    char product_Id[100];
    char product_Name[100];
    char product_Type[100];
    char product_Price[100];
    char product_Quantity[100];
    char merchant_Id[100];

    void add_product();                 //Function to add a product.
    void search_product_name();         //Function to search for a product by name.
    void search_product_by_type();      //Function to search for a product by type.
    void prod_under_a_count();          //Function to view products under a count.
    void list_cancel_orders();          //Function to view the list of cancled orders.
    void status_of_order();             //Function to view the status of orders.
    void assign_courier();              //Function to assign a courirer person.
};

CProduct prod_obj;