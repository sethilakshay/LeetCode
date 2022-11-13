class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        long sum = 0, max_n = 0;
        
        for(long n: damage){
            sum += n;
            max_n = max(n, max_n);
        }
        
        if(armor>max_n)
            return sum - max_n + 1;
        else
            return sum - armor+1;
    }
};