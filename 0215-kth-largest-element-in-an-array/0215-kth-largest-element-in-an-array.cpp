class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxq;
        
        
        for(int i=0; i<nums.size(); i++){
            maxq.push(nums[i]);
        }
        
        while(k > 1){
            maxq.pop();
            k--;
        }
        
        return maxq.top();
    }
};