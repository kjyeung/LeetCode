class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
        int ret = 0;
        if(q2.empty()){
            ret = q1.back();
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }else{
            ret = q2.back();
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            
            ret = q2.front();
            q2.pop();
        }
        return ret;
    }
    
    int top() {
        if(q1.empty()) return q2.back();
        return q1.back();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */