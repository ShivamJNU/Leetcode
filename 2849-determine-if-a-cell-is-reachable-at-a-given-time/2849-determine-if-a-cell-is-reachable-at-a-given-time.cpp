class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int req_moves=max(abs(fx-sx),abs(fy-sy));
        // movement: 5 on x  and  3 on y
        // total must be 6.

        // 1 on y + 2 on diagonal + 3 on x
        if(req_moves==0){
            if(t==1){
                return false;
            }else{
                return true;
            }
        }

        if(req_moves>0 && t>=req_moves){
            return true;
        } 
        
        

        return false;

    }
};