class MinStack {
public:
    stack<int>stk;
    stack<int>minstk;
    MinStack(){} 
    void push(int val){
        if(stk.size()==0){
            stk.push(val);
            minstk.push(val);
        }
        else{
            stk.push(val);
            if(minstk.top()>=val){
                minstk.push(val);
            }
        }
    } 
    void pop(){
            if(stk.top()==minstk.top()){
                minstk.pop();
            }
            stk.pop();
    }
    int top(){
        return stk.top();
    }
    int getMin(){
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */