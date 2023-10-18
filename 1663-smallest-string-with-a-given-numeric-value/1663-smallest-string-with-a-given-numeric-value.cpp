class Solution {
public:
    string getSmallestString(int n, int k) {
        string final="";

        for(int i=0;i<n;i++){
            final+='z';
        }

        k=n*26-k;
        for(int i=0;i<final.length();i++){
            int deductable=min(25,k);

            final[i]=(char)(final[i]-deductable);
            k-=deductable;

            if(k==0){
                break;
            }
        }

        return final;

    }
};