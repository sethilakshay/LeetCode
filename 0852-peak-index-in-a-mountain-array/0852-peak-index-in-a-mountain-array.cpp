class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0, hi=arr.size()-1, mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(arr[mid]>arr[mid+1]){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        if (!(arr[hi]>arr[hi+1])) return -1;
        else return hi;
    }
};