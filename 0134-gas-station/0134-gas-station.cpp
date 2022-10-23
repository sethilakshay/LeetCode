class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int i=0, j, n = gas.size();
        
        while(i<n){
            
            j = i;
            int cnt = n-1, tot_gas = 0;
            
            while(cnt>=0){
                tot_gas += gas[j] - cost[j];
                
                if(tot_gas < 0)
                    break;
                //Easily will adjust to rotation
                j = (j+1)%n;
                cnt--;
            }
            
            if(tot_gas >= 0)
                return i;
            //Very Important condition without which we will get infinite loop
            else if(j<i) 
                return -1;
            
            else
                i = j+1;
        }
        return -1;
    }
};