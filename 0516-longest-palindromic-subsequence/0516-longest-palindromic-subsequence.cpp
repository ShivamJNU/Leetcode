class Solution {
public:
    
    int DP[1005][1005];
    
    int func(int left, int right, string &s){
        if(left==right){
            return 1;
        }
        
        if(left>right){
            return 0;
        }
        
        if(DP[left][right]!=-1){
            return DP[left][right];
        }
        
        if(s[left]==s[right]){
            return DP[left][right] = (2 + func(left+1, right-1, s));
        }
        
        int fst = func(left+1, right, s);
        fst = max(fst, func(left, right-1, s));
        
        return DP[left][right] = fst;
    }
    
    int longestPalindromeSubseq(string s) {
        memset(DP, -1, sizeof(DP));
        
        return func(0, s.length()-1, s);
    }
};