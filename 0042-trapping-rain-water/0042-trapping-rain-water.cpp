class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
            vector<int>prefixMax(n),suffixMax(n);
            for(int i=0; i<n;i++){
                if(i==0){
                    prefixMax[i]=height[i];
                }else{
                    prefixMax[i]=max(prefixMax[i-1],height[i]);
                }
            }
            for(int i=n-1; i>=0;i--){
                if(i==n-1){
                    suffixMax[i]=height[i];
                }else{
                    suffixMax[i]=max(suffixMax[i+1],height[i]);
                }
           }
        int ans=0;
        for(int i=0; i<n; i++){
            int minheight=min(prefixMax[i],suffixMax[i]);
            int netarea=minheight-height[i];
            ans+=netarea;
        }
        return ans;    
    }
};