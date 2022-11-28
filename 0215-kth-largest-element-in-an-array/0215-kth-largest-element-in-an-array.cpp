class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minq;
        
        for(int i=0; i<nums.size(); i++){
            
            if(minq.size() < k){
                minq.push(nums[i]);
            }
            else if(minq.top() < nums[i]){
                minq.pop();
                minq.push(nums[i]);
            }
        }
        return minq.top();
    }
};