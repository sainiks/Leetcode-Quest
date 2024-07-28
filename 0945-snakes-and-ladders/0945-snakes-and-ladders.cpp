class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int sq=1;
        unordered_map<int,pair<int,int>>addmp;
        int n=board.size();
        vector<int>path(n*n+1,-1);
        path[1]=0;
        for(int i=n-1;i>=0;i--){
            int x=n-1-i;
            if(x%2==0){
                for(int j=0;j<=n-1;j++){
                    addmp[sq]={i,j};
                    sq++;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    addmp[sq]={i,j};
                    sq++;
                }
            }
        }
        queue<int>q;
            q.push(1);
            while(!q.empty()){
                int f=q.front();
                q.pop();
                for(int i=1;i<=6;i++){
                    int d=min(n*n,f+i);
                    int a=addmp[d].first,b=addmp[d].second;
                    if(board[a][b]!=-1)d=board[a][b];
                    if(path[d]==-1 or path[d]>path[f]+1) {
                        path[d]=path[f]+1;
                        q.push(d);
                    }
                }
            }
        return path[n*n];
    }
};
