class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(), tot_gas = 0, i = 0, j = 0, cnt;
        
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
            
            if(tot_gas >= 0){
                return i;
            }
            
            if(j<i)
                return -1;
            
            i = j+1;
        }
        return -1;
    }
};