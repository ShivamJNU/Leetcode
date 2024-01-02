class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        map<int, int> m1;

        for(auto &e: nums){
            m1[e]++;
        }

        int maxa = 0;

        for(auto e: m1){
            maxa = max(maxa, e.second);
        }

        vector<vector<int>> ans(maxa);

        for(auto &e : m1){
            for(int i = 0; i<e.second; i++){
                ans[i].push_back(e.first);
            }
        }

        return ans;



    }
};