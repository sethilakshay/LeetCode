class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        int i = 0, res = 0;
        while(truckSize > 0 && i<boxTypes.size()){
            
            res = res + min(truckSize, boxTypes[i][0])*boxTypes[i][1];
            truckSize = truckSize - min(truckSize, boxTypes[i][0]); 
            
            i++;
        }
        
        return res;
    }
};