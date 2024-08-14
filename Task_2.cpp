#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

class Account{
    public:
        int accountnumber;
        string account_holder_name;
        double bank_balance;

        Account(int accNumber, string name, double balance){
            accountnumber = accNumber;
            account_holder_name = name;
            this -> bank_balance = balance;
        }

        void deposit(){
            int AccNum;
            cout<<"Enter Account number - ";
            cin>>AccNum;
            if(AccNum == accountnumber){
                double amt;
                cout<<"Amount : ";
                cin>>amt;
                bank_balance += amt;
                cout<<"Your A/C "<<accountnumber<<" Credited INR "<<amt<<endl;
                cout<<"Account Balance : "<<bank_balance<<" Rupees"<<endl;
            }
            else{
                cout<<"Account number does not match, Please try again"<<endl;
                exit(0);
            }
        }

        void withdraw(){
            int AccNum;
            cout<<"Enter Account number - ";
            cin>>AccNum;
            if(AccNum == accountnumber){
                double amt;
                cout<<"Amount : ";
                cin>>amt;
                bank_balance -= amt;
                cout<<"Your A/C "<<accountnumber<<" Debited INR "<<amt<<endl;
                cout<<"Account Balance : "<<bank_balance<<" Rupees"<<endl;
            }
            else{
                cout<<"Account number does not match, Please try again"<<endl;
                exit(0);
            }
        }

        void transfer(){
            int acno;
            cout<<"Receiver Account Number : ";
            cin>>acno;
            int amt;
            cout<<"Amount - ";
            cin>>amt;
            bank_balance -= amt;
            cout<<"Transaction Successful"<<endl;
            cout<<amt<<" Rupees is successfully transfered to A/c number "<<acno<<endl;
        }

        void balanceInq(){
            cout<<"Account Balance: "<<bank_balance<<" Rupees"<<endl;
        }

};
int main(){
    vector<Account> acc;
    int choice;
    cout<<"\n----- Banking System -----\n"<<endl;

    while(true){
        cout<<"--------------------"<<endl;
        cout<<"1. Creat Account."<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. Transfer"<<endl;
        cout<<"5. Balance Inquiry"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"--------------------"<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1:{
                    string name;
                    double balance;
                    int accountnumber;
                    cout<<"Account Number :";
                    cin>>accountnumber;     //Accouont number must be 10 digits 
                    if(to_string(accountnumber). length() != 10){      
                        cout<<"Ivalid input!!"<<endl<<"Please enter the A/c no. currectly"<<endl;
                        exit(0);
                    }
                    cout<<"Enter your name - ";
                    cin.ignore();
                    getline(cin, name);
                    cout<<"Initial Diposit Amount - ";
                    cin>>balance;
                    acc.push_back(Account(accountnumber, name, balance));   
                    cout<<"Account Generated Successfully "<<endl;
                    break;
                }
            case 2:{
                    acc[0].deposit();
                    break;
                }
            case 3:{
                    acc[0].withdraw();
                    break;
                } 
            case 4:{
                    acc[0].transfer();
                    break;
            }

            case 5:{
                    acc[0].balanceInq();
                    break;
            }

            case 6:{
                    cout<<"Thank You!!"<<endl<<"Visit Us Again"<<endl;
                    exit(0);
            }
            default:
                cout<<"Invalid Input!!"<<endl;
                break;
        }
    }

}