class Solution {
public:
    int mini(int amount,vector<int>&coins,vector<int> &DP){
        if(amount==0){
            return 0;
        }
        
        if(DP[amount]!=-1){
            return DP[amount];
        }
        
        int maxa=INT_MAX;
        
        for(auto coin: coins){
            if(amount-coin>=0){
                maxa=min(maxa+0LL, mini(amount-coin, coins, DP)+1LL);
            }
        }
        return DP[amount]=maxa;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>DP(1e4+10,-1);
        int ans=mini(amount, coins, DP);
        
        if(ans==INT_MAX){
            return -1;
        }
        
        return ans;
    }
};