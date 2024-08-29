#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long sumOfPrimesBelow(int n) {
        if (n < 2) return 0; // There are no primes below 2
        
        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes
        
        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        // Sum all primes
        long long sum = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                sum += i;
            }
        }
        
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    int n = 2000000; // Change this value to test with different limits
    cout << "The sum of all primes below " << n << " is: " << s.sumOfPrimesBelow(n) << endl;
    
    return 0;
}
