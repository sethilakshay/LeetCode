class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int> max_heap;
        
        for(int n: nums){
            max_heap.push(n);
        }
        
        long long res = 0;
        int curr = 0;
        
        while(k > 0){
            
            curr = max_heap.top();
            max_heap.pop();
            
            res += curr;
            curr = ceil((double)curr/3);
            
            max_heap.push(curr);
            k--;
        }
        return res;
    }
};