class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int max=INT_MIN;

        for(int i=0;i<(nums.size()/2);i++){
            int sum=nums[i]+nums[nums.size()-i-1];
            if(sum>max){
                max=sum;
            }
        }
        return max;
    }
};