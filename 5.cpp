#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int h(int a,int b){
        if(b==0)
            return a;
        return h(b,a%b);
    }
    int l(int a,int b){
        return (a/h(a,b))*b;
    }
    int ans(int n){
        int lc=1;
        for(int i=2;i<=n;i++)lc=l(i,lc);
        return lc;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    cout<<s.ans(20);
    return 0;
}