class Solution {
public:
/* The below approach is incorrect because the DP[index] is set only once for a given index and does not gets updated even if a smaller value is encountered in future.*/  
    /*int DP[10010];
    
    int func(vector<int>&nums, int index, int jumps){
        
        if(index>=(nums.size()-1)){
            return jumps;
        }
        
        if(DP[index]!=-1){
            return DP[index];
        }
        
        if (nums[index] == 0) {
            return DP[index] = INT_MAX;
        }
        
        int mini=INT_MAX;
        
        for(int i=1;i<=nums[index];i++){
            mini=min(mini, func(nums, index+i, jumps+1));
        }
        
        return DP[index]=mini;
        
    }
    
    int jump(vector<int>& nums) {
        
        memset(DP, -1, sizeof(DP));
        int ans=func(nums, 0, 0);
        
        return ans;
        
    }
};*/
    
    int DP[10010];
    
    int func(vector<int>&nums, int index){
        
        if(index>=(nums.size()-1)){
            return 0;
        }
        
        if(DP[index]!=-1){
            return DP[index];
        }
        
        if (nums[index] == 0) {
            return DP[index] = INT_MAX-10;
        }
        
        int mini=INT_MAX-10;
        
        for(int i=1;i<=nums[index];i++){
            mini=min(mini, 1+func(nums, index+i));
        }
        
        return DP[index]=mini;
        
    }
    
    int jump(vector<int>& nums) {
        
        memset(DP, -1, sizeof(DP));
        
        int ans=func(nums, 0);
        
        return ans;
        
    }
};