#include <iostream>
#include <cmath>
using namespace std ;

int ChangesToArr(int p,int t){
    int arr[100];
    int a = p;
    for (int i = 0 ; i < t ; i ++){
        int var = 8*(t-i-1);
        arr[i] = a / (int)pow(2,var);
        a = a % (int)pow(2,var);
    }
    for (int i = 0 ; i < t ; i ++){
        cout<<arr[i]<<" ";
    }cout<<"\n";
    
}

int main(){ 
    int p ;cout<<" p = "; cin>>p;
    int t = 4;
    int a,b;

    ChangesToArr(p,t);

}
