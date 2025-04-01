class Solution {
public:
    int Helper(vector<int>&nums,int ind,int n,vector<int>&dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+Helper(nums,ind+2,n,dp);
        int notPick=Helper(nums,ind+1,n,dp);

        return dp[ind]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,-1);
        return Helper(nums,0,n,dp);
        
    }
};