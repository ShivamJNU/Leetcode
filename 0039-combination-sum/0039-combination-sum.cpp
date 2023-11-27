class Solution {
public:
    
    vector<vector<int>>returning;
    
    void generate(vector<int> & candidates, vector<int>comb, int index, int target){
        if(target==0){
            returning.push_back(comb);
            return;
        }
        
        if(index>=candidates.size()){
            return;
        }
        
        generate(candidates, comb, index+1, target);
        for(int candidate=candidates[index];candidate<=target;candidate+=candidates[index]){
            comb.push_back(candidates[index]);
            generate(candidates, comb, index+1, target-candidate);
            //comb.pop_back();
            
        }
        
        return;
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>comb;
        generate(candidates, comb, 0, target);
        
        return returning;
    }
};