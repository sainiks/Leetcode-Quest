class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        for(auto i:asteroids){
            if(v.empty()){
                v.push_back(i);
            }else{
                if(i>0){
                    v.push_back(i);
                }else{
                    bool flag=false;
                    while(v.size()>0 and v.back()<=abs(i) and v.back()>0){
                        int last=v.back();
                        v.pop_back();
                        if(last==abs(i)){
                            flag=true;
                            break;
                        }
                    }
                    if((v.size()==0 or (v.size()>0 and v.back()<0)) and flag==false){
                    v.push_back(i);
                    }
                }
            }
        }
        return v;
    }
};