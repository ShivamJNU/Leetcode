class Solution {
public:
    
    int total = 0;
    
    void func(int index, int sum, vector<int>&nums, int target){
        if(index==nums.size()){
            if(sum==target){
                total++;
            }
            return;
        }
        
        func(index+1, sum-nums[index], nums, target);
        func(index+1, sum+nums[index], nums, target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        func(0, 0, nums, target);
        
        return total;
    }
};