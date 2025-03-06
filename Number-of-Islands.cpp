class Solution{
public:
    void bfs(vector<vector<char>> &grid,int n,int m,vector<vector<int>>&vis,int a,int b ){
        queue<pair<int,int>>q;
        q.push({a,b});
        vis[a][b]=1;
        
        int rowno[]={-1,0,1,0};
        int colno[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int r=0;r<4;r++){
                    int newRow=row+rowno[r];
                    int newCol=col+colno[r];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]=='1' && vis[newRow][newCol]==0){
                        vis[newRow][newCol]=1;
                        q.push({newRow,newCol});
                    }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    bfs(grid,n,m,vis,i,j);
                 }
            }
        }
        return count;
    }
};
