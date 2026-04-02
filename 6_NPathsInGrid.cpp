#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,int n,int m){
    if(i==m-1 && j==n-1) return 1;
    int right=0,down=0;
    if(i<m-1) down=f(i+1,j,n,m);
    if(j<n-1) right=f(i,j+1,n,m);
    return down+right;
}
int uniquePaths(int m, int n) {
    
    return f(0,0,n,m);
}
int m_f(int i,int j,int n,int m,vector<vector<int>> &dp){
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int right=0,down=0;
    if(i<m-1) down=m_f(i+1,j,n,m,dp);
    if(j<n-1) right=m_f(i,j+1,n,m,dp);
    return dp[i][j]=down+right;
}
int m_uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return m_f(0,0,n,m,dp);
}
int t_uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,1));
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    return dp[0][0];
}
int s_uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,1));
    vector<int> prev(n,1);
        
    for(int i=m-2;i>=0;i--){
        vector<int> curr(n,1);
        for(int j=n-2;j>=0;j--){
            curr[j]=prev[j]+curr[j+1];
        }
        prev=curr;
    }
    return prev[0];
}
int main(){
    cout<<"Recursive Solution "<<uniquePaths(3,7)<<endl;
    cout<<"Memoization Solution "<<m_uniquePaths(3,7)<<endl;
    cout<<"Tabulation Solution "<<t_uniquePaths(3,7)<<endl;
    cout<<"Space Optimization Solution "<<s_uniquePaths(3,7)<<endl;
}