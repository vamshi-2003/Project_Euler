#include <iostream>
using namespace std;

int main() {
    int n = 100;
    
    long long sum_of_squares = (long long)n * (n + 1) * (2 * n + 1) / 6;
    
    long long sum = (long long)n * (n + 1) / 2;
    long long square_of_sum = sum * sum;
    
    long long difference = square_of_sum - sum_of_squares;
    
    cout << "The difference is: " << difference << endl;
    
    return 0;
}
