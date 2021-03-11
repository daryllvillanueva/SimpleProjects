#include <iostream>
#include <cmath>
using namespace std;

int get_Sides(int j, int i){
    int s;
    s = (pow(j, 2) - pow(i, 2));
    s = sqrt(s);
    return s;
}

int get_Hypotenuse(int x, int y){
    int h;
    h = (pow(x, 2) + pow(y, 2));
    h = sqrt(h);
    return h;
}

int main()
{
    double a, b, c;
    char input, again;
do
{
    cout<<"Pythagorean Theorem"<<endl;
    cout<<"\n";
    cout<<"Compute for"<<endl;
    cout<<"\n";
    cout<<"[a] altitude"<<endl;
    cout<<"[b] base"<<endl;
    cout<<"[c] hypotenuse"<<endl;
    cout<<"\n";
    
    cout<<"Input [a|b|c]:";
    cin>>input;
    cout<<"\n";
     if (input == 'c')
    {
        cout<<"Pythagorean Theorem"<<endl;
        cout<<"Function 1 (find c)"<<endl;
        cout<<"\n";
        cout<<"Input a:";
        cin>>a;
        cout<<"Input b:";
        cin>>b;
        cout<<"Computed value of c:"<<get_Hypotenuse(a, b)<<endl;
    }
    if (input == 'a')
    {
        cout<<"Pythagorean Theorem"<<endl;
        cout<<"Function 2 (find a)"<<endl;
        cout<<"\n";
        cout<<"Input c:";
        cin>>c;
        cout<<"Input b:";
        cin>>b;
        cout<<"Computed value of a:"<<get_Sides(c, b)<<endl;
    }
    
    if (input == 'b')
    {
        cout<<"Pythagorean Theorem"<<endl;
        cout<<"Function 3 (find b)"<<endl;
        cout<<"\n";
        cout<<"Input c:";
        cin>>c;
        cout<<"Input a:";
        cin>>a;
        cout<<"Computed value of b:"<<get_Sides(c, a)<<endl;
    }
    
    cout<<"\n";
    cout<<"Try Another[Y/N]:"; 
    cin>>again;
}   while(again =='Y' || again == 'y');
    
    return 0;
}