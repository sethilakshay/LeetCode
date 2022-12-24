class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hashSet;
        
        for(int num: nums){
            hashSet.insert(num);
        }
        
        int res = 0, currCnt = 0;
        
        for(int i = 0; i<nums.size(); i++){
            currCnt = 1;
            
            if(hashSet.find(nums[i] - 1) == hashSet.end()){
                while(hashSet.find(nums[i]+currCnt) != hashSet.end()){
                    currCnt++;
                }
            }
            
            res = max(res, currCnt);
        }
        
        return res;
    }
};