class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>posmap;
        int begin=0, ans=0;
        for(int i=0; i<s.size();i++){
            if(posmap.find(s[i])!=posmap.end() and posmap[s[i]]>=begin){
                begin=posmap[s[i]]+1;
            }
            posmap[s[i]]=i;
            ans=max(ans,i-begin+1);
        }
        return ans;
    }
};