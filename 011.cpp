#include <iostream>
#include <cmath> 
using namespace std ;

bool PrimeCheck(int x){
    int var = 0;
    for (int i = 1 ; i<=x ; i++){
        if (x % i == 0){
            var++;
        }
    }
    if (var==2){
        return true;
    }
    else{
        return false;
    }
}

int UCLN(int a , int b){
    int c = 1;
    while (c!=0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;  
}
bool CarmichealCheck(int x, int n){                 //(x mux t) mod n = var
    int t = n - 1;      
    long long var = 1;
    while (t > 0) {                                //"thuat toan luy thua nhi phan
        if (t % 2 == 1) {
            var = (var * x) % n;
            t--;
        } else {
            x = ((long long)x * x) % n;
            t /= 2;
        }                                           //"
    }
    if (var == 1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n ; 
    cout<<"n = ";cin>>n;
    for (int j = 1 ; j < n ; j++){
        if (PrimeCheck(n) == false){
            for (int i = 2 ; i < n ; i++){
                if (UCLN(i,n) == 1){
                    if (CarmichealCheck(i,n)==true){
                        cout<<j<<" ";
                    }
                }
            }
        }
    }
}