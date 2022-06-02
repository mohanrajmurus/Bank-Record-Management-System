#include <iostream>
#include "Account.h"
using namespace std;

Account a;
int main()
{
    //Account a;
    int n;
    cout<<"\n\t\t\t************************";
	cout<<"\n\t\t\t BANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t************************\n";
    do
    {
        cout<<"\n\n\n\t\t\t\tMAIN MENU";
        cout<<"\n\n\t01. NEW ACCOUNT";
        cout<<"\n\n\t02. BALANCE ENQUIRY";
		cout<<"\n\n\t03. DEPOSIT AMOUNT";
		cout<<"\n\n\t04. WITHDRAW AMOUNT";
        cout<<"\n\n\t05. DISPLAY ALL ACCOUNT";
        cout<<"\n\n\t06. DELETE ACCOUNT";
        cout<<"\n\n\t07. EXIT";
        cout<<"\n\n\tSelect Your Option (1-7) ";
        cin>>n;
        switch(n)
        {
            case 1:
                Create_Account();//Add New Account
                break;
            case 2:
                Dispaly_Account();//Balance Enquiry
                break;
            case 3:
                Deposit();//deposit amount to account
                break;
            case 4:
                Withdraw();//withdraw amount
                break;
            case 5:
                Display_All_Acc();//display all accounts
                break;
            case 6:
                Delete_Account();
                break;
            case 7:
                cout<<"\n\n\n\n\t\t*** Thank you for Banking with us ***\n";
                break;
        }
    }while(n != 7);
}
