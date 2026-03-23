#include <bits/stdc++.h> 
using namespace std;

int r_f(int n,vector<int> &heights,int k){
    if(n==0) return 0;
    int cost=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n>=i){ 
            int Step=r_f(n-i,heights,k)+abs(heights[n]-heights[n-i]);
            cost=min(cost,Step);
        }
    }
    return cost;
    
}
int m_f(int n,vector<int> &heights,int k,vector <int> &dp){
     int cost=INT_MAX;
     if(dp[n]!=-1) return dp[n];
     for(int i=1;i<=k;i++){
        if(n>=i){ 
            int Step=r_f(n-i,heights,k)+abs(heights[n]-heights[n-i]);
            cost=min(cost,Step);
        }
    }
    return dp[n]=cost;
}

int t_f(int n,vector<int> &heights,int k){
    vector <int> dp2(n+1);
    dp2[0]=0;
    for(int j=1;j<=n;j++){
         int cost=INT_MAX;
        for(int i=1;i<=k;i++){
            if(j>=i){ 
                int Step=dp2[j-i]+abs(heights[j]-heights[j-i]);
                cost=min(cost,Step);
            }
        }
        dp2[j]=cost;
    }
    return dp2[n];
}
int main(){
    vector <int> heights={15, 4, 1, 14, 15};
    int k=3;
    cout<<r_f(4,heights,k)<<endl;
    int n=5;
    vector <int> dp(n,-1);
    dp[0]=0;

    cout<<m_f(4,heights,k,dp)<<endl;

    cout<<"Tabulation solution "<<t_f(4,heights,k)<<endl;


}