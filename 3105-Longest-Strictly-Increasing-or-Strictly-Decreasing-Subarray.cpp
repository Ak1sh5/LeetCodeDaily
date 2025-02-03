class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing=1,decreasing=1;
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            nums[i]<nums[i+1]?increasing++:increasing=1;

            nums[i]>nums[i+1]?decreasing++:decreasing=1;
    
            ans=max(ans,max(increasing,decreasing));
        }
        return ans;
    }
};