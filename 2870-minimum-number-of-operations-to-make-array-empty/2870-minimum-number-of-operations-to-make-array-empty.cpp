class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;

        for(auto e : nums){
            m[e]++;
        }

        int count=0;

        for(auto e : m){

            if(e.second==1){
                count=-1;
                break;
            }else if(e.second%3==0){
                count+=e.second/3;
            }else if(e.second%3==2){
                count+=e.second/3+1;
            }else if(e.second%3==1){
                count+=(e.second-4)/3+2;
            }
        }

        return count;

    }
};