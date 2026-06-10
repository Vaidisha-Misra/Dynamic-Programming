#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,string &a,string &b,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]=1+f(i-1,j-1,a,b,dp);
    f(i-1,j,a,b,dp);
    f(i,j-1,a,b,dp);
    return dp[i][j]=0;
}
int lcs(string &a,string &b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    f(a.size()-1,b.size()-1,a,b,dp);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
int main(){
    string a="abcjklp";
    string b="acjkp";
    cout<<lcs(a,b)<<endl;
    vector<int> x={1,2,3,2,1};
    vector<int> y={3,2,1,4,2,1};
    cout<<findLength(x,y);
    
}