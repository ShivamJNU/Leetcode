class Solution {
public:
    int maxDepth(string s) {
        int maxa = 0;
        int cnt = 0;
        
        stack<char> st;
        
        for(auto &e: s){
            if(e=='('){
                    st.push(e);
                    maxa = max(maxa, (int)(st.size()));
            }
                
            if(e==')'){
                    st.pop();
                }
            
        }
        
        
        return maxa;
        
    }
};