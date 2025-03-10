class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjRev(numCourses);
        vector<int>indegree(numCourses,0);

        
        for(auto it:prerequisites){
            int a=it[0];
            int b=it[1];
            adjRev[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        int counter=0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            counter++;
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(counter==numCourses) return true;
        return false;
    }
};