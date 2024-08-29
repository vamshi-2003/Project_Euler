#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long l=999;
    long long sum(long long f){
        long long sup=l/f;
        return f*(sup)*(sup+1)/2;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    cout<<s.sum(3)+s.sum(5)-s.sum(15);
    return 0;
}