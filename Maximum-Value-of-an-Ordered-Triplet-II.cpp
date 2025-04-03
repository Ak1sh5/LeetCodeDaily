class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0,dmax=0,imax=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            res=max(res,dmax*nums[i]);
            dmax=max(dmax,imax-nums[i]);
            imax = max(imax, static_cast<long long>(nums[i]));
        }
        return res;
    }
};