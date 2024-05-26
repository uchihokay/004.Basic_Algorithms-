#include <iostream>                              //Q-prime la so co 4 uoc 
using namespace std ;

bool CheckQPrime(int x){
    int a = 0 ;                                    //dem so uoc
    for (int i = 1 ; i <= x ; i++){
        if (x % i == 0){
            a++;
        }
    }
    if (a == 4){
        return true;
    }
    else {
        return false ;
    }
}

int main(){
    int n ;                                     //gioi han < n
    cout<<"n = ";cin>>n;
    for (int i = 1 ; i < n ; i++){
        if (CheckQPrime(i) == true){
            cout<<i<<" ";
        }
    }
}
