class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int i = 0, j, tot_gas = 0, n = gas.size(), cnt;
        
        while(i<n){
            
            j = i;
            cnt = n-1, tot_gas = 0;
            
            while(cnt>=0){
                
                tot_gas += gas[j] - cost[j];
                if(tot_gas<0)
                    break;
                
                j = (j+1)%n;
                cnt--;
            }
            
            if(tot_gas >= 0)
                return i;
            
            if(j<i)
                return -1;
            
            i = j+1;
        }
        return -1;
    }
};