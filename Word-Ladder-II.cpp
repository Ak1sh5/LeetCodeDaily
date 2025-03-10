class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;

private:
    void dfs(string word,vector<string>&path){
        if(word==b){
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(),path.end());
            return;
        }
         int steps=mpp[word];
         for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                        path.push_back(word);
                        dfs(word,path);
                        path.pop_back();
                    }
                }
                word[i]=original;
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;

        q.push(b);
       
        s.erase(b);
        mpp[b]=1;
        int len=b.length();

        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();

            if(endWord==word) break;

            for(int i=0;i<len;i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(s.find(word)!=s.end()){
                        mpp[word]=steps+1;
                        q.push(word);
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>path;
            path.push_back(endWord);
            dfs(endWord,path);
        } 
        return ans;
    }
};