class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()==k){
            return true;
        }else if(s.length()<k){
            return false;
        }
        
        unordered_map<char,int>m;
        
        for(auto e:s){
            m[e]++;        
        }
        
        int oddCount=0;
        
        for(auto e: m){
            if(e.second%2==1){
                oddCount++;
            }
        }
        
        if(oddCount>k){
            return false;
        }
        
        return true;
    }
};