#include <iostream>
using namespace std;

int main(){
    int start,step,stop,count,accumulator;
    char again;
do{
    cout<<"Start:";
    cin>>start;
    cout<<"Step:";
    cin>>step;
    cout<<"Stop:";
    cin>>stop;
    cout<<"\n";
    
    for(int totalSteps = start; totalSteps <= stop; totalSteps += step)
    {
        cout<<totalSteps<<", ";
        count = totalSteps / step + 1;
        accumulator += totalSteps;
    }
    cout<<"\n";
    cout<<"Count:"<<count<<endl;
    cout<<"Sum:"<<accumulator<<endl;
    
    cout<<"\n";
    cout<<"Try Another[Y/N]:"; 
    cin>>again;
    cout<<"\n";
}   while(again =='Y' || again == 'y');
    return 0;
}