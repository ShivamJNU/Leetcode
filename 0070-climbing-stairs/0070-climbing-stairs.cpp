class Solution {
public:
    
    int DP[50];
    
    int func(int n){
        if(n==0){
            return 1;
        }
        
        if(n==1){
            return 1;
        }
        
        if(DP[n]!=-1){
            return DP[n];
        }
        
        int ans=func(n-1)+func(n-2);
        
        return DP[n]=ans;
    }
    
    int climbStairs(int n) {
        memset(DP, -1, sizeof(DP));
        
        int ans=func(n);
        
        return ans;
        
    }
    
};
