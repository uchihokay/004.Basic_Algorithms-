#include <iostream>                         // xac suat kiem tra sai rat lon :))
#include  <math.h>
using namespace std ;

int MillerRabin(int n){                           //( n -1) = 2^k * m
    int k , m;
    int a = n -1 ;
    k = 0;

    //phan tich n -1 =  2^k * m
    int var0 = 1;                               //var0 = 2^k
    while (a % 2 == 0){
    a = a / 2;
    k++;
    var0 = var0 * 2;
    }
    m = (n-1) / var0;

    for (int i = 2 ; i < n-1 ; i++){

        //truong hop : a^m = 1
        int b = i;                                 
        for (int i = 0 ; i < m-1; i++){
            b = ( b * 3) % n;
        }
        if (b == 1){
            cout<<n<<" is a Prime number";
            exit(0);
        }

        //truonghop : a^[(2^r)*m] = -1 
        int var1;                                    //var1 =   2^r        
        int c = i;
        for (int i = 0 ; i < k-1 ; i++){
            var1 = 1;
            var1 = (var1 * 2) % n;
            int var2 = var1 * m;                    //var2 = (2^r) * m;
            for (int i = 0 ; i < var1;i++){
                c = (c*2) % n;
            }
            if (c == -1){
                cout<<n<<" is a Prime number";
                exit(0);
            }
        }
    }
    cout<<n<<" is not a Prime number";
}

int main(){
    int n;
    cout<<"n = ";cin>>n;
    if (n % 2 == 0){
        cout<<n<<" is not a Prime number";
    }
    else {
        MillerRabin(n);
    }
}