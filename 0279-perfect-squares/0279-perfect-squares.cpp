class Solution {
public:
    
    vector<int> vec;
    
    static const int sizer = 1e4 + 10;
    int DP[sizer][105];
    
    int func(int index, int sum, int total){
        if(sum==0){
            return 0;
        }
        
        if(index>=vec.size()){
            return 1e9;
        }
        
        if(sum<vec[index]){
            return 1e9;
        }
        
        if(DP[sum][index]!=-1){
            return DP[sum][index];
        }
        
        int fst = func(index+1, sum, total);
        int snd = func(index, sum-vec[index], total)+1;
        
        return DP[sum][index] = (min(fst, snd));
        
    }
    
    int numSquares(int n) {
        
        memset(DP, -1, sizeof(DP));
        
        for(int i=1; i<=100; i++){
            vec.push_back(i*i);
        }
        
        
        int x = func(0, n, 0);
        
        return x;
    }
};