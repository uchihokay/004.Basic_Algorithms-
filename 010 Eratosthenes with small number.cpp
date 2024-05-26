#include<iostream>
#include <math.h>
using namespace std ;

int PrintPrimeNumber(int n ){
    int arr[10000];
    for (int i = 0 ; i <= n ; i++){
        arr[i] = 0;
    }
    for (int i = 2 ; i <= sqrt(n) ; i++) {        
        for (int j = i*i ; j <= n ; j += i){                      //duyetj j = i*i thay vi 2*i vi n da tu triet tieu r
            arr[j] = 1;                                            //vi du 5*2=10 , nhung 10 bi loai vi la boi cua 2 roi
        }
    }
    for (int i = 1 ; i <= n ; i++){
        if (arr[i] == 0){
            cout<<i<<" ";
        }
    }
}

int main(){
    int n ; cout<<"n = "; cin>>n;
    PrintPrimeNumber(n);
}