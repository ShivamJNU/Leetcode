class Solution {
public: 
    
    int DP[310][5010];
    
    int func(int amount, int index, vector<int>&coins){
        if(amount==0){
            return 1;
        }
        
        if(index<0){
            return 0;
        }
        
        if(DP[index][amount]!=-1){
            return DP[index][amount];
        }
        
        int ways=0;
        
        // Make loop while coin_amount<=amount
        
        for(int coin_amount=0;coin_amount<=amount; coin_amount+=coins[index]){
            ways+=func(amount-coin_amount, index-1, coins);
        }
        
        return DP[index][amount] = ways;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(DP, -1, sizeof(DP));
        
        int ans=func(amount, coins.size()-1, coins);
        
        if(ans==0){
            return 0;
        }
        
        return ans;
    }
};