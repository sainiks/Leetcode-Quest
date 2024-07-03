class Solution {
    void placequeen(int i, int n,vector<int>&r,vector<int>&c,vector<int>&d1,vector<int>&d2,vector<int>&pos,vector<vector<string>>&ans){
        if(i==n){
            vector<string>s;
            for(int i=0;i<n;i++){
                string str="";
                for(int j=0;j<n;j++){
                    if(pos[i]!=j){
                    str+='.';
                    }else{
                        str+='Q';
                    }
                }
                s.push_back(str);
            }
            ans.push_back(s);
            return;
        }
        for(int j=0;j<n;j++){
            if(c[j]==0 && d1[i-j+n-1]==0 && d2[i+j]==0){
                c[j]=1;
                d1[i-j+n-1]=1;
                d2[i+j]=1;
                pos[i]=j;
                placequeen(i+1,n,r,c,d1,d2,pos,ans);
                c[j]=d1[i-j+n-1]=d2[i+j]=pos[i]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int>r(n,0);
        vector<int>c(n,0);
        vector<int>d1(2*n-1,0);
        vector<int>d2(2*n-1,0);
        vector<int>pos(n,0);
        vector<vector<string>>ans;
        placequeen(0,n,r,c,d1,d2,pos,ans);
        return ans;
    }
};