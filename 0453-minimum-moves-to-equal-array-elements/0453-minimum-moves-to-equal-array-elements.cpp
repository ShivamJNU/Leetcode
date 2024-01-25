class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        
        for(auto &e: nums){
            mini = min(mini, e);
        }
        
        int total = 0;
        
        for(auto &e: nums){
            total += (e - mini);
        }
        
        return total;
        
    }
};