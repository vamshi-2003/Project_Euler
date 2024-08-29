#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isPalindrome(int number) {
    string str = to_string(number);
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
    int largestPalindromeProduct(int n) {
    int upperLimit = 1;
    for (int i = 0; i < n; ++i) {
        upperLimit *= 10;
    }
    int lowerLimit = upperLimit / 10;
    int maxPalindrome = 0;

    for (int i = upperLimit - 1; i >= lowerLimit; --i) {
        for (int j = i; j >= lowerLimit; --j) {
            int product = i * j;
            if (product <= maxPalindrome) {
                break; // Products will decrease after this point
            }
            if (isPalindrome(product)) {
                maxPalindrome = product;
            }
        }
    }
    return maxPalindrome;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    cout<<s.largestPalindromeProduct(3);
    return 0;
}