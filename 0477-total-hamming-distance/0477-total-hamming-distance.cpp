class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total=0;
        
        // check different combinations for each bit

        for(int i=0;i<32;i++){
            int count=0; // keeps the count for set bits

            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)){
                    count++;
                }
            }

            total+=(count)*(nums.size()-count);
            // count: No. with ith Bit set
            // (nums.size() - count): No. with ith Bit unset
            
        }
        
        return total;
    }
};