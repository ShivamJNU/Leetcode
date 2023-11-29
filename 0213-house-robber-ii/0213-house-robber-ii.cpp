class Solution {
public:
    // My first intution is to keep a flag whether the last element was selected or not
    // Then work accordingly while selecting the first element.
    
    int DP[105];
    
    int func(vector<int>&nums, int index){
        if(index<0){
            return 0;
        }
        
        if(DP[index]!=-1){
            return DP[index];
        }
        
        
        int ans1,ans2;
        
            ans1=func(nums, index-1);
            ans2=func(nums, index-2)+nums[index];
        
        return DP[index]=max(ans1, ans2);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        memset(DP, -1, sizeof(DP));
        int last=nums[nums.size()-1];
        nums.pop_back();
        
        int ans1;
        
        if(nums.size()==0){
            ans1=0;
        }else{
            ans1=func(nums, nums.size()-1);
        }
        
        memset(DP, -1, sizeof(DP));
        nums.push_back(last);
        nums.erase(nums.begin());
        
        int ans2;
        if(nums.size()==0){
            ans2=0;
        }else{
            ans2=func(nums, nums.size()-1);
        }
        
        int ans=max(ans1, ans2);
        
        return ans;
    }
    
};