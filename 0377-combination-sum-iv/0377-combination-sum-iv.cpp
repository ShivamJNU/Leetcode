class Solution {
public:
    
    int DP[1010];
    
    int maxam(vector<int>&nums, int target){
        
        if(target<0){
            return 0;
        }
        
        if(DP[target]!=-1){
            return DP[target];
        }
        
        if(target==0){
            return 1;
        }
        
        
        int ways=0;
        for(auto num: nums){
            ways+=maxam(nums, target-num);
        }
        
        return DP[target] = ways;
        
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(DP, -1, sizeof(DP));
        int ans=maxam(nums, target);
        return ans;
    }
};