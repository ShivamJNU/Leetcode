class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int first_place_x=0;
        int first_place_y=0;

        for(int i=0;i<s1.length();i++){
            if(s1[i]=='x' && s2[i]=='y'){
                    first_place_x++;
                }else if(s1[i]=='y' && s2[i]=='x'){
                    first_place_y++;
                }
        }

        if((first_place_x+first_place_y)%2==0){

            int total=0;

            total+=(first_place_x/2)+(first_place_x%2);
            total+=(first_place_y/2)+(first_place_y%2);
            
            return total;
        }

        return -1;
    }
};