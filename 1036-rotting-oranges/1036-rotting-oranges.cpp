class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>t(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    t[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int mxTime =0;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            mxTime=max(mxTime,t[i][j]);
            if(i-1>=0 and grid[i-1][j]==1){
                t[i-1][j]=t[i][j]+1;
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(i+1<n and grid[i+1][j]==1){
                t[i+1][j]=t[i][j]+1;
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            if(j-1>=0 and grid[i][j-1]==1){
                t[i][j-1]=t[i][j]+1;
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if(j+1<m and grid[i][j+1]==1){
                t[i][j+1]=t[i][j]+1;
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mxTime=-1;
                }
            }
        }
        return mxTime;
    }
};