class Solution {
public:
    int lis(vector<int>&nums, int index, vector<int>&DP){
        if(DP[index]!=-1){
            return DP[index];
        }
        
        int maxa=1;
        
            for(int j=index-1;j>=0;j--){
                if(nums[j]<nums[index]){
                    maxa=max(maxa, lis(nums, j, DP)+1);
                }
            }
        
        return DP[index]=maxa;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int maxa=1;
        int n=nums.size();
        
        vector<int>DP(n,-1);
        DP[0]=1;
        
        for(int i=n-1;i>=0;i--){
            maxa=max(maxa,lis(nums, i, DP));
            
        }
    
    return maxa;
    }
};