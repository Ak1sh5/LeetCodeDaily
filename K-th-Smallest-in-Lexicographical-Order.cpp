class Solution {
private:
    int Helper(long long prefix1, long long prefix2, int n){
        int steps;
        while(prefix1<=n){
            steps+= min((long)(n+1),(long)(prefix2))-prefix1;
            prefix1*=10;
            prefix2*=10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
             int steps= Helper(curr,curr+1,n);

             if(steps<=k){
                k-=steps;
                curr++;
             }
             else{
                curr*=10;
                k--;
             }
        }
        return curr;
    }
};