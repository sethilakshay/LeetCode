class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        
        int n = packages.size();
        long packages_sum = 0, min_waste = LONG_MAX, mod = 1e9+7;
        
        sort(packages.begin(), packages.end());
        int max_req = packages[n-1];
    
        for(auto pk: packages)
            packages_sum += pk;
        
        for(int i=0; i<boxes.size(); i++){
            
            sort(boxes[i].begin(), boxes[i].end());
            if(boxes[i][boxes[i].size()-1] < max_req)
                continue;
            
            long box_waste = 0, lo = 0, prev_lo = 0;
            for(int j=0; j<boxes[i].size(); j++){

                if(boxes[i][j] < packages[lo])
                    continue;
                
                long hi = n-1, mid;
                while(lo<hi){
                    mid = lo + (hi-lo+1)/2;
                    if(packages[mid] <= boxes[i][j])
                        lo = mid;
                    else
                        hi = mid-1;
                }
                
                box_waste += ((lo-prev_lo+1)*boxes[i][j]);
                prev_lo = lo+1;
                
                if(lo == n-1)
                    continue;
            }
            min_waste = min(min_waste, box_waste);
        }
        
        return min_waste == LONG_MAX ? -1 : (min_waste-packages_sum)%mod;
    }
};