class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int count=0;
        int ind1=0,ind2=0;
       
        int i=0;
        while(i<n){
            if(s1[i]!=s2[i]){
              count++;
              if(count>2) return false;
              else if(count==1) ind1=i;
              else ind2=i;
            }
            i++;
        }
        
        return (s1[ind1]==s2[ind2] && s1[ind2]==s2[ind1]);
    }
};