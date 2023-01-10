class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<long, vector<long>, greater<long>> min_heap;
        min_heap.push(1);
        
        n--;
        
        while(n > 0){
            long num = min_heap.top();
            min_heap.pop();
            
            if(num%5 == 0){
                min_heap.push(num*5);
            }
            else if(num%3 == 0){
                min_heap.push(num*5);
                min_heap.push(num*3);
            }
            else{
                min_heap.push(num*5);
                min_heap.push(num*3);
                min_heap.push(num*2);
            }
            n--;
        }
        return min_heap.top();
    }
};