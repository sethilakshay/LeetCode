class Solution {
public:
    int partition(vector<int>& nums, int l, int r, int pivot){
        int leftPtr = l-1;
        int rightPtr = r;
        
        while(true){
            while(nums[++leftPtr] < pivot){
            }
            
            while(rightPtr > leftPtr && nums[--rightPtr] > pivot){
            }
            
            if(leftPtr >= rightPtr){
                break;
            }
            else{
                swap(nums[leftPtr], nums[rightPtr]);
            }
        }
        swap(nums[leftPtr], nums[r]);
        return leftPtr;
    }
    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        
        int mid = l+(r-l)/2;
        int pivot = nums[mid];
        swap(nums[r], nums[mid]);
        int partitionIdx = partition(nums, l, r, pivot);
        
        quickSort(nums, l, partitionIdx-1);
        quickSort(nums, partitionIdx+1, r);
    }
    void sortColors(vector<int>& nums) {
        //2-Pointer approach
        //lo -> 0;
        //mid -> 1;
        //hi -> 2;
        // int lo = 0, mid = 0, hi = nums.size()-1;
        // while(mid <= hi){
        //     if(nums[mid] == 0){
        //         swap(nums[lo], nums[mid]);
        //         lo++;
        //         mid++;
        //     }
        //     else if(nums[mid] == 1){
        //         mid++;
        //     }
        //     else{
        //         swap(nums[hi], nums[mid]);
        //         hi--;
        //     }
        // }
        
        // QuickSort Based Approach
        quickSort(nums, 0, nums.size()-1);
    }
};