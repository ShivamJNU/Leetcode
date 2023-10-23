class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;

        int i=0,j=0;
        
        long long maxa=0;
        long long sum=0;

        while(j<nums.size()){
            if(j-i+1<k){
                m[nums[j]]++;
                sum+=nums[j];
                j++;
            }else if(j-i+1==k){
                m[nums[j]]++;
                sum+=nums[j];

                if(m.size()==k){
                    maxa=max(maxa,sum);
                }

                m[nums[i]]--;

                if(m[nums[i]]==0){m.erase(nums[i]);}
                sum=sum-nums[i];

                i++;
                j++;
            }
        }

        return maxa;

    }
};