class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        long long sum_n = 0, max_n = 0, armor_n = armor;
        
        for(long long n: damage){
            sum_n += n;
            max_n = max(n, max_n);
        }
        
        
        return sum_n - min(max_n, armor_n) + 1;
    }
};