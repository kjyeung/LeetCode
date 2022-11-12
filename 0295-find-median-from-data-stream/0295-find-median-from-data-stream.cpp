class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size() > big.size()){
            small.push(num);
            big.push(small.top());
            small.pop();
        }else{
            big.push(num);
            small.push(big.top());
            big.pop();
        }
        
    }
    
    double findMedian() {
        if(small.size() > big.size()){
            return small.top();
        }
        if(small.size() < big.size()){
            return big.top();
        }
        return (small.top() + big.top()) / 2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */