class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        
        map<int, int> m1;
        
        for(auto e: nums){
            m1[e]++;
        }
        
        auto it = m1.begin();
        int fst = it->first;
        
        it++;
        
        while(it!=m1.end()){
            if((it->first) % fst != 0){
                return 1;
            }
            it++;
        }
        
        return (m1[fst] + 1)/2;
        
    }
};