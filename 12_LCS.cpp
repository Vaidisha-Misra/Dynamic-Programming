#include <bits/stdc++.h>
using namespace std;
int f(int i,int j,string &a,string &b,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]=1+f(i-1,j-1,a,b,dp);
    return dp[i][j]=max(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp));
}
int lcs(string &a,string &b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(a.size()-1,b.size()-1,a,b,dp);
}

// performing shift of indexes

int a_f(int i,int j,string &a,string &b,vector<vector<int>> &dp){
    if(i==0 || j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i-1]==b[j-1]) return 1+a_f(i-1,j-1,a,b,dp);
    return dp[i][j]=max(a_f(i-1,j,a,b,dp),a_f(i,j-1,a,b,dp));
}
int a_lcs(string &a,string &b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return a_f(a.size(),b.size(),a,b,dp);
}

int t_lcs(string &a,string &b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// Printing LCS
void p_lcs(string &a,string &b){
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int len=dp[n][m];
    string ans="";
    for(int i=0;i<len;i++) ans+="$";

    int index=len-1;
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans[index]=a[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    cout<<ans;
}

int s_lcs(string &a,string &b){
    int n=a.size();
    int m=b.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[m];
}
int main(){
    string a="ced";
    string b="acd";
    cout<<lcs(a,b)<<endl;
    cout<<a_lcs(a,b)<<endl;
    cout<<t_lcs(a,b)<<endl;
    cout<<s_lcs(a,b)<<endl;
    p_lcs(a,b);
    cout<<endl;
}