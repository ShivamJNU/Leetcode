class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<long long>> m1;

        for (int i = 0; i < logs.size(); i++) {
            m1[logs[i][0]].insert(logs[i][1]);
        }

        //unordered_map<long long, long long> m1;

        vector<int> returning(k, 0);

        for (auto e: m1) {
            int index = e.second.size();  
            if (index > 0 && index <= k) { 
                returning[index - 1]++;    
            }
        }

        return returning;
    }
};
