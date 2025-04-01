class Solution {
public:
    long long Helper(vector<vector<int>>& questions,int ind,int n,vector<long>&dp){

       if (ind >= n) return 0;
       if(dp[ind]!=-1) return dp[ind];

        long long pick = questions[ind][0] + Helper(questions, ind + questions[ind][1] + 1, n,dp);

        long long notPick=Helper(questions,ind+1,n,dp);
          
        return dp[ind]=max(pick, notPick);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long>dp(n,-1);
        return Helper(questions,0,n,dp);
    }
};