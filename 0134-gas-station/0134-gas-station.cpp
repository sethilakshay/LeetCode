class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int i = 0, j = 0, n = gas.size();
        int totGas = 0, cnt = 0;
        
        while(i < n){
            j = i;
            
            totGas = 0;
            cnt = 0;
            
            while(cnt < n){
                totGas += gas[j] - cost[j];
                
                if(totGas < 0){
                    break;
                }
                j = (j+1)%n;
                cnt++;
            }
            
            if(totGas >= 0){
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