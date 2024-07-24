class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>graph[n+1];
        for(auto e:times){
            int u=e[0],v=e[1],w=e[2];
            graph[u].push_back({v,w});
        }
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int >>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first,i=pq.top().second;
            pq.pop();
            if(dis[i]<d){
                continue;
            }
            for(auto [j,w]:graph[i]){        // here we are doing destuctursize
                if(dis[j]>dis[i]+w){
                    dis[j]=dis[i]+w;
                    pq.push({dis[j],j});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }
        if(ans==1e9)return -1;
            return ans;
    }
};