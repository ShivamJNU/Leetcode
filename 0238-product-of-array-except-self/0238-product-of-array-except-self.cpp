class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int n=nums.size();
        
        vector<int>prefix(n,0);
        
        for(int i=0;i<n;i++){
            prefix[i]=prod;
            prod=prod*nums[i];
        }
        
        vector<int>suffix(n,0);
        
        prod=1;
        
        for(int i=n-1;i>=0;i--){
            suffix[i]=prod;
            prod=prod*nums[i];
        }
        
        vector<int>returning(n,0);
        
        for(int i=0;i<n;i++){
            returning[i]=prefix[i]*suffix[i];
        }
        
        return returning;
        
    }
};