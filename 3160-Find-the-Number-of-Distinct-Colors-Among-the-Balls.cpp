class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>result;
        unordered_map<int,int>colorCount; //color , count
        unordered_map<int,int>ballColor; //ball ,color

        int n=queries.size();

        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];

            if(ballColor.find(ball)!=ballColor.end()){
                int prevColor=ballColor[ball];
                colorCount[prevColor]--;
                if(colorCount[prevColor]==0) colorCount.erase(prevColor);
            }
            
            ballColor[ball]=color;
            colorCount[color]++;
            result.push_back(colorCount.size());
        }
        return result;
    }
};