#include <iostream>
#include <iomanip>
using namespace std;

void formative_set(double &);

void value_behavior(double &);

void summative_set(double &);


int main(){
    
    char again;
    double fa_weight, vb_weight, sa_weight;
    double final_grade;
    
    do{
        
        formative_set(fa_weight);
        
        value_behavior(vb_weight);
        
        summative_set(sa_weight);
        
        final_grade = fa_weight + vb_weight + sa_weight;
        
        if(final_grade > 75.00 && final_grade < 100){
            cout << "\n";
            cout << "FINAL GRADE:" << fixed << setprecision(1) << final_grade << " - PASSED" << endl;
        }
        
        else{
            cout << "\n";
            cout << "FINAL GRADE:" << final_grade << " - FAILED" << endl;
        }
        
        cout << "\n";
        cout << "Compute Another[Y/N]:";
        cin >> again;
        cout << "\n";
        
    }   while(again == 'Y' || again == 'y');
    
    return 0;
}

void formative_set(double &fa_weight){
    
    int input;
    double sum = 0.0;
    double fa_average;
    double *ptrformative;
    
    cout << "Input No of FAs: ";
    cin >> input;
    
    if(input > 12){
        cout << "\tThe maximum input of FA's is 12" << endl;
        cout << "\n";
        return;
    }
    
    ptrformative = new double[input];
    
    for(int i = 0; i < input; i++){
        cout << "FA[" << i << "]:";
        cin >> ptrformative[i];
        
        sum += ptrformative[i];
        
        fa_average = sum / input;
        
        fa_weight = fa_average * 0.15;
    }
    
    cout << "AVE:" << fixed << setprecision(2) << fa_average << endl;
    
    cout << "WEIGHT:" << fixed << setprecision(2) << fa_weight << endl;
    
    cout << "\n";
    
    delete [] ptrformative;
}

void value_behavior(double &vb_weight){
    
    int input;
    double equivalent;
    double vb_average;
    double behavior;

    cout << "\n";
    cout << "Input BV:" << endl;
    
    cout << "Attendance(No of Classes Attended):";
    cin >> input;
    
    if(input <= 12){
        
        equivalent = input / 12.0 * 50 + 50;
        
        cout << "Percentage Equivalent:" << fixed << setprecision(2) << equivalent << endl; 
        
        cout << "Behavior:" ;
        cin >> behavior;
        
        vb_average = behavior + equivalent;
        vb_average = vb_average / 2.0;
        cout << "AVE:" << fixed << setprecision(2) << vb_average << endl;
        
        vb_weight = vb_average * 0.10;
        
        cout << "WEIGHT:" << fixed << setprecision(2) << vb_weight << endl;
        cout << "\n";
    }
    
    else {
        cout << "The maximum input of Attendance is 12" << endl;
        cout << "\n";
        return;
    }
}

void summative_set(double &sa_weight){
    
    int input;
    double sa_average;
    double sum = 0.0;
    double *ptrsummative;
    
    cout << "Input No of SA: ";
    cin >> input;
    
    if(input > 6){
        cout << "\tThe maximum input of SA's is 6" << endl;
        cout << "\n";
        return;
    }
    
    ptrsummative = new double[input];
    
    for(int j = 0; j < input; j++){
        cout << "SA[" << j << "]:";
        cin >> ptrsummative[j];
        
        sum += ptrsummative[j];
        
        sa_average = sum / input;
        
        sa_weight = sa_average * 0.75;
    }
    
    cout << "AVE:" << fixed << setprecision(2) << sa_average << endl;
    
    cout << "WEIGHT:" << fixed << setprecision(2) << sa_weight << endl;
    
    
    delete [] ptrsummative;
}