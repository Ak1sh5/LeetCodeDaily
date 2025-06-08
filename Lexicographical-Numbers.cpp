class Solution {
public:
    void Helper(vector<int>&ans,int n,int curr){
        if(curr>n) return;
        ans.push_back(curr);

        for(int i=0;i<=9;i++){
            int nextNumber=curr*10+i;

            if(nextNumber <=n) Helper(ans,n,nextNumber);
            else break;
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;

        for(int i=1;i<=9;i++){
            Helper(ans,n,i);
        }
        return ans;

    }
};