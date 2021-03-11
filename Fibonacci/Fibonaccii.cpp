#include <iostream>
using namespace std;

int n(int i){
    if (i == 1)
    return 1;
    else
    return i*n(i-1);
}
 
int main()
{
    int i;
    char again;
do
{
    cout<<"Input i:";
    cin>>i;
    while(i < 2 || i > 10)
    return i;
    cout<<"Process:";
    for(int process = 1; process <= i; process++)
    {
        cout<<process<<"*";
    }
    
    cout<<"\n";
    cout<<"Output:"<<n(i)<<endl;
    
    cout<<"\n";
    cout<<"Try Another[Y/N]:"; 
    cin>>again;
}   while(again =='Y' || again == 'y');
    
    return 0;
}
