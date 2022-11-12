class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int it = nums1.size()-1;
        m = m-1, n = n-1;
        
        while(m>=0 && n>=0){
            
            if(nums1[m] > nums2[n]){
                nums1[it] = nums1[m];
                m--;
            }
            else{
                nums1[it] = nums2[n];
                n--;
            }
            it--;
        }
        
        while(m>=0){
            nums1[it] = nums1[m];
            m--;
            it--;
        }
        
        while(n>=0){
            nums1[it] = nums2[n];
            n--;
            it--;
        }
    }
};