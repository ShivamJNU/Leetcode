class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>m1;
        int length = 0;
        int max_length = 0;
        
        int i=0,j=0;
        
        while(i<nums.size() && j<nums.size()){
            if(m1[nums[j]]<k){
                m1[nums[j]]++;
                length++;
                max_length = max(max_length,length);
                j++;
            }else{
                m1[nums[i]]--;
                length--;
                i++;
            }
        }
        return max_length;
    }
};