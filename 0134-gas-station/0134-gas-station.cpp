class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int run_gas, i = 0, j, n = gas.size();
        
        while(i<n){
            
            j = i;
            int cnt = n-1, tot_gas = 0;
            
            while(cnt>= 0){
                
                tot_gas += gas[j] - cost[j];
                
                if(tot_gas < 0)
                    break;
                
                j = (j+1)%n;
                cnt--;
            }
            
            if(tot_gas>=0){
                return i;
            }
            
            else if (j<i)
                return -1;
            
            i = j+1;
        }
        return -1;
            
    }
};