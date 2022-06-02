#ifndef ACCOUNT_H
#define ACCOUNT_H
//class decleration
class Account
{
private:
    int ac_no;
    char ac_name[20];
    char type;
    float balance;
public:
//member functions
    void create_account();//create new account
    void show_acc_details();//display details
    void deposit(float);//deposit
    void withdraw(float);
    int get_acc_no();
    float get_bal();
    char get_ac_type();
    void Report();
};

void Create_Account();
void Dispaly_Account();
void Display_All_Acc();
void Deposit();
void Withdraw();
void Delete_Account();





#endif // ACCOUNT_H
