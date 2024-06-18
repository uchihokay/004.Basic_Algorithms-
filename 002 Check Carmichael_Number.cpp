// Viết chương trình tìm các số  Carmichael (là các số giả nguyên tố n thoả mãn
//  điều kiện là hợp số và thoả mãn  � � −1 ≡ 1 (��� � ) với mọi số nguyên 
// dương b nguyên tố cùng nhau với n) nhỏ hơn một số N cho trước nhập vào từ 
// bàn phím (với điều kiện  0 ≤ � ≤ 10000.
#include <iostream>
#include <cmath> 
#include <vector>
using namespace std ;
vector<int>primes;

bool Eratosthenes(int n ){
    vector<bool> isprime(n,true);
    isprime[0] = isprime[1] = false;
    for (int i = 2 ; i * i < n ; i++){
        for (int j = i*i ; j < n ; j+=i){
            isprime[j] = false;
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (isprime[i] == true){
            primes.push_back(i);
        }
    }
}

int GCD(int a , int b){
    int c = 1;
    while (c!=0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;  
}

bool Carmichael(int n){
    long long result, a , t;
    for (int i = 0 ; i < primes.size() ; i++){
        if (primes[i] == n){
            return false;
        }
    }
    for (int i = 2 ; i < n ; i++){
        a = i ; 
        t = n - 1;
        result = 1;
        if (GCD(a,n) == 1){
            while(t!=0){
                if (t % 2 == 0){
                    t = t/2;
                    a = (a * a) % n;
                }
                else{
                    t --;
                    result = (result * a) % n;
                }
            }
            if (result != 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n ; 
    cout<<"n = ";cin>>n;
    Eratosthenes(n);
    for (int i = 2 ; i < n ; i++){
        if (Carmichael(i) == true){
            cout<<i<<" ";
        }
    }
}
