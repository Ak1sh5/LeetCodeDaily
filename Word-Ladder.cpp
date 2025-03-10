
class Solution{
public:
    int ladderLength(string startWord, string targetWord,
                         vector<string> &wordList) {
        unordered_set<string>s;
        for(auto it:wordList){
            s.insert(it);
        }

        int len=startWord.length();
        queue<pair<string,int>>q;
        q.push({startWord,1});

        while(!q.empty()){
            string node=q.front().first;
            int presntLen=q.front().second;
            if(node==targetWord) return presntLen;
            q.pop();

            for(int i=0;i<len;i++){
                string temp=node;
                for(int j=0;j<26;j++){
                    temp[i]=j+'a';
                    if(s.find(temp)!=s.end()){
                        s.erase(temp);
                        q.push({temp,presntLen+1});
                    }
            }
        }

        }
        return 0;
    }
};