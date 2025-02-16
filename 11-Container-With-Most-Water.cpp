class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxi=INT_MIN;
        while(left<right){
            int presentArea=(right-left)*min(height[left],height[right]);
            maxi=max(maxi,presentArea);
            if(height[left]<=height[right])left++;
            else right--;
        }
        return maxi;
    }
};