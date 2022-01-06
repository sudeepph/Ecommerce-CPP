#pragma once
class CUser             //User Class
{
    public:
        char user_name[100];
        int user_type;
        char user_contact_num[100];
        char passwd[100];
        char user_mail [100];
        char user_id[100];
        char cust_address[100];
        char cour_area[100];
        char merch_location[100];
    public:
        void add_user();            //Function to add a new user.
        void login_user();          //Function for login.
        void Search_Product();      //Function to search for a product.
        void Buy_Product();         //Function to buy a product.
        void See_Status();          //Function to see status of an order.
        void Cancel_Order();        //Function to cancel an order.

};

CUser user_obj;