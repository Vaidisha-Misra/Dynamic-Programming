#include <bits/stdc++.h>
using namespace std;

int r_f(int i,int j,int l,int n,int m,vector<vector<int>>& grid){
    if(i==n-1){
        if(j==l) return grid[i][j];
        else return grid[i][j]+grid[i][l];
    }
    int ans=INT_MIN;
    int add;
    if(j==l) add=grid[i][j];
     else add=grid[i][j]+grid[i][l];
    int cols[3]={0,-1,1};
    for(auto it:cols){
        int icol=j+it;
        if(icol<0 || icol>=m) continue;
        for(auto kt:cols){
            int kcol=l+kt;
            if(kcol>=0 && kcol<m){
                int take=r_f(i+1,icol,kcol,n,m,grid)+add;
                ans=max(take,ans);
            }
        }
    }
    return ans;
}
int r_cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    return r_f(0,0,m-1,n,m,grid);
}
int m_f(int i,int j,int l,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(i==n-1){
            if(j==l) return grid[i][j];
            else return grid[i][j]+grid[i][l];
        }
        if(dp[i][j][l]!=-1) return dp[i][j][l];
        int ans=INT_MIN;
        int add;
        if(j==l) add=grid[i][j];
        else add=grid[i][j]+grid[i][l];
        int cols[3]={0,-1,1};
        for(auto it:cols){
            int icol=j+it;
            if(icol<0 || icol>=m) continue;
            for(auto kt:cols){
                int kcol=l+kt;
                if(kcol>=0 && kcol<m){
                    int take=m_f(i+1,icol,kcol,n,m,grid,dp)+add;
                    ans=max(take,ans);
                }
            }
        }
        return dp[i][j][l]=ans;
    }
    int m_cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return m_f(0,0,m-1,n,m,grid,dp);
    }
    int t_cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int l=0;l<m;l++){
                    if(i==n-1){
                        if(j==l) dp[i][j][l]=grid[i][j];
                        else dp[i][j][l]=grid[i][j]+grid[i][l];
                    }
                    else{
                    int ans=INT_MIN;
                    int add;
                    if(j==l) add=grid[i][j];
                    else add=grid[i][j]+grid[i][l];
                    int cols[3]={0,-1,1};
                    for(auto it:cols){
                        int icol=j+it;
                        if(icol<0 || icol>=m) continue;
                        for(auto kt:cols){
                            int kcol=l+kt;
                            if(kcol>=0 && kcol<m){
                                int take=dp[i+1][icol][kcol]+add;
                                ans=max(take,ans);
                            }
                        }
                    }
                    dp[i][j][l]=ans;
                    }
                }
            }
        }
        return dp[0][0][m-1];
    }
int s_cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(m));
        vector<vector<int>> curr(m,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int l=0;l<m;l++){
                    if(i==n-1){
                        if(j==l) dp[j][l]=grid[i][j];
                        else dp[j][l]=grid[i][j]+grid[i][l];
                    }
                    else{
                    int ans=INT_MIN;
                    int add;
                    if(j==l) add=grid[i][j];
                    else add=grid[i][j]+grid[i][l];
                    int cols[3]={0,-1,1};
                    for(auto it:cols){
                        int icol=j+it;
                        if(icol<0 || icol>=m) continue;
                        for(auto kt:cols){
                            int kcol=l+kt;
                            if(kcol>=0 && kcol<m){
                                int take=dp[icol][kcol]+add;
                                ans=max(take,ans);
                            }
                        }
                    }
                    curr[j][l]=ans;
                    }
                }
            }
            if(i!=n-1) dp=curr;
        }
        return dp[0][m-1];
    }
int main(){
    vector<vector<int>> grid={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout<<"Recursive Solution "<<r_cherryPickup(grid)<<endl;
    cout<<"Memoization Solution "<<m_cherryPickup(grid)<<endl;
    cout<<"Tabulation Solution "<<t_cherryPickup(grid)<<endl;
    cout<<"Space Optimization Solution "<<s_cherryPickup(grid)<<endl;
}