class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>graph[numCourses];
        for(auto v:prerequisites){
            int a=v[0],b=v[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
            q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto u:graph[f]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
            ans.push_back(f);
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};