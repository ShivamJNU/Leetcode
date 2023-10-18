class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        int count1=0, count2=0;

        for(int i=0;i<s1.length();i++){
            if(s1[i]>s2[i]){
                count1++;
            }else if(s2[i]>s1[i]){
                count2++;
            }else{
                count1++;
                count2++;
            }
        }

        if(count1==s1.length() || count2==s2.length()){
            return true;
        }

        return false;

    }
};