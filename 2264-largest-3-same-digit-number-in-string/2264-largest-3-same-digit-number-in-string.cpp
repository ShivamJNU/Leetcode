class Solution {
public:
    string largestGoodInteger(string num) {
        int count=1;
        string str;
        str.push_back(num[0]);

        string final="";
        int final_score=0;

        for(int i=1; i<num.length();i++){
            if(num[i]==num[i-1]){
                count++;
                str.push_back(num[i]);
            }else{
                str=num[i];
                count=1;
            }

            if(count==3){
                int score=3*num[i];
                if(score>final_score){
                    final=str;
                    final_score=score;
                }
                str="";
                str.push_back(num[i]);
                count=1;
            }
        }
        return final;
    }
};