struct Node{
    int val, min;
    Node(int _v,int _min){
        val = _v;
        min = _min;
        next = nullptr;
    }
    Node* next;
};
class MinStack {
public:
    Node* head = nullptr;
    MinStack() {
        
    }
    
    void push(int val) {
        if(head == nullptr) head = new Node(val, val);
        else{
            Node* cur = new Node(val, min(head->min,val));
            cur->next = head;
            head = cur;
        }
        return;
    }
    
    void pop() {
        head = head->next;
        return;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
        
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