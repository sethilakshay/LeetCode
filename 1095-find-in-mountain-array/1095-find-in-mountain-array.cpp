/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int lo = 0, hi = mountainArr.length()-1, mid;
        
        while(lo < hi){
            mid = lo + (hi - lo + 1)/2;
            
            if(mountainArr.get(mid) > mountainArr.get(mid-1)){
                lo = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        
        int mount_Idx = lo;
        lo = 0, hi = mount_Idx;
        
        // Searching the lower half from 0 idx to mountain number idx.
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        
        lo = mount_Idx+1, hi = mountainArr.length()-1;
        
        // Searching the upper half from mountain number idx + 1 to end.
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return -1;
    }
};