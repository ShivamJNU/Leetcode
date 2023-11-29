class Solution {
public:
    int DP[105];
    
    
    int maxum(vector<int>&nums, int index){
        
        if(index<0){
            return 0;
        }
        
        if(DP[index]!=-1){
            return DP[index];
        }
        
        //Choose the number at index
        int total1=nums[index]+maxum(nums, index-2);
        
        // Do not choose the number at index;
        int total2=maxum(nums,index-1);
        
        return DP[index]=max(total1, total2);
    }
    
    
    int rob(vector<int>& nums) {
        
        memset(DP, -1, sizeof(DP));
        int ans=maxum(nums, nums.size()-1);
        return ans;
        
    }
};