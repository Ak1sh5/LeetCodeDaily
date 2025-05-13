class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long>freq(26,0);
        int modulo=1e9+7;

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for(int i=0;i<t;i++){
            vector<long long>newFreq(26,0);
            for(int j=0;j<25;j++){
                newFreq[j+1]=(freq[j])% modulo;
            }
            newFreq[0]=(freq[25])%modulo;
            newFreq[1]=(newFreq[1]+freq[25])%modulo;
            freq=newFreq;
        }

        long long ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+freq[i])%modulo;
        }
        return (int)ans;
    }
};