#include <bits/stdc++.h> 
using namespace std;
bool f(int i,int sum,int n,int k,vector<int> &arr){
    if(i==n){
        if(sum==k) return true;
        else return false;
    }
    if(f(i+1,sum+arr[i],n,k,arr)) return true;
    else return f(i+1,sum,n,k,arr);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(0,0,n,k,arr);
}
/* This code will result in values of sum which are very greater than target 
    and also unpredictable as they depend on the elements of the array.
    So when we apply 2D DP (dp[i][sum]), the number of columns will be equal to the sum of all elements of the array.
    which can be very high.
*/
// Therefore, we start from target and go back till 0.


bool a_f(int i,int sum,vector<int> &arr){
    if(sum==0) return true;
    if(i==0) return arr[i]==sum;
    
    bool take=a_f(i-1,sum-arr[i],arr);
    bool not_take=a_f(i-1,sum,arr);
    return take || not_take;
}
bool a_subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return a_f(n-1,k,arr);
}
/* Here value of sum can go upto negative. while applying DP we can not have negative index in a matrix.*/

bool m_f(int i,int sum,vector<int> &arr,vector<vector<int>> &dp){
    if(sum==0) return true;
    if(i==0) return arr[i]==sum;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool take=false;
    if(arr[i]<=sum) take=m_f(i-1,sum-arr[i],arr,dp);
    bool not_take=m_f(i-1,sum,arr,dp);
    return dp[i][sum]=(take || not_take);
}
bool m_subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return m_f(n-1,k,arr,dp);
}
bool t_subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;

    for(int i=1;i<n;i++){
        for(int sum=1;sum<=k;sum++){
            bool take=false;
            if(arr[i]<=sum) take=dp[i-1][sum-arr[i]];
            bool not_take=dp[i-1][sum];
            dp[i][sum]=(take || not_take);
        }
    }
    return dp[n-1][k];
}
bool s_subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    vector<bool> prev(k+1,0),curr(k+1,0);

    prev[0]=curr[0]=true;
    prev[arr[0]]=true;

    for(int i=1;i<n;i++){
        for(int sum=1;sum<=k;sum++){
            bool take=false;
            if(arr[i]<=sum) take=prev[sum-arr[i]];
            bool not_take=prev[sum];
            curr[sum]=(take || not_take);
        }
        prev=curr;
    }
    return prev[k];
}
int main(){
    vector<int> v={2,3,1,1};
    cout<<subsetSumToK(4,4,v)<<endl;
    cout<<a_subsetSumToK(4,4,v)<<endl;
    cout<<m_subsetSumToK(4,4,v)<<endl;
    cout<<t_subsetSumToK(4,4,v)<<endl;
    cout<<s_subsetSumToK(4,4,v)<<endl;
}