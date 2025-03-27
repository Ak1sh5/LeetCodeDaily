class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n=nums.size();
        int count=0;
        int element=-1;
        for(int i=0;i<n;i++){
            if(count==0){
                element=nums[i];
                count=1;
            }
            else if(element==nums[i]){
                count++;
            }
            else count--;
        }
        
        count=0;
        int i=0;
        while(i<n){
            if(element==nums[i]) count++;
            if(count>(i+1)/2){
                break;
            }
            i++;
        }
        int j=i+1;
        count=0;
        while(j<n){
            if(element==nums[j])count++;
            j++;
        }
      
        if(count>(j-i-1)/2) return i;
        return -1;
    }
};