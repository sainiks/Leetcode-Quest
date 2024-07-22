class Solution {
public:
    bool dfs(int i , int pr,vector<int>&visited,vector<vector<int>>graph){
        if(pr==-1){
            visited[i]=1;
        }else{
            visited[pr]==1 ? visited[i] = 2 : visited[i] = 1;
        }
        bool ans=true;
        for(auto u:graph[i]){
            if(u==pr)continue;
            if(visited[u]==0){
                ans&=dfs(u,i,visited,graph);
            }else if(visited[u]==visited[i]){
                ans&=false;
            }
        }
        return ans ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        bool ans =true;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans&=dfs(i,-1,visited,graph);
            }
        }
        return ans;
    }
};