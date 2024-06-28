class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n, 0);
        
        for(auto &e: roads){
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        sort(degree.begin(), degree.end(), greater<int>());
        
        int start = n;
        
        long long ans = 0;
        
        for(auto &e: degree){
            ans+=(start*1LL*e);
            start--;
        }
        
        return ans;
    }
};