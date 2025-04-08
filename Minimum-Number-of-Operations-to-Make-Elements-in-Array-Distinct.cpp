class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int countDuplicates=0;
        unordered_map<int,int>mpp;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                countDuplicates=max(countDuplicates, mpp[nums[i]]+1);
            }
            mpp[nums[i]]=i;
        }
       ans=ceil((double)countDuplicates/(double)3);
       return ans;
        
    }
};