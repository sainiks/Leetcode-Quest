class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        int n=stations.size();
        priority_queue<int>acp;
        int nextpump=0;
        int curpos=startFuel;
        int stops=0;
        while(true){
            while(nextpump < n and stations[nextpump][0] <=curpos){
                acp.push(stations[nextpump][1]);
                nextpump++;
            }
            if(curpos>=target)return stops ;
            if(acp.empty())break;
            curpos+=acp.top();
            acp.pop();
            stops++;
        }
        return -1;
    }
};