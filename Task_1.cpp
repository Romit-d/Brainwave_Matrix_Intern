#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

const double Max_balance = 500000.0;

bool checkaccno(long long accno){
    if(accno >= 1000000000 && accno < 10000000000){
        return true;
    }
    cout<<"Invalid Account Number"<<endl;
    return false;
}

bool checkpin(int pin){
    if(pin >=1000 && pin < 10000){
        return true;
    }
    cout<<"Invalid ATM PIN"<<endl;
    return false;
}

void checklimit(int amount, int balance){
    if(amount > balance){
        cout<<"Isufficiant Funds!!"<<endl;
    }
}

void checkbalance(int balance, long long accno){
    char response;
    cout<<"Do you want to Check Your Account Balance (Y/N): ";
    cin>>response;
    if(response == 'Y' || response == 'y'){
        cout<<"Account Number : "<<accno<<endl;
        cout<<"Balance : Rs."<<balance<<endl;
    }
    else {
        cout<<"Returning to Main Menu"<<endl;
    }
}

void rating(){
    cout<<" 1 - Poor"<<endl;
    cout<<" 2 - Unatisfactory"<<endl;
    cout<<" 3 - Satisfactory"<<endl;
    cout<<" 4 - Above Standards"<<endl;
    cout<<" 5 - Excellent"<<endl;
}

void disp(int rate){
    if(rate == 1){
        cout<<"We're disappointed to hear that. We'll try our best to improve your experience next time"<<endl;
    }
    else if (rate == 2){
        cout<<"Thank you for your feedback!"<<endl;
    }
    else if(rate == 3){
        cout<<"We're glad you're satisfied!"<<endl;
    }
    else if(rate == 4){
        cout<<"We appreciate the excellent rating!"<<endl;
    }
    else{
        cout<<"Wow! Thanks for being a great customer!"<<endl;
    }
    
}

int main(){
    int pin, choice, rate;
    long long accno;
    double amount;
    srand(time(NULL));
    double balance = rand() % 10001;

    cout<<"Enter the Account Number - ";
    cin>>accno;
    if(!checkaccno(accno)){
        return 1;
    }
    cout<<"Enter the 4 digit Pin - ";
    cin>>pin;
    if(!checkpin(pin)){
        return 1;
    }
    while (true)
    {
        cout<<"\n-: Main Menu :-"<<endl;
        cout<<"1. Check Balance "<<endl;
        cout<<"2. Withdraw Chash "<<endl;
        cout<<"3. Exit \n"<<endl;
        cout<<"Enter your choice - ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Account Balance : "<<balance<<endl;
                break;
            
            case 2:
                cout<<"Enter the Amount - ";
                cin>>amount;
                cout<<"Transaction is Under Process.."<<endl;
                checklimit(amount, balance);
                if(amount <=  balance){
                    balance -= amount;
                    cout<<"Transaction Successful"<<endl<<"Please collect Your Cash"<<endl;
                }
                checkbalance(balance, accno);
                break;
            
            case 3:
                cout<<"Thank You for Using our ATM service, Have a nice day"<<endl;
                cout<<"Please Rate Your Experience (1 - 5) : "<<endl;;
                rating();
                cin>>rate;
                disp(rate);    
                return 0;

            default :
                cout<<"Invalid Choice !! Please try again."<<endl;
                break;
        }
    }
    
}