#include <bits/stdc++.h>
using namespace std;

int f(int i,int last,vector<vector<int>> &nums,vector<vector<int>> &dp){
    if(i>=nums.size()) return 0;
    int maxi=INT_MIN;
    if(dp[i][last]!=-1) return dp[i][last];
    for(int k=0;k<=2;k++){
        if(k!=last){
            int take=f(i+1,k,nums,dp)+nums[i][k];
            maxi=max(maxi,take);
        }
    }
    return dp[i][last]=maxi;

}
int ninja(vector<vector<int>> &nums){
    vector<vector<int>> dp(nums.size(),vector<int>(4,-1));
    
    return f(0,3,nums,dp);
}

int t_ninja(vector<vector<int>> &nums){
    vector<vector<int>> dp(nums.size()+1,vector<int>(3));
    for(int i=0;i<3;i++){
        dp[nums.size()][i]=0;
    }
    for(int i=nums.size()-1;i>0;i--){
        for(int j=0;j<3;j++){
            int maxi=INT_MIN;
            for(int k=0;k<=2;k++){
                if(k!=j){
                    int take=dp[i+1][k]+nums[i][k];
                    maxi=max(maxi,take);
                }
            }
            dp[i][j]=maxi;
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        ans=max(ans,dp[1][i]+nums[0][i]);
    }
    return ans;
}
int s_ninja(vector<vector<int>> &nums){
    vector <int> next(3,0);
    
    for(int i=nums.size()-1;i>0;i--){
        vector <int> curr(3);
        for(int j=0;j<3;j++){
            int maxi=INT_MIN;
            for(int k=0;k<=2;k++){
                if(k!=j){
                    int take=next[k]+nums[i][k];
                    maxi=max(maxi,take);
                }
            }
            curr[j]=maxi;
        }
        next=curr;
    }
    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        ans=max(ans,next[i]+nums[0][i]);
    }
    return ans;
}

int s2_ninja(vector<vector<int>> &nums){
    int a=0;
    int b=0;
    int c=0;

    for(int i=nums.size()-1;i>=0;i--){
        int na=max(b+nums[i][1],c+nums[i][2]);
        int nb=max(a+nums[i][0],c+nums[i][2]);
        int nc=max(b+nums[i][1],a+nums[i][0]);

        a=na;
        b=nb;
        c=nc;
    }
    return max({a,b,c});
}
int main(){
    vector<vector<int>> nums={{10,40,70},{20,50,80},{30,60,90}};
    cout<<"Recursive solution "<<ninja(nums)<<endl;

    cout<<"Tabulation solution "<<t_ninja(nums)<<endl;

    cout<<"Space Optimization solution "<<s_ninja(nums)<<endl;

    cout<<"Space Optimization solution2 "<<s2_ninja(nums)<<endl;
}