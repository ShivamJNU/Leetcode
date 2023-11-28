class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        unordered_map<char,int>m1,m2;
        
        for(auto e: word1){
            m1[e]++;
        }
        
        for(auto e: word2){
            m2[e]++;
        }
        
//         if(m1.size()==m2.size()){
//             return true;
//         }
        
        
        for(int i=0;i<26;i++){
            char first='a'+i;
            for(int j=0;j<26;j++){
                char second='a'+j;
                
                if(m1.find(first)!= m1.end() && m2.find(second)!=m2.end()){
                //if(m1[first]!=0 && m2[second]!=0)--> Will not work here.
                    
                    // int first_size=m1.size();
                    // int second_size=m2.size();
                    m1[second]++;
                    m2[first]++;
                    
                    m1[first]--;
                    if(m1[first]==0){
                        m1.erase(first);
                    }
                    
                    m2[second]--;
                    if(m2[second]==0){
                        m2.erase(second);
                    }
                    
                    if(m1.size()==m2.size()){
                        return true;
                    }
                    
                    m1[first]++;
                    m2[second]++;
                    
                    m1[second]--;
                    if(m1[second]==0){
                        m1.erase(second);
                    }
                    
                    m2[first]--;
                    if(m2[first]==0){
                        m2.erase(first);
                    }
                    
                }
            }
        }
        
        return false;
        
    }
};