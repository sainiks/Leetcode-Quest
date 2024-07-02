class StockSpanner {
public:
    stack<int>stk;
    vector<int>v;
    StockSpanner(){}
    int next(int price) {
    int ans =1;
    if(stk.size()==0){
        stk.push(v.size());
        v.push_back(price);
    }else{
        int i=v.size();
        while(stk.size()>0 and v[stk.top()]<=price){
            stk.pop();
        }
        if(stk.size()>0){
            ans=i-stk.top();
        }
        else{
            ans=i+1;
        }
        stk.push(v.size());
        v.push_back(price);
    }
    return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */