class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(), i = 0, j = 0;
        int cnt, tot_gas;
        
        while(i<n){
            
            j = i;
            cnt = 0;
            tot_gas = 0;
            
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