class Solution {
private:
   vector<int> parent;
public:
    void initalise(){
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b){
        int ax=find(a);
        int bx=find(b);
        
        if(ax==bx) return;
        
        if(ax<bx){
            parent[bx]=ax;
        }
        else parent[ax]=bx;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        initalise();
        for(int i=0;i<n;i++){
            unite(s1[i]-'a',s2[i]-'a');
        }

        string ans;
        int n1=baseStr.length();

        for(int i=0;i<n1;i++){
            int smallest=find(baseStr[i]-'a');
            ans+='a'+smallest;
        }
        return ans;

    }
};