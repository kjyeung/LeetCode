class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size() > large.size()){
            small.push(num);
            large.push(small.top());
            small.pop();
        }else{
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        if(large.size() > small.size()) return large.top();
        return (small.top() + large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */