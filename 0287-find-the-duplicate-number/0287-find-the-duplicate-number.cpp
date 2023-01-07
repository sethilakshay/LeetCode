class Solution {
public:
    // Using Floyd's algorithim
    // TC: O(n)
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;
        
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            // Means fast and slow pointers have intersected
            // The cycle start distance will be same from idx = 0 from curr slow
            if(fast == slow){
                break;
            }
        }
        
        int slow2 = 0;
        
        while (true){
            slow = nums[slow];
            slow2 = nums[slow2];
            // They have met, means that the current position is the start of the cycle
            // This is also the duplicate element
            // Answer can be slow or slow 2 since they are the same
            if(slow == slow2){
                break;
            }
        }
        return slow;
    }
};