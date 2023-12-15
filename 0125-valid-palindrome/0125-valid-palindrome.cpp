class Solution {
public:
    bool isPalindrome(string s) {

        vector<char>vec1;

        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90){
                char c = (char) (s[i] + 32);
                vec1.push_back(c);
            }

            if((s[i]>=97 && s[i]<=122)||(s[i]>=48 && s[i]<=57)){
                vec1.push_back(s[i]);
            }
        }

        for(int i=0;i<(vec1.size()/2);i++){
            if(vec1[i]!=vec1[vec1.size()-1-i]){
                return false;
            }
        }

        return true;
    }
};