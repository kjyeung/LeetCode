class MedianFinder {
private:
    priority_queue<int> s1;
    priority_queue<int, vector<int> ,greater<int>> s2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s1.size() >= s2.size()){
            s1.push(num);
            s2.push(s1.top());
            s1.pop();
        }else{
            s2.push(num);
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    double findMedian() {
        if(s1.size() > s2.size()){
            return s1.top();
        }
        if(s2.size() > s1.size()){
            return s2.top();
        }
        return (s1.top() + s2.top() ) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */