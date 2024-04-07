class Solution {
public:
    
    static const int sizer = 105;
    
    int DP[sizer][sizer];
    
    int func(int horiz, int vert, int n, int m){
       if(horiz==n && vert==m){
           return 1;
       }
        
        if(DP[horiz][vert]!=-1){
            return DP[horiz][vert];
        }
        
       int val1=0, val2=0;
        
        if((horiz+1)<=n){
            val1 = func(horiz+1, vert, n, m);
        }
        
        if((vert+1)<=m){
            val2 = func(horiz, vert+1, n, m);
        }
        
        return (DP[horiz][vert]) = (val1 + val2);
    }
    
    
    int uniquePaths(int m, int n) {
        
        memset(DP, -1, sizeof(DP));
        return func(1,1,n,m);
    }
};