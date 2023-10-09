class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftmost=-1,rightmost=-1;

        int high=nums.size()-1;
        int low=0;

        // leftmost index
        while(high-low>1){
           int mid=(low+high)/2;
           if(nums[mid]==target){
               leftmost=mid;
               high=mid;
           }else if(nums[mid]>target){
               high=mid-1;
           }else{
               low=mid+1;
           }
        }

        if((high>=0)&& /*(high<nums.size())&&*/(nums[high]==target)){
            leftmost=high;
        }
        if(/*(low>=0)&&*/ (low<nums.size())&&(nums[low]==target)){
            leftmost=low;
        }

        high=nums.size()-1;
        low=0;
        
        // rightmost index
        while(high-low>1){
           int mid=(low+high)/2;
           if(nums[mid]==target){
               rightmost=mid;
               low=mid;
           }else if(nums[mid]>target){
               high=mid-1;
           }else{
               low=mid+1;
           }
        }

        if(/*(low>=0)&&*/ (low<nums.size())&&(nums[low]==target)){
            rightmost=low;
        }
        
        if((high>=0)&& /*(high<nums.size())&&*/(nums[high]==target)){
            rightmost=high;
        }
        

        return {leftmost,rightmost};
    }
};