#include <iostream>
using namespace std ;

int GCD(int a){
    int b , d ;
    for (int i = 2 ; i <= a ; i++){
        b = i;
        d = a;
        while (b!=0){
            int c = d % b;
            d = b ;
            b = c ;
        }
        if (d == 1){
            return i;break;
        }
        else {
            continue;
        }
    }
}

int Fermat(int n ){
    for (int i = 2 ; i < n ; i++){                  //x^y = var (mod i)
        int x = GCD(i);
        int y = i-1;
        int var = 1;
        while(y!=0){
            if (y % 2 == 0){
                x = ((long long)x * x ) % i;
                y = y / 2;
            }
            else {
                var = (var * x) % i;
                y --;
            }
        }
        if (var == 1){
            cout<<i<<" ";
        }
        else {
            continue;
        }
    }
}


int main(){
    int n ; cout<< "n = "; cin>>n;
    Fermat(n);
}
