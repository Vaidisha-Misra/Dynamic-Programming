#include <bits/stdc++.h>
using namespace std;

void r_f(int n,int sum,int &ans,vector<int>& nums){
    if(n>=nums.size()){
        ans=max(sum,ans);
        return;
    }
    r_f(n+2,sum+nums[n],ans,nums);
    r_f(n+1,sum,ans,nums);
}
int r_rob(vector<int>& nums) {
    int ans=0;
    r_f(0,0,ans,nums);
    return ans;
}
int m_f(int n,vector<int>& nums,vector <int> &dp){
    if(n>=nums.size()){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    int take=m_f(n+2,nums,dp)+nums[n];
    int leave=m_f(n+1,nums,dp);
    return dp[n]=max(take,leave);
}
int m_rob(vector<int>& nums) {
    vector <int> dp(nums.size()+2,-1);
    return m_f(0,nums,dp);
        
}

int t_rob(vector<int>& nums) {
    vector <int> dp(nums.size()+2,-1);
    int n=nums.size();
    dp[n+1]=0;
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int take=dp[i+2]+nums[i];
        int leave=dp[i+1];
        dp[i]=max(take,leave);
    }
    return dp[0];
}

int s_rob(vector<int>& nums) {
        
        int n=nums.size();
        int prev2=0;
        int prev=0;
        for(int i=n-1;i>=0;i--){
            int take=prev2+nums[i];
            int leave=prev;
            int curr=max(take,leave);
            prev2=prev;
            prev=curr;
        }

        return prev;
    }
int main(){
    vector <int> v={2,1,4,9};

    cout<<"Recursive solution "<<r_rob(v)<<endl;
    cout<<"Memoization solution "<<m_rob(v)<<endl;
    cout<<"Tabulation solution "<<t_rob(v)<<endl;
    cout<<"Space Optimization solution "<<s_rob(v)<<endl;
}