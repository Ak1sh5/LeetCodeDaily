class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans=0;
        sort(courses.begin(),courses.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        }
        );

        priority_queue<int>pq;
        int sum=0;

        for(auto i:courses){
           if(sum+i[0]<=i[1]){
              pq.push(i[0]);
              sum+=i[0];
           }
           else if(!pq.empty() && i[0]<pq.top()){
            sum=sum-pq.top()+i[0];
            pq.pop();
            pq.push(i[0]);
           }
        }
        return pq.size();

    }
};