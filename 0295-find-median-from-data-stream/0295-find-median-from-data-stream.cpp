class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<>> minq;
    
    MedianFinder() {
    }

    void addNum(int num) {
        
        if(maxq.size() == minq.size()){
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
        
        if(maxq.size() == minq.size()){
            return (double) (maxq.top() + minq.top())/2;
        }
        else{
            return (double) maxq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */