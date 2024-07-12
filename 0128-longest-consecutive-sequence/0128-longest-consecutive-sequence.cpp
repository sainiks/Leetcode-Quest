class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int ans=0;
        for(int i=0; i<nums.size();i++){
            int cnt =0,j=nums[i];
            while(mp[j]!=0){
                cnt+=mp[j];
                int d= mp[j];
                mp[j]=0;
                j-=d;
            }
            mp[nums[i]]=cnt;
            ans =max(ans,cnt);
        }
        return ans;
    }
};