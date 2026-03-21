#include <bits/stdc++.h>
using namespace std;

// Recursive Solution TC O(2^n) and SC O(n) stack space
int r_f(int n){
    if(n<=1) return n;
    return r_f(n-1)+r_f(n-2);
}

// Memoization Solution TC O(n) and SC O(2n) stack space and dp array
int m_f(int n, vector<int> &dp){
    if(dp[n]!=-1) return dp[n];
    return dp[n]=m_f(n-1,dp)+m_f(n-2,dp);
}

// Tabulation Solution TC O(n) and SC O(n) dp array
int t_f(int n,vector<int> &dp1){
    for(int i=2;i<=n;i++){
        dp1[i]=dp1[i-1]+dp1[i-2];
    }
    return dp1[n];
}

// Space Optimization Solution TC O(n) and SC O(1)
int s_f(int n){
    if(n<=1) return n;
    int prev2=0;
    int prev=1;
    
    for(int i=2;i<=n;i++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}



int main(){

    cout<<"Recursive Fibonacci Solution "<<r_f(5)<<endl;

    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;

    cout<<"Memoization Fibonacci Solution "<<m_f(n,dp)<<endl;

    int n1;
    cin>>n1;
    vector<int> dp1(n1+1,-1);
    dp1[0]=0;
    dp1[1]=1;

    cout<<"Tabulation Fibonacci Solution "<<t_f(n1,dp1)<<endl;

    cout<<"Space Optimization Fibonacci Solution "<<s_f(5)<<endl;
    
    return 0;
}