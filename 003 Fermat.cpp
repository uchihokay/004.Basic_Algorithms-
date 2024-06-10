#include <iostream>
using namespace std ;

int Fermat(int n ){
    int a , t , result;
    for (int i = 0 ; i < n - 2 ; i ++){
        a = 2;
        t = n - 1;
        result = 1;
        while(t != 0){
            if (t % 2 == 0){
                t = t/2;
                a = ((long long)(a * a)) % n;
            }
            else {
                t--;
                result = ((long long)(result * a)) % n;
            }
        }
        if (result != 1){
            cout<<"\n"<<n<<" is a composite .";
            exit(0);
        }
        else {
            a++;
        }
    }
    cout<<"\n"<<n<<" is a prime .";
}

int main(){
    int n ; cout<< "n = "; cin>>n;
    Fermat(n);
}
