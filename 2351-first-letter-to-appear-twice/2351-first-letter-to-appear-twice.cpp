class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> freq(26, 0);
        
        for(auto e: s){
            freq[(int)(e-'a')]++;
            
            for(int i = 0; i<26; i++){
                if(freq[i]==2){
                    return (char)(i+'a');
                }
            }
        }
        
        
        return 'c';
    }
};