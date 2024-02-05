class Solution {
public:
long long maximumSubarraySum(vector<int> &nums, int k)
{

    
    // Make a map of sum ending with a given number.
    
    map<long long, long long> m2;
    
    long long maxa = LLONG_MIN;
    bool con = true;
    
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += (long long)nums[i];
        
        if(m2.find(nums[i])==m2.end()){
            m2[nums[i]]=sum;
        }else{
            m2[nums[i]] = min(m2[nums[i]], sum);
        }
        
        long long fst = nums[i];
        long long snd = (long long)k + nums[i];
        
        if(m2.find(snd)!=m2.end()){
            con = false;
            maxa = max(maxa, sum-m2[snd]+snd);
        }
        
        
        snd = nums[i] - k;
        if(m2.find(snd)!=m2.end()){
            con = false;
            maxa = max(maxa, sum-m2[snd]+snd);
        }

        
    }
    
    if(con){
        return 0LL;
    }

    return maxa;
}
};