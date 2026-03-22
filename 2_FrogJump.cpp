/* Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. 
At a time the frog can climb either one or two steps. A height[N] array is also given. 
Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), 
where abs() means the absolute difference. 
We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.. */

#include <bits/stdc++.h> 
using namespace std;

// Recursion
int r_f(int n,vector<int> &heights){
    if(n==0) return 0;
    if(n==1) return abs(heights[n]-heights[n-1]);

    int oneStep=r_f(n-1,heights)+abs(heights[n]-heights[n-1]);
    int twoStep=r_f(n-2,heights)+abs(heights[n]-heights[n-2]);

    return min(oneStep,twoStep);
}
int r_frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return r_f(n-1,heights);
}


// Memoization
int m_f(int n,vector<int> &heights,vector<int> &dp){
    if(dp[n]!=-1) return dp[n];

    int oneStep=m_f(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int twoStep=m_f(n-2,heights,dp)+abs(heights[n]-heights[n-2]);

    return dp[n]=min(oneStep,twoStep);
}
int m_frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector <int> dp(n,-1);
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    return m_f(n-1,heights,dp);
}


// Tabulation
int t_frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n<=1) return 0;
    vector <int> dp(n);
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    
    n=n-1;
    for(int i=2;i<=n;i++){
       int oneStep=dp[i-1]+abs(heights[i]-heights[i-1]);
       int twoStep=dp[i-2]+abs(heights[i]-heights[i-2]);
       dp[i]=min(oneStep,twoStep); 
    }
    return dp[n];
}

// Space optimization
int s_frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n<=1) return 0;
    int prev2=0;
    int prev=abs(heights[1]-heights[0]);
    
    n=n-1;
    for(int i=2;i<=n;i++){
       int oneStep=prev+abs(heights[i]-heights[i-1]);
       int twoStep=prev2+abs(heights[i]-heights[i-2]);
       int curr=min(oneStep,twoStep); 
       prev2=prev;
       prev=curr;
    }
    return prev;
}

int main(){
    vector <int> heights={10,20,30,10};
    cout<<"Recursive solution "<<r_frogJump(4,heights)<<endl;
    cout<<"Memoization solution "<<m_frogJump(4,heights)<<endl;
    cout<<"Tabulation solution "<<t_frogJump(4,heights)<<endl;
    cout<<"Space Optimization solution "<<s_frogJump(4,heights)<<endl;
}