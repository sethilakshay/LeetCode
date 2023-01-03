class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int i=0, j = 0, n = gas.size(), tot_gas = 0;
        
        while(i<n){
            j = i;
            tot_gas = 0;
            int cnt = 0;
            
            while(cnt < n){
                tot_gas += gas[j] - cost[j];
                if(tot_gas < 0){
                    break;
                }
                
                j = (j+1)%n;
                cnt++;
            }
            
            if(tot_gas >= 0){
                return i;
            }
            if(j < i){
                return -1;
            }
            
            i = j+1;
        }
        return -1;
    }
};