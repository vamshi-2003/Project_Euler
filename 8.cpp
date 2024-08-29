#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxProduct(const string &number, int windowSize) {
        long long maxProduct = 0;
        long long currentProduct = 1;
        int zeroCount = 0;

        // Initialize the first window
        for (int i = 0; i < windowSize; ++i) {
            if (number[i] == '0') {
                zeroCount++;
            } else {
                currentProduct *= (number[i] - '0');
            }
        }

        if (zeroCount == 0) {
            maxProduct = currentProduct;
        }

        // Slide the window across the number
        for (int i = windowSize; i < number.size(); ++i) {
            int start = i - windowSize;
            int end = i;

            // Remove the influence of the digit going out of the window
            if (number[start] == '0') {
                zeroCount--;
            } else {
                currentProduct /= (number[start] - '0');
            }

            // Add the influence of the new digit coming into the window
            if (number[end] == '0') {
                zeroCount++;
            } else {
                currentProduct *= (number[end] - '0');
            }

            // Update the maximum product if there are no zeros in the current window
            if (zeroCount == 0) {
                maxProduct = max(maxProduct, currentProduct);
            }
        }

        return maxProduct;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The large number split into lines, which are concatenated into a single string
    string number = "73167176531330624919225119674426574742355349194934"
                    "96983520312774506326239578318016984801869478851843"
                    "85861560789112949495459501737958331952853208805511"
                    "12540698747158523863050715693290963295227443043557"
                    "66896648950445244523161731856403098711121722383113"
                    "62229893423380308135336276614282806444486645238749"
                    "30358907296290491560440772390713810515859307960866"
                    "70172427121883998797908792274921901699720888093776"
                    "65727333001053367881220235421809751254540594752243"
                    "52584907711670556013604839586446706324415722155397"
                    "53697817977846174064955149290862569321978468622482"
                    "83972241375657056057490261407972968652414535100474"
                    "82166370484403199890008895243450658541227588666881"
                    "16427171479924442928230863465674813919123162824586"
                    "17866458359124566529476545682848912883142607690042"
                    "24219022671055626321111109370544217506941658960408"
                    "07198403850962455444362981230987879927244284909188"
                    "84580156166097919133875499200524063689912560717606"
                    "05886116467109405077541002256983155200055935729725"
                    "71636269561882670428252483600823257530420752963450";

    Solution s;
    int windowSize = 13;
    cout << "The greatest product of " << windowSize << " adjacent digits is: " << s.maxProduct(number, windowSize) << endl;

    return 0;
}
