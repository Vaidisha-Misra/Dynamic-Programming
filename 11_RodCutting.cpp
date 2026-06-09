#include <bits/stdc++.h>
using namespace std;

int f(int idx,int len,vector<int> &rodPrices,vector<vector<int>> &dp){

    if(len==0) return 0;
    if(idx==0) return len*rodPrices[idx];
    if(dp[idx][len]!=-1) return dp[idx][len];
    int notTake=f(idx-1,len,rodPrices,dp);
    int Take=-1e9;
    if(len>=idx+1) Take=f(idx,len-idx-1,rodPrices,dp)+rodPrices[idx];
    return dp[idx][len]=max(notTake,Take);
}

int rodCutting(int n,vector<int> rodPrices){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(n-1,n,rodPrices,dp);
}
int main(){
    vector<int> r={1,6,8,9,10,19,7,20};
    int len=8;
    cout<<rodCutting(len,r);
}