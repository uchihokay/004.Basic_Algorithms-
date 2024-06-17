#include <iostream>
#include <vector>
using namespace std;

// Hàm Sàng nguyên tố Eratosthenes
void SieveOfEratosthenes(int n, vector<int>& primes) {
    // Tạo một vector đánh dấu các số nguyên từ 0 đến n-1
    vector<bool> isPrime(n, true);
    
    // 0 và 1 không phải là số nguyên tố
    isPrime[0] = isPrime[1] = false;

    // Bắt đầu từ số nguyên tố đầu tiên là 2
    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            // Đánh dấu tất cả các bội số của p là không phải số nguyên tố
            for (int i = p * p; i < n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Thu thập tất cả các số nguyên tố vào vector primes
    for (int p = 2; p < n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}

int main() {
    int n;
    cout << "Nhập n: "; cin >> n;

    // Vector để lưu trữ các số nguyên tố
    vector<int> primes;

    // Gọi hàm Sàng nguyên tố Eratosthenes
    SieveOfEratosthenes(n, primes);

    // In ra các số nguyên tố nhỏ hơn n
    cout << "Các số nguyên tố nhỏ hơn " << n << " là: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
