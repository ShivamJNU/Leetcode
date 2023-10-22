class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        string pat=p;
        string txt=s;

        vector<int>returning;

        map<char, int> mp;
        
        for (auto e : pat) {
            mp[e]++;
        }
        
        int dist_elements = mp.size();
        int ans = 0;
        
        for (int j = 0; j < pat.length()-1; j++) { 

            if(mp.find(txt[j])!=mp.end()){
               
                mp[txt[j]]--;
                if (mp[txt[j]] == 0) {
                    dist_elements--;
                    
                }
            
                
            }
            
        }
        
        int i = 0;
        int j = pat.length() - 1;
        
        while (j < txt.length()) {
            
            
            
            if(mp.find(txt[j])!=mp.end()){
                
                
                mp[txt[j]]--;
                if (mp[txt[j]] == 0) {
                    dist_elements--;
                }
            
                
            }

            
                if(dist_elements==0){
                    returning.push_back(i);
                ans++;
            }

            if(mp.find(txt[i])!=mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]]==1){
                    dist_elements++;
                }
                
            }
            
            i++;
            j++;

            
            
        }
        

        return returning;
    }
};