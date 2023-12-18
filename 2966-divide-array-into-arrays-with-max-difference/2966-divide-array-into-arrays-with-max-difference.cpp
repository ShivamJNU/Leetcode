class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> returning;
        
        for(int i=0;i<nums.size();i=i+3){
            if((nums[i+1]-nums[i]<=k) && (nums[i+2]-nums[i+1]<=k) && (nums[i+2]-nums[i]<=k)){
                vector<int>vec1;
                
                vec1.push_back(nums[i]);
                vec1.push_back(nums[i+1]);
                vec1.push_back(nums[i+2]);
                
                returning.push_back(vec1);
            }else{
                vector<vector<int>>vec1;
                return vec1;
            }
        }
        
        return returning;
        
    }
};