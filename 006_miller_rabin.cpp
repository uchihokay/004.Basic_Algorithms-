#include <iostream>                         // xac suat kiem tra sai rat lon :))
#include  <math.h>
using namespace std ;

int GCD(int a , int b){
    int c = 1;
    while (c!=0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;  
}


int MillerRabin(int n){                           //( n -1) = 2^k * m
    int k , m ;
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
    cout<<"\n\t"<<n<<" - 1 = 2^"<<k<<" * "<<m;



    int result = 1;
    int b;
    for (int i = 2 ; i < n -2 ; i++){
        b = i;
    
    //tinh a^m mod n
        while(m != 0){
            if (m % 2 == 0){
                m = m / 2;
                b = ((long long)(b*b)) % n;
            }
            else{
                m--;
                result = ((long long)(result * b)) % n;
            }
        }
    //
        if (result != 1 && result != n-1){
            int c = 1;
            while (c <=k && result != (n-1)){
                result = ((long long)(result * result)) % n;
                if (result == 1){
                    cout<<"\n "<<n<<" is a composite .";
                    exit(0);
                }
                c++;
            }
            
        }
    }
    if (result != n-1){
            cout<<"\n "<<n<<" is a composite .";
            cout<<"?????";
            exit(0);
    }
    cout<<"\n "<<n<<" is a prime number .";
    

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
