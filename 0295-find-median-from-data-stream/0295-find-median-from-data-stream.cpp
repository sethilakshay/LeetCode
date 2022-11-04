class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        if((minq.size() + maxq.size()) %2 == 0){
            minq.push(num);
            maxq.push(minq.top());
            minq.pop();
        }
        
        else{
            maxq.push(num);
            minq.push(maxq.top());
            maxq.pop();
        }
        
    }
    
    double findMedian() {
        if((minq.size() + maxq.size()) %2 == 0){
            return (double) (minq.top() + maxq.top())/2; 
        }
        else{
            return (double) maxq.top(); 
        }
        
        return {};
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */