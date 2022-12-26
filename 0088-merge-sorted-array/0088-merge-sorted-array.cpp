class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr1 = nums1.size()-1;
        
        while(m-1 >= 0 && n-1 >= 0){
            
            if(nums1[m-1] < nums2[n-1]){
                nums1[ptr1] = nums2[n-1];
                n--;
            }
            else{
                nums1[ptr1] = nums1[m-1];
                m--;
            }
            ptr1--;
        }
        
        while(n-1 >= 0){
            nums1[ptr1] = nums2[n-1];
            n--;
            ptr1--;
        }
    }
};