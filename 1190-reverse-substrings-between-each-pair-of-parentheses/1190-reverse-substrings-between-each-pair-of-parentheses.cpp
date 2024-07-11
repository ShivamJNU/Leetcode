class Solution {
public:
    
    string reverseParentheses(string s) {
        
        stack<char> st;
        
        string ans = "";
        
        for(auto &e: s){
            
            if(e==')'){
                
                string str = "";
                
                while(true){
                    
                    if(st.top()=='('){
                        st.pop();
                        break;
                    }else{
                        str.push_back(st.top());
                        st.pop();
                    }
                }
                
                for(auto &f: str){
                    st.push(f);
                }
                
            }else{
                st.push(e);
            }
        }
        
        while(true){
            if(st.empty()){
                break;
            }
            if(st.top()=='('){
                        st.pop();
                        break;
                    }else{
                        ans.push_back(st.top());
                        st.pop();
                    }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};