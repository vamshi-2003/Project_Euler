#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTripletProduct(int sum) {
        // Iterate over possible values of 'a'
        for (int a = 1; a < sum / 3; ++a) {
            // Iterate over possible values of 'b'
            for (int b = a + 1; b < sum / 2; ++b) {
                int c = sum - a - b;
                
                // Check if the current triplet is a Pythagorean triplet
                if (a * a + b * b == c * c) {
                    return a * b * c; // Return the product of the triplet
                }
            }
        }
        return -1; // In case no triplet is found
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int sum = 1000;
    cout << "The product of the Pythagorean triplet for sum " << sum << " is: " << s.findTripletProduct(sum) << endl;

    return 0;
}
