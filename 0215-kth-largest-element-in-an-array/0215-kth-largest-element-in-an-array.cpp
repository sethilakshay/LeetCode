class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> maxq;
        
        for(int num: nums)
            maxq.push(num);
        
        while(k-1>0){
            maxq.pop();
            k--;
        }
        
        return maxq.top();
    }
};