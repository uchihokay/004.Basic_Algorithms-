#include <iostream>              
using namespace std ;               

int Decompose(int n , int arr0[10000] ){
    int var1 = 0;
    for (int i = 1 ; i < n ; i++){                          //tim cac snt < n
        int var2 = 0;
        for (int j = 1 ; j < n ; j++){
            if (i % j ==0 ){
                var2 ++;
            }
        }
        if (var2 == 2){
            arr0[var1] = i;
            var1++;
        }
    }

    int var2=0;                                            // chia n cho cac snt tu be -> lon
    while (n > 1){
        if (n % arr0[var2] == 0){
            n = n/arr0[var2];
            cout<<arr0[var2]<<" ";
        }
        else {
            var2++;
        }
    }
}

int main(){
    int arr0[10000];
    int var1 = 0;
    int n ; cout<<"n = ";cin>>n;
    Decompose(n,arr0);
}