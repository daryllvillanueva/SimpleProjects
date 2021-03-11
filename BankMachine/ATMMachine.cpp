#include<iostream>    
#include<string>        
#include<iomanip>     
using namespace std; 

void displayBalance(double&);
void transactDeposit(double&);
void transactWithdrawal(double&);

int main(){
	char pin[6]= {'m','a','d','1','2','3'};
	string input, verifyPin;
	double balance = 0.0;
	char option, again;
	int attempt = 3;
	bool login;
	
	do{
 	    system ("CLS");
	    cout<<"\tMAD AUTOMATED TELLER MACHINE IS ONLINE\n"<<endl;
      	cout<<"\t\tINPUT YOUR 6 DIGIT PIN: ";
        cin>>input;
        if(input == pin || input == verifyPin){
            login = true;
            TRANSACTION:
            cout<<"[C]HECK BALANCE"<<endl;
            cout<<"[D]EPOSIT CASH"<<endl;
            cout<<"[W]ITHDRAW CASH"<<endl;
            cout<<"C[H]ANGE PIN"<<endl;
            cout<<"TRANSACTION [C][D][W][H]:";
            cin>>option;
            switch(option){
                case 'C': case 'c':
                    displayBalance(balance);
                    break;
                case 'D': case 'd':
                    transactDeposit(balance);
                    break;
                case 'W': case 'w':
                    transactWithdrawal(balance);
                    break;
                case 'H': case 'h': {
                    string currentPin, newPin;
                    cout<<"\tMAD AUTOMATED TELLER MACHINE IS ONLINE\n"<<endl;
                    cout<<"\t\tINPUT YOUR CURRENT PIN: ";
                    cin>>currentPin;
                    
                    if(currentPin != pin && currentPin != verifyPin){
                        cout<<"\t\t\tINVALID INPUT\n";
                        return 1;
                    }
                    
                    cout<<"\t\tINPUT YOUR NEW 6 DIGIT PIN: ";
                    cin>>newPin;
                    
                    if(newPin.length() != 6){
                        cout<<"\t\t\tINVALID INPUT\n";
                        return 1;
                    }
                    
                    cout<<"\t\tVERIFY YOUR NEW PIN: ";
                    cin>>verifyPin;
                    
                    if(verifyPin != newPin){
                        cout<<"\n\t\t\tINVALID INPUT\n";
                        return 1;
                    }
                    else{
                        cout<<"\t\t\tYOU HAVE CHANGED YOUR PIN"<<endl;
                    }
                }
                    break;
                default:
                cout<<"\t\tINVALID INPUT"<<endl;
                break;
	    goto TRANSACTION;
            }
        }
        if (!login){
            cout<<"\t\tYOU INPUT A WRONG PIN"<<endl;
            --attempt;
            if(!attempt){
                cout<<"\t\t (for the 3rd time)"<<endl;
                cout<<"\nYou've exceeded the allowable number of tries! Try again later"<<endl;
                return 1;
            }
        }
        cout<<"\nENTER[Y/N]:";
        cin>>again;
        cout<<"\n";
    } while (again == 'Y' || again == 'y');
    return 0;
}

void displayBalance(double &balance){
    cout<<"\tMAD AUTOMATED TELLER MACHINE IS ONLINE\n"<<endl;
    cout<<"\t\t YOUR CURRENT BALANCE IS:"<<endl;
    cout<<"\t\t\tPhp"<<fixed<<setprecision(2)<<balance<<endl;
}

void transactDeposit(double &balance){
    double calcuInterest;
    double interest = 0.05;
    double depositCash;
    cout<<"\tMAD AUTOMATED TELLER MACHINE IS ONLINE\n"<<endl;
    cout<<"\t\tINSERT YOUR CASH"<<endl;
    cout<<"\t\tPhp";
    cin>>depositCash;
    for(int i = 0; i < 2; i++){
        if(depositCash <= 0){
            cout<<"\t\tINVALID AMOUNT, TRY AGAIN\n"<<endl;
            cout<<"\t\tINSERT YOUR CASH"<<endl;
            cout<<"\t\tPhp";
            cin>>depositCash;
        }
    }
    if(depositCash > 0){
        balance += depositCash;
        cout<<"\t\tYOU HAVE DEPOSITED Php"<<fixed<<setprecision(2)<<depositCash<<endl;
        if(balance > 10000){
            calcuInterest = (balance * interest) / 100;
	 calcuInterest = calcuInterest + balance;
	 balance = calcuInterest;
        }
    }
}

void transactWithdrawal(double &balance){
    double calcuBank;
    double bankCharge = 0.02;
    double withdrawCash;
    cout<<"\tMAD AUTOMATED TELLER MACHINE IS ONLINE\n"<<endl;
    cout<<"\t\tINPUT THE AMOUNT OF WITHDRAWAL"<<endl;
    cout<<"\t\t\tPhp";
    cin>>withdrawCash;
    for(int x = 0; x < 2; x++){
        if(withdrawCash > balance || withdrawCash <= 0){
            cout<<"\t\tCASH NOT ENOUGH, TRY AGAIN\n"<<endl;
            cout<<"\t\tINPUT THE AMOUNT OF WITHDRAWAL"<<endl;
            cout<<"\t\t\tPhp";
            cin>>withdrawCash;
        }
    }
    
    if(withdrawCash < balance){
	calcuBank = balance - (bankCharge * withdrawCash);
	balance = calcuBank;
        balance -= withdrawCash;
        cout<<"\t\tYOU HAVE WITHDREW Php"<<fixed<<setprecision(2)<<withdrawCash<<endl;
        if(balance < 5000){
            cout<<"Cant withdraw now"<<endl;
        }
    }
}