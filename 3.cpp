#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long largest_prime_factor(long long x) {
        long long max_prime = -1;

        // Remove all factors of 2
        while (x % 2 == 0) {
            max_prime = 2;
            x /= 2;
        }

        // Remove factors of odd numbers from 3 onwards
        for (long long i = 3; i <= sqrt(x); i += 2) {
            while (x % i == 0) {
                max_prime = i;
                x /= i;
            }
        }

        // If x is still greater than 2, then it must be prime
        if (x > 2) {
            max_prime = x;
        }

        return max_prime;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    //main code]
    cout<<s.largest_prime_factor(600851475143);
    return 0;
}