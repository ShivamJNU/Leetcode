class Solution {
public:
    
    int DP[(const int)205][(const int)(1e4 + 10)];
    
    bool func(int left, int index, vector<int> &nums){
        if(left == 0){
            return true;
        }
        
        if(index==nums.size()){
            return false;
        }
        
        if(DP[index][left]!=-1){
            return DP[index][left];
        }
        
        int con1 = false, con2 = false;
        
        con1 = func(left, index+1, nums);
        
        if(left-nums[index]>=0){
            con2 = func(left-nums[index], index+1, nums);
        }
        
        if(con1==true || con2==true){
            return DP[index][left] = 1;
        }
        
        return DP[index][left] = 0;
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        memset(DP, -1, sizeof(DP));
        
        int sum = 0;
        
        for(auto &e: nums){
            sum+=e;
        }
        
        if(sum%2==1){
            return 0;
        }
        
        int req = sum/2;
        
        return func(req, 0, nums);
        
    }
};