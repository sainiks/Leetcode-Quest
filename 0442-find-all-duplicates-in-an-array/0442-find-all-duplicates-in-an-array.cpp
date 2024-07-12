class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0; i<nums.size();i++){
            int x=nums[i];
            if(x>4*n){
                x-=4*n;
            }else if(x>2*n){
                x-=2*n;
            }
            x--;
            nums[x]+=2*n;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>4*n){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};