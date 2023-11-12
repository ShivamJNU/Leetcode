class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxa=1;
        int length=1;

        for(int i=1;i<s.length();i++){
            if((int)(s[i]-s[i-1])==1){
                length++;
                maxa=max(maxa,length);
            }else{
                maxa=max(maxa,length);
                length=1;
            }
        }

        return maxa;
        
    }
};