class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
//         priority_queue<int> maxq;
        
//         for(int num: nums)
//             maxq.push(num);
        
//         while(k-1>0){
//             maxq.pop();
//             k--;
//         }
        
//         return maxq.top();
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(int num: nums){
            
            if(min_heap.size() < k)
                min_heap.push(num);
            
            else{
                if(min_heap.top() < num){
                    min_heap.pop();
                    min_heap.push(num);
                }
                
            }
            
        }
        
        return min_heap.top();
        
    }
};