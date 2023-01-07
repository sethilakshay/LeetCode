class Solution {
public:
    // Using Floyd's algorithim
    // TC: O(n)
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;
        
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if(fast == slow){
                break;
            }
        }
        
        int slow2 = 0;
        
        while (true){
            slow = nums[slow];
            slow2 = nums[slow2];
            
            if(slow == slow2){
                break;
            }
        }
        return slow;
    }
};