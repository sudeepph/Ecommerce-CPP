#include "User.cpp"
#include "customer.cpp"
#include "product.cpp"
#include "courier.cpp"
#include "User.h"
#include "product.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;



int main()    //Login and Sign Up
{
    int choice=0;
    while(choice !=3){
        cout << "\n\n***********************************\n";
        cout << "\tE-COMMERCE SYSTEM\n";
        cout << "***********************************\n";
        cout << "\t1. Sign Up\n";
        cout << "\t2. Login in\n";
        cout << "\t3. Exit\n\n";

        cout << "Enter the choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "signup Function";
           user_obj.add_user();
            break;
        case 2:
           cout << "Sign in Function";
          user_obj.login_user();
           break;
        case 3:
            cout<< "exiting";
            exit(0);
            break;
        default:
            cout <<"Wrong choice";
        }
    }
        
}