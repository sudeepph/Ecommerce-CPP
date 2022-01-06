#pragma once
class COrders           //Order class
{
    public:
        char Ouser_id[100];
        char Oproduct_Id[100];
        char OProduct_name[100];
        char Oproduct_price[100];
        char courier_status[100];
        char Oproduct_quantity[100];
        char OMerchant_id[100];
        char Order_number[100];
        char Status[100];
        char Ocourier_id[100];
    
    public:
        void Buy_Product();             //Function to buy a product
        void Cancel_Product();          //Function to cancel a product
        void View_Status();             //Function to view the status of an order.
        void Update_Status();           //Function to update the status of an ordrer.
        void Addto_file();              //Function to add the details to a curresponding file.
        void list_of_orders();          //Function to view all orders.
        void list_of_orders_delivering();   //Function to view the pending delivey orders.
        void update_delivery();         //Function to update the delivery status.
};

COrders order_obj;