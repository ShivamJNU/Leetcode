class Solution {
public:
    
    int DP[40];
    
    int func(int i){
        if(DP[i]!=-1){
            return DP[i];
        }
        
        return DP[i]=(func(i-1)+func(i-2)+func(i-3));
    }
    
    int tribonacci(int n) {
        memset(DP, -1, sizeof(DP));
        DP[0] = 0;
        DP[1] = 1;
        DP[2] = 1;
        
        return func(n);
    }
};