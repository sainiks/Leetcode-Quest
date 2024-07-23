class Solution {
public:
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int i ,int j){
        vis[i][j]=1;
        int cnt=1;
        if(i+1<grid.size() and vis[i+1][j]==0 and grid[i+1][j]!=0){
            cnt+=dfs(grid,vis,i+1,j);
        }
        if(j+1<grid[0].size() and vis[i][j+1]==0 and grid[i][j+1]!=0){
            cnt+=dfs(grid,vis,i,j+1);
        }
        if(i-1>=0 and vis[i-1][j]==0 and grid[i-1][j]!=0){
            cnt+=dfs(grid,vis,i-1,j);
        }
        if(j-1>=0 and vis[i][j-1]==0 and grid[i][j-1]!=0){
            cnt+=dfs(grid,vis,i,j-1);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]!=0){
                    int x=dfs(grid,vis,i,j);
                    mx=max(mx,x);
                }
            }
        }
        return mx;
    }
};