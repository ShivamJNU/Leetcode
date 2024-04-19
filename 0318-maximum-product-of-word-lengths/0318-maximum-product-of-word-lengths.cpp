class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> label;
        
        // vector<vector<int>> label2;
        
        for(auto &e: words){
            vector<int> freq(26,0);
            
            for(auto &x: e){
                freq[x-'a']++;
            }
            
            label.push_back(freq);
        }
        
        int maxa = 0;
        
        for(int i = 0; i<label.size()-1; i++){
            for(int j=i+1; j<label.size(); j++){
                int len1 = 0, len2 = 0;
                
                bool con = true;
                
                for(int k=0;k<26; k++){
                    if(label[i][k]>0 && label[j][k]>0){
                        len1=0;
                        len2=0;
                        con = false;
                        break;
                    }else{
                        len1+=label[i][k];
                        len2+=label[j][k];
                    }
                }
                
                if(con){
                    maxa = max(maxa, len1*len2);
                }
            }
        }
        
        return maxa;
    }
};