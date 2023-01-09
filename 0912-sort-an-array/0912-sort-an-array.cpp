class Solution {
public:
    int sortFunc(vector<int>& nums, int l, int r, int pivot){
        
        int left = l-1;
        int right = r;
        
        while(true){
            while(nums[++left] < pivot);
            while(right > left && nums[--right] > pivot);
            
            if(left >= right) break;
            else swap(nums[left], nums[right]);
        }
        
        swap(nums[left], nums[r]);
        return left;
    }
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        
        int mid = l + (r-l)/2;
        swap(nums[mid], nums[r]);
        int pivot = nums[r];
        
        int pivot_idx = sortFunc(nums, l, r, pivot);
        quickSort(nums, l, pivot_idx-1);
        quickSort(nums, pivot_idx+1, r);        
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};