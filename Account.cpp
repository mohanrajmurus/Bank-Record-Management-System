#include <iostream>
#include <fstream>
#include <cstring> 
#include <iomanip>
#include "Account.h"
using namespace std;

int Account::get_acc_no()
{
    return ac_no;
}
float Account::get_bal()
{
    return balance;
}
char Account::get_ac_type()
{
    return type;
}

void Account::Report()
{
    cout<<ac_no<<setw(10)<<ac_name<<setw(10)<<type<<setw(15)<<balance<<endl;
}
void Account::create_account()
{
    cout << "Enter the Account Number(5 digits): ";
    cin>>ac_no;
    cout << "Enter the Account holder Name: ";
    cin>>ac_name;
    cout <<"Choose the type of Account..\n1.Savings(S)\n2.Current(C)\n";
    cout << "Acc Type: ";
    cin >> type;
    type = toupper(type);
    switch(type)
    {
        case 'S':
        {
            cout << "For Savings Accout Initial deposit is Rs 500/-\n";
            cout << "Deposit Amount: ";
            cin >> balance;
            if(balance < 500)
            {
                cout << "Minimum deposit is Rs 500.\n";
                cout << "Deposit Amount: ";
                cin >> balance;
            }
        }
        break;
        case 'C':
        {
            cout << "For Savings Accout Initial deposit is Rs 1000/-\n";
            cout << "Deposit Amount: ";
            cin >> balance;
            if(balance < 1000)
            {
                cout << "Minimum deposit is Rs 1000.\n";
                cout << "Deposit Amount: ";
                cin >> balance;
            }
        }
        break;
        default:
            cout << "Invalid Type!!!\n";
    }
    cout << "Account Creater Sucessfully!!!!\n";
}

void Account::show_acc_details()
{
    cout << "\n*****************************\n";
    cout << "\tAccout details\t\n";
    cout << "Name: " << ac_name <<"\n";
    cout << "Acc No: " << ac_no <<"\n";
    cout << "Acc Type: " << type <<"\n";
    cout << "Available Balance: " << balance<<"\n";
}

void Account::deposit(float amt)
{
    balance += amt;
    cout << "Avalaible Balance : " << balance << endl;
    
}
void Account::withdraw(float amt)
{
    balance -= amt;
    cout << "Avalaible Balance : " << balance << endl;
}



void Create_Account()
{
    char ch;
    Account a;
    ofstream fout;
    fout.open("BankRec.dat",ios::out|ios::binary|ios::app);
    do
    {
        a.create_account();
        fout.write((char *)&a,sizeof(a));
        cout << "Add one more Entry [Y/N]:";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');
    fout.close();
}

void Dispaly_Account()
{
    Account a;
    int n,flag = 0;
    ifstream fin;
    fin.open("BankRec.dat",ios::out|ios::binary);
    cout << "\nEnter the Account Number: ";
    cin>>n;
    while(fin.read((char *)&a,sizeof(a)))
    {
        if(n == a.get_acc_no())
        {
            a.show_acc_details();
            flag++;
        }
    }
    fin.close();
    if(flag == 0)
        cout<<"\nAccount Number Not Found!!!!\n";
}
void Deposit()
{
    Account a;
    int n,flag = 0;
    float amt;
    fstream file;
    file.open("BankRec.dat",ios::out|ios::binary|ios::in);
    cout << "Enter the Account Number To Deposit: ";
    cin >> n;
    while(file.read((char *)&a,sizeof(a)))
    {
        if(n == a.get_acc_no())
        {
            a.show_acc_details();
            cout << "\n\n\tDeposit Amount\n";
            cout<<"Enter the amount to be deposited: ";
            cin>>amt;
            a.deposit(amt);
             cout << "\nRecord Updated\n";
             flag++;
        }
        int pos = sizeof(a);
        file.seekg(-pos,ios::cur);
        file.write((char *)&a,sizeof(a));
       
        
    }
    
    file.close();
    if(flag == 0)
        cout<<"Record Not Found!!!\n";
}
void Withdraw()
{
    Account a;
    int n,flag = 0;
    float amt;
    fstream file;
    file.open("BankRec.dat",ios::out|ios::binary|ios::in);
    cout << "Enter the Account Number To Withdraw: ";
    cin >> n;
    while(file.read((char *)&a,sizeof(a)))
    {
        if(n == a.get_acc_no())
        {
            int bal;
            a.show_acc_details();
            cout << "\n\n\tWithdraw Amount\n";
            cout<<"Enter the amount to be Withdraw: ";
            cin>>amt;
            bal = a.get_bal() - amt;
            if((bal < 500 && a.get_ac_type() == 'S') ||(bal < 1000 && a.get_ac_type() == 'C'))
                cout <<"\nInsufficient Balance!!!!\n";
            else
            {
                a.withdraw(amt);
                cout << "\nRecord Updated\n";
            }
             flag++;
        }
        int pos = sizeof(a);
        file.seekg(-pos,ios::cur);
        file.write((char *)&a,sizeof(a));
       
        
    }
    
    file.close();
    if(flag == 0)
        cout<<"Record Not Found!!!\n";
}

void Display_All_Acc()
{
    Account a;
    ifstream fin;
    fin.open("BankRec.dat",ios::binary);
    cout<<"AC.No."<<setw(10)<<"Name"<<setw(10)<<"AC Type"<<setw(15)<<"Available Balance"<<endl;
    while(fin.read((char *)&a,sizeof(a)))
        a.Report();
    fin.close();
}
void Delete_Account()
{
    Account a;
    int n, flag=0;
    ifstream fin;
    ofstream fout;
    fin.open("BankRec.dat",ios::binary|ios::out);
    fout.open("temp.dat",ios::binary);
    cout << "Enter the Account Number To Delete: ";
    cin >> n;
    while(fin.read((char *)&a,sizeof(a)))
    {
        if(n == a.get_acc_no())
        {
            a.show_acc_details();
            flag++;
            cout<<"\nFollowing Record will deleted!!!...\n";
        }
        else
            fout.write((char *)&a,sizeof(a));
    }
    fin.close();
    fout.close();
    remove("Bankrec.dat");
    rename("temp.dat","BankRec.dat");
    cout<<"Account deleted sucessfully...\n";
    if(flag == 0)
        cout<< "Account Number not found...\n";
}

