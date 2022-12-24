class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        
        long long totSum = 0;
        int maxDamage = INT_MIN;
        for(int i=0; i<damage.size(); i++){
            totSum += damage[i];
            maxDamage = max(damage[i], maxDamage);
        }
        
        return totSum - min(maxDamage, armor) + 1;
    }
};