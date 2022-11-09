class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        
        int res = 0;
        
        for(int i=0; i<boxTypes.size(); i++){
            
            if(truckSize - (boxTypes[i][0]) >= 0){
                res += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            
            else{
                int lo = 0, hi = boxTypes[i][0], mid;
            
                while(lo<hi){
                    mid = lo+(hi-lo+1)/2;
                    
                    if(truckSize - mid >= 0){
                        lo = mid;
                    }
                    
                    else{
                        hi = mid-1;
                    }
                }
                
                //Sanity check
                if(truckSize - lo >= 0){
                    res += lo*boxTypes[i][1];
                }
                
                truckSize -= lo;
            }
            
            if(truckSize == 0)
                break;   
        }
        return res;
    }
};