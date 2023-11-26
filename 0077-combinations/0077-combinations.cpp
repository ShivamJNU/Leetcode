class Solution {
public:
    
    vector<vector<int>>returning;
    
    void generate(int index, int n, int k, vector<int> &current){
        if(current.size()==k){
            returning.push_back(current);
            return;
        }
        
        for(int i=index;i<=n;i++){
            current.push_back(i);
            index++;
        generate(index, n, k, current);
        current.pop_back();
        }
        
        
        
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        generate(1, n, k, current);
        return returning;
    }
};