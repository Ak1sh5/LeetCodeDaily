class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        long long imax=0,dmax=0;

        for(int i=0;i<n;i++){
            // diff*k
            res=max(res,dmax*nums[i]);
            
            //maxdiff
            dmax=max(dmax,imax-nums[i]);
            
            //maxi I
            imax=max(imax,static_cast<long long>(nums[i]));

        }
        return res;
    }
};