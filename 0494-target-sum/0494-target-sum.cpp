class Solution {
public:
    
    // int total = 0;
    
    int func(int index, int sum, vector<int>&nums, int target){
        if(index==nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        
        int x1 = func(index+1, sum-nums[index], nums, target);
        int x2 = func(index+1, sum+nums[index], nums, target);
        
        return (x1+x2);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        total = func(0, 0, nums, target);
        
        return total;
    }
};