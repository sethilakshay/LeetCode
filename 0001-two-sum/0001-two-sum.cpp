class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //Making a vector of pairs to store number and their index
        vector<pair<int, int>> sort_nums;
        
        for(int i=0; i<nums.size(); i++){
            sort_nums.push_back(make_pair(i, nums[i]));
        }
        
        sort(sort_nums.begin(), sort_nums.end(), [](pair <int, int>& a, pair <int, int>& b){
            return a.second < b.second;
        });
        
        //2 pointers
        int l = 0, r = nums.size()-1;
        
        while(l<r){
            
            if(sort_nums[l].second + sort_nums[r].second == target)
                return {sort_nums[l].first, sort_nums[r].first};
            
            else if (sort_nums[l].second + sort_nums[r].second < target)
                l++;
            
            else
                r--;
        }
        return {-1, -1};
        
    }
};