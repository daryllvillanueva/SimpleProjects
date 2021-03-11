#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name[2] = {"default"};
    string pass[2] = {"admin"};
    string userName, userPassword;
    bool userInfo;
    int attempt = 3;
    char again, option;
    do{
        cout<<"Username: ";
        cin>>userName;
        
        cout<<"Password: ";
        cin>>userPassword;
        
        for (int x = 0; x < 2; x++){
            if(userName == name[x] && userPassword == pass[x]){
                userInfo = true;
                cout<<"\nUsername: correct UN"<<endl;
                cout<<"Password: correct PW"<<endl;
                cout<<"\nWelcome to my World"<<endl;
            }
        }
        
        cout<<"\nChange Username and Password [Y/N]: ";
        cin>>option;
        cout<<"\n";
        
        if(option == 'Y' || option == 'y'){
            cout<<"Username: ";
            cin>>userName;
            
            name[1] = userName;
            
            cout<<"Password: ";
            cin>>userPassword;
            
            pass[1] = userPassword;
        }
        
        if(!userInfo){
            cout<<"\nUsername: wrong UN"<<endl;
            cout<<"Password: wrong PN"<<endl;
            --attempt;
            if(!attempt){
                cout<<"(for the 3rd time)"<<endl;
                cout<<"\nYou've exceeded the allowable number of tries! Try again later"<<endl;
                return 0;
            }
        }
        
        cout<<"\nENTER [Y/N]: ";
        cin>>again;
        cout<<"\n";
    }   while (again == 'Y' || again == 'y');
    
    return 0;
}