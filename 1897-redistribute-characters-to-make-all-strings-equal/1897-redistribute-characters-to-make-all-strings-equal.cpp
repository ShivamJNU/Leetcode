class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        map<char, int> m1;
        
        for(int i=0; i<words.size(); i++){
            for(auto e: words[i]){
                m1[e]++;
            }
        }
        
        for(auto e: m1){
            if((e.second%words.size())!=0){
                return false;
            }
        }
        
        return true;
        
    }
};