class Solution {
public:
    int minSwaps(string s) {
        int odd_one=0,odd_zero=0,even_one=0,even_zero=0;

        for(int i=0;i<s.length();i++){
            if(i%2==0){
                if(s[i]=='1'){
                    even_one++;
                }else{
                    even_zero++;
                }
            }else{
                if(s[i]=='1'){
                    odd_one++;
                }else{
                    odd_zero++;
                }
            }
        }

            // All zeroes should either be on odd index or on even index

            int move1=-1; //i.e. moves required to shift zeroes on even index

            if(odd_zero==even_one){
                move1=odd_zero;
            }

            int move2=-1; //i.e. moves required to shift zeroes on odd index

            if(odd_one==even_zero){
                move2=odd_one;
            }

            if(move1==-1 && move2!=-1){
                return move2;
            }else if(move1!=-1 && move2==-1){
                return move1;
            }else if(move1!=-1 && move2!=-1){
                return min(move1,move2);
            }

            

        

        return -1;
    }
};