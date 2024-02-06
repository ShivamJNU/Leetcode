class Solution {
public:
    
    map<int, int> m1;
    
    vector<vector<int>> Glob;
    
    void func(int index, vector<int>&nums, vector<int>&temp){
        if(index==nums.size()){
            Glob.push_back(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(m1.find(nums[i])==m1.end()){
                m1[nums[i]]++;
                temp.push_back(nums[i]);
                func(index+1, nums, temp);
                temp.pop_back();
                m1.erase(nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        
        func(0, nums, temp);
        
        return Glob;
    }
};