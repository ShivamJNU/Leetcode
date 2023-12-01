class Solution {
public:
    long long DP[100005][2];
    
    long long func(vector<int>&nums, int index, int parity, int x){

        if(index==nums.size()){
            return 0;
        }

        if(DP[index][parity]!=-1){
            return DP[index][parity];
        }

        int parity_temp=nums[index]%2;

        long long ans=func(nums, index+1, parity, x);

        long long temp_val;

        if(parity==parity_temp){
            temp_val=nums[index];
        }else{
            temp_val=nums[index]-x;
        }

        ans=max(ans, temp_val+func(nums, index+1, parity_temp, x));
        
        return DP[index][parity]=ans;
    }
    
    long long maxScore(vector<int>& nums, int x) {
        
        memset(DP, -1, sizeof(DP));
        
        int parity=nums[0]%2;
        
        long long ans = func(nums, 0, parity, x);
        
        return ans;
    }
};


// The below code fails bacause its time complexity is O(N^2) as apporx N calls are
// made for each index:

/*class Solution {
public:
    long long DP[100005][2];
    
    long long func(vector<int>&nums, int index, int parity, int x){

        if(index==nums.size()){
            return 0;
        }

        if(DP[index][parity]!=-1){
            return DP[index][parity];
        }

        int parity_temp=nums[index]%2;

        long long ans=nums[index];
        
        for(int i=1;(i+index)<nums.size();i++){
            ans=max(ans, nums[index]+func(nums, index+i, parity_temp, x));
        }
        
        if(parity!=parity_temp){
            ans=max(0LL, ans-x);
        }
        
        return DP[index][parity]=ans;
    }
    
    long long maxScore(vector<int>& nums, int x) {
        
        memset(DP, -1, sizeof(DP));
        
        int parity=nums[0]%2;

        long long ans = func(nums, 0, parity, x);
        
        return ans;
    }
};*/