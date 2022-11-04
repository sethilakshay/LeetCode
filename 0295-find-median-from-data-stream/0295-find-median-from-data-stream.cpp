class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    bool isEven = true;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        if(isEven){
            minq.push(num);
            maxq.push(minq.top());
            minq.pop();
            isEven = false; 
        }
        
        else{
            maxq.push(num);
            minq.push(maxq.top());
            maxq.pop();
            isEven = true;
        }
        
    }
    
    double findMedian() {
        if(isEven){
            return (double) (minq.top() + maxq.top())/2;
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