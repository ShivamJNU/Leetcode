class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                
                if(tokens[i]=="+"){
                    st.push(num1+num2);
                }
                if(tokens[i]=="-"){
                    st.push(num2-num1);
                }
                if(tokens[i]=="/"){
                    st.push(num2/num1);
                }
                if(tokens[i]=="*"){
                    st.push(num1*num2);
                }
            }else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        
        return st.top();
    }
};