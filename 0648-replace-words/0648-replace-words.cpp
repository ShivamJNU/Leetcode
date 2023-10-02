class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int>m;
        
        for(auto e : dictionary){
            m[e]++;
        }
        
        vector<string>vec1;
        
        string temp="";
        
        for(auto e : sentence){
            if(e==' '){
                vec1.push_back(temp);
                temp="";
            }else{
                temp+=e;
            }
        }
        vec1.push_back(temp);
        
        for(auto &e : vec1){
            string temp="";
            for(int i=0;i<e.length();i++){
                temp+=e[i];
                if(m[temp]){
                    e=temp;
                    break;
                }
            }
        }
        
        string return_string="";
        
        for(int i=0;i<vec1.size();i++){
            return_string+=vec1[i];
            if(i!=vec1.size()-1){
                return_string+=' ';
            }
        }
        
        return return_string;
        
    }
};