class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        map<int,int>right_min_elements;
        map<int,int>left_min_elements;

        int left_min_element=nums[0];
        int right_min_element=nums[nums.size()-1];

        int mini=INT_MAX;

        for(int i=1;i<nums.size();i++){
            left_min_elements[i]=left_min_element;
            left_min_element=min(left_min_element,nums[i]);
        }

        for(int i=nums.size()-2;i>=0;i--){
            right_min_elements[i]=right_min_element;
            right_min_element=min(right_min_element,nums[i]);
        }

        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>left_min_elements[i] && nums[i]>right_min_elements[i]){
                int sum=nums[i]+left_min_elements[i]+right_min_elements[i];
                mini=min(mini,sum);
            }
        }

        if(mini==INT_MAX){
            return -1;
        }
        
        return mini;
    }
};