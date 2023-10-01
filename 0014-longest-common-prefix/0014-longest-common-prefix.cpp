class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        string temp=strs[0];
        string final="";
        
        for(int i=1;i<strs.size();i++){
            final="";
            for(int j=0;j<min(strs[i].length(),temp.length());j++){
                if(strs[i][j]==temp[j]){
                    final+=strs[i][j];
                }else{
                    break;
                }
            }
            temp=final;
        }
        
        return final;
        
    }
};