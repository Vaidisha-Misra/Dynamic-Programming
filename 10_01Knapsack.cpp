#include <bits/stdc++.h>
using namespace std;
int f(int idx,int sum,vector<int> &weight,vector<int> &profit,vector<vector<int>> &dp){
    if(sum==0) return 0;
    if(idx==0) return weight[idx]<=sum?profit[idx]:0;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int notTake=f(idx-1,sum,weight,profit,dp);
    int Take=0;
    if(sum>=weight[idx]) Take=f(idx-1,sum-weight[idx],weight,profit,dp)+profit[idx];
    return dp[idx][sum]=max(Take,notTake);
}
int m_knapsack(vector<int> &weight,vector<int> &profit,int &capacity){
    vector<vector<int>> dp(weight.size(),vector<int>(capacity+1,-1));
    return f(weight.size()-1,capacity,weight,profit,dp);
}
int t_knapsack(vector<int> &weight,vector<int> &profit,int &capacity){
    vector<vector<int>> dp(weight.size(),vector<int>(capacity+1,0));
    for(int i=0;i<=capacity;i++){
        dp[0][i]=weight[0]<=i?profit[0]:0;
    }
    for(int i=1;i<weight.size();i++){
        for(int j=1;j<=capacity;j++){
            int notTake=dp[i-1][j];
            int Take=0;
            if(j>=weight[i]) Take=dp[i-1][j-weight[i]]+profit[i];
            dp[i][j]=max(Take,notTake);
        }
    }
    return dp[weight.size()-1][capacity];
}
int s1_knapsack(vector<int> &weight,vector<int> &profit,int &capacity){
    
    vector<int> prev(capacity+1,0),curr(capacity+1,0);
    for(int i=0;i<=capacity;i++){
        prev[i]=weight[0]<=i?profit[0]:0;
    }
    for(int i=1;i<weight.size();i++){
        for(int j=1;j<=capacity;j++){
            int notTake=prev[j];
            int Take=0;
            if(j>=weight[i]) Take=prev[j-weight[i]]+profit[i];
            curr[j]=max(Take,notTake);
        }
        prev=curr;
    }
    return prev[capacity];
}
int s_knapsack(vector<int> &weight,vector<int> &profit,int &capacity){
    
    vector<int> dp(capacity+1,0);
    for(int i=0;i<=capacity;i++){
        dp[i]=weight[0]<=i?profit[0]:0;
    }
    for(int i=1;i<weight.size();i++){
        for(int j=capacity;j>=0;j--){
            int notTake=dp[j];
            int Take=0;
            if(j>=weight[i]) Take=dp[j-weight[i]]+profit[i];
            dp[j]=max(Take,notTake);
        }
    }
    return dp[capacity];
}

int main(){
    vector<int> w={3,2,5};
    vector<int> p={30,40,60};
    int cap=6;
    cout<<m_knapsack(w,p,cap)<<endl;
    cout<<t_knapsack(w,p,cap)<<endl;
    cout<<s1_knapsack(w,p,cap)<<endl;
    cout<<s_knapsack(w,p,cap)<<endl;
}