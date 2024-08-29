#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long fibo(){
        int lim=4000000;
        int sum=0;
        int a=1;
        int b=1;
        int c=a+b;
        while(c<lim){
            sum+=c;
            a=b+c;
            b=c+a;
            c=a+b;
        }
        return sum;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    cout<<s.fibo();
    return 0;
}