class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec1;
        string temp="";

        for(int i=0;i<s.length();i++){
            if((s[i]!=' ')&&(i!=s.length()-1)&&(s[i+1]==' ')){
                temp+=s[i];
                vec1.push_back(temp);
                temp="";
            }else if((s[i]!=' ')&&(i!=s.length()-1)&&(s[i+1]!=' ')){
                temp+=s[i];
            }else if((s[i]!=' ')&&(i==s.length()-1)){
                temp+=s[i];
                vec1.push_back(temp);
                temp="";
            }
        }
        
        string return_string="";

        for(int i=0;i<vec1.size();i++){
            for(int j=vec1[i].length()-1;j>=0;j--){
                return_string+=vec1[i][j];
            }
            if(i!=vec1.size()-1)return_string+=' ';
        }

        return return_string;
    }
};