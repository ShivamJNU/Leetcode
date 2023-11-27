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


// Striver's Solution:
// class Solution {
// public: 
//     void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
//         if(ind == arr.size()) {
//             if(target == 0) {
//                 ans.push_back(ds); 
//             }
//             return; 
//         }
//         // pick up the element 
//         if(arr[ind] <= target) {
//             ds.push_back(arr[ind]); 
//             findCombination(ind, target - arr[ind], arr, ans, ds); 
//             ds.pop_back(); 
//         }
        
//         findCombination(ind+1, target, arr, ans, ds); 
        
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ans; 
//         vector<int> ds; 
//         findCombination(0, target, candidates, ans, ds); 
//         return ans; 
//     }
// };