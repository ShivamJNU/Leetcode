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
        if(temp!=""){
            vec1.push_back(temp);
        }
        
        string return_string="";

        for(int i=vec1.size()-1;i>=0;i--){
            return_string+=vec1[i];
            if(i!=0)return_string+=' ';
        }

        return return_string;
    }
};