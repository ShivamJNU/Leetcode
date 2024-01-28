class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        
        int ans = 0;
        int mask = 0;

        for(int i=30; i>=0; i--){
            mask = mask + (1<<i); //mask stores how many bits has been set

            int consecAnd = mask;
            int cnt = 0;

            for(auto &e: nums){
                consecAnd = consecAnd & e; 

                if((consecAnd|ans)!=ans){
                    cnt++;
                }else{
                    consecAnd = mask;
                }
            }

            if(cnt>k){
                ans+=(1<<i);
            }
        }

        return ans;

    }
};