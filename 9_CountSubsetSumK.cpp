#include <bits/stdc++.h>
using namespace std;
int f(int idx,int sum,vector<int> &arr,vector<vector<int>> &dp){
    if(sum==0) return 1;
    if(idx==0) return arr[idx]==sum?1:0;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int notTake=f(idx-1,sum,arr,dp);
    int take=0;
    if(arr[idx]<=sum) take=f(idx-1,sum-arr[idx],arr,dp);
    return dp[idx][sum]=take+notTake;
}
int m_subsetSumK(vector<int> &arr,int k){
    vector<vector<int>> dp(arr.size(),vector<int>(k+1,-1));
    return f(arr.size()-1,k,arr,dp);
}
int t_subsetSumK(vector<int> &arr,int k){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=k) dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<k+1;j++){
            int notTake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j) take=dp[i-1][j-arr[i]];
            dp[i][j]=take+notTake;

        }
    }
    return dp[n-1][k];

}

int s_subsetSumK(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> prev(k+1,0);
    prev[0]=1;
    if(arr[0]<=k) prev[arr[0]]=1;
    vector<int> curr(k+1,0);
    for(int i=1;i<n;i++){
        curr[0]=1;
        for(int j=1;j<k+1;j++){
            int notTake=prev[j];
            int take=0;
            if(arr[i]<=j) take=prev[j-arr[i]];
            curr[j]=take+notTake;

        }
        prev=curr;
    }
    return prev[k];

}

int main(){
    vector<int> v={1,2,2,3};
    int k=3;
    cout<<"Number of subsets using space optimization approach : "<<s_subsetSumK(v,k)<<endl;
    cout<<"Number of subsets using tabulation approach : "<<t_subsetSumK(v,k)<<endl;
    cout<<"Number of subsets using memoization approach : "<<m_subsetSumK(v,k)<<endl;
}