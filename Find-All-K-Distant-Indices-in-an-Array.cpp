class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        vector<int>keys;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==key) keys.push_back(i);
        }
        int m=keys.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(abs(i-keys[j])<=k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};