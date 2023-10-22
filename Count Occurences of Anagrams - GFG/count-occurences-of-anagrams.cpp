//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int search(string pat, string txt) {
        
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
        //int j=0;
        int j = pat.length() - 1;
        
        while (j < txt.length()) {
            
            
            
            if(mp.find(txt[j])!=mp.end()){
                
                
                mp[txt[j]]--;
                if (mp[txt[j]] == 0) {
                    dist_elements--;
                }
            
                
            }

            if(j-i+1<pat.length()){
                j++;
            }else{
                if(dist_elements==0){
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
            
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends