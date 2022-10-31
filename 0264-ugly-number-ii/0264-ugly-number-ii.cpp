class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<long, vector<long>, greater<long>> min_heap;
        
        min_heap.push(1);
        int cnt = 1;
        
        while(cnt < n){
            
            long top = min_heap.top();
            min_heap.pop();
            
            if(top %5 == 0){
                min_heap.push(top*5);
            }
            
            else if(top %3 == 0){
                min_heap.push(top*3);
                min_heap.push(top*5);
            }
            
            else{
                min_heap.push(top*2);
                min_heap.push(top*3);
                min_heap.push(top*5);
            }
            cnt++;
        }
        
        return min_heap.top();
    }
};