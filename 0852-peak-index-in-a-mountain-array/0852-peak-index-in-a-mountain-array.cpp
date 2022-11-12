class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int lo = 0, hi = arr.size()-1, mid;
        
        while(lo<hi){
            
            mid = lo + (hi-lo+1)/2;
            if(arr[mid-1] < arr[mid])
                lo = mid;
    
            else
                hi = mid-1;
        }
        
        if(arr[lo-1] < arr[lo])
            return lo;
        
        return -1;
    }
};