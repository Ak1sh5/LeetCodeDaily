// a -> 26, ab
// b -> 26, bc
// ...
// y -> 26, yz

// z -> 1, ab
// ab -> 24, yz
// yz -> 1, zab
// z -> 26, zab

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long freq[26]={};
        int modulo = 1e9 + 7;

        for (char ch : s) {
            freq[ch - 'a']++;
        }

       while(t>=26) {
            long temp[26]={};

            for (int i = 0; i < 25; ++i) temp[i + 1] += freq[i];

            temp[0]+=freq[25];
            temp[1]+=freq[25];
            
            for(int i=0;i<=25;i++){
                freq[i]+=temp[i];
                freq[i]%=modulo;
            }
            t-=26;
        }

        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans +=freq[i];
            if(i+t>=26) ans+=freq[i];
            ans%=modulo;
        }
        return ans%modulo;
    }
};