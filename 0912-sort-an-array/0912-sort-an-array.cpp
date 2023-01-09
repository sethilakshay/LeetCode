class Solution {
public:
    // Merge Sort
    void merge(vector<int>& nums, int l, int mid, int r){
        int ptr1 = l, ptr2 = mid+1, ptr = 0;
        vector<int> temp(r-l +1);
        
        while(ptr1 <= mid && ptr2 <= r){
            if(nums[ptr1] < nums[ptr2]){
                temp[ptr++] = nums[ptr1++];
            }
            else{
                temp[ptr++] = nums[ptr2++];
            }
        }
        
        while(ptr1 <= mid){
            temp[ptr++] = nums[ptr1++];
        }
        
        while(ptr2 <= r){
            temp[ptr++] = nums[ptr2++];
        }
        
        for(int i=0; i<temp.size(); i++){
            nums[l++] = temp[i];
        }
        return;
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        if(l>=r){
            return;
        }
        //Divide the Array
        int mid = l + (r-l)/2;
    
        mergeSort(nums, l, mid);    //Sort the 1st Half
        mergeSort(nums, mid+1, r);  //Sort the 2nd Half
        
        merge(nums, l, mid, r);     //Merge the two halves
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};