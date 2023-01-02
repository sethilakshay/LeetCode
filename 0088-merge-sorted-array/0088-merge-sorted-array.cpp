class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = nums1.size();
        
        while(m-1 >= 0 && n-1 >= 0){
            
            if(nums1[m-1] >= nums2[n-1]){
                nums1[j-1] = nums1[m-1];
                m--;
            }
            else{
                nums1[j-1] = nums2[n-1];
                n--;
            }
            j--;
        }
        
        while(n-1 >= 0){
            nums1[j-1] = nums2[n-1];
            n--;
            j--;
        }
    }
};