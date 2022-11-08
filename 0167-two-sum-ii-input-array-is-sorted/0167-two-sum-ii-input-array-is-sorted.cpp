class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int ptr1 = 0, ptr2 = numbers.size()-1;
        
        while(ptr1<ptr2){
            int s = numbers[ptr1] + numbers[ptr2];
            if(s == target){
                return {ptr1+1, ptr2+1};
            }
            else if(s > target){
                ptr2--;
            }
            else{
                ptr1++;
            }
        }
        return {};
    }
};