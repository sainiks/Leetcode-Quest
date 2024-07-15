class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>tmap,smap;
        for(auto c:t){
            tmap[c]++;
        }
        int l=0, r=-1,ans=1e9 ,l1=-1,r1=-1;
        while(l<(int)s.size() and r<(int)s.size()){
            bool check=true;
            for(auto u:tmap){
                char c=u.first;
                char f=u.second;
                if(smap[c]<tmap[c]){
                    check=false;
                }
            }
            if(check==false){
                r++;
                smap[s[r]]++;
            }else{
                if(ans>r-l+1){
                    ans=r-l+1;
                    l1=l;
                    r1=r;
                }
                smap[s[l]]--;
                l++;
            }  
        }
        string g="";
        if(l1!=-1 and r1!=-1){
            for(int i=l1;i<=r1;i++){
                g+=s[i];
            }
        }
        return g;
    }
};