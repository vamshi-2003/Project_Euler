#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sieve(int n) {
        // Estimate the initial limit
        int limit = max(15, int(n * log(n) * 1.2));
        vector<bool> is_prime(limit + 1, true);
        int count = 0;
        is_prime[0] = is_prime[1] = false;

        while (count < n) {
            // Sieve of Eratosthenes
            for (int i = 2; i <= limit; ++i) {
                if (is_prime[i]) {
                    if (++count == n) return i;
                    for (int j = i * i; j <= limit; j += i) {
                        is_prime[j] = false;
                    }
                }
            }

            // Increase the limit and reset the sieve if needed
            limit *= 2;
            is_prime.resize(limit + 1, true);
            fill(is_prime.begin() + (limit / 2 + 1), is_prime.end(), true);
            is_prime[0] = is_prime[1] = false;
        }

        return -1; // Just a fallback; ideally, this should not be reached
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;
    int n = 10001; // Change this to find a different n-th prime
    cout << "The 10001st prime number is: " << s.sieve(n) << endl;

    return 0;
}
