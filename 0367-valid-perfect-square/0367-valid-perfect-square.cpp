class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long high=num-1;
        long long low=1;
        
        if(high*1LL*high == (long long)num || low*1LL*low==(long long)num){
            return true;
        }
        
        while(high>=low){
            long long middle=(high+low)/2;
            
            if(middle*1LL*middle==num){
                return true;
            }else if(middle*1LL*middle>num){
                high=middle-1;
            }else if(middle*1LL*middle<num){
                low=middle+1;
            }
        }
        return false;
    }
};