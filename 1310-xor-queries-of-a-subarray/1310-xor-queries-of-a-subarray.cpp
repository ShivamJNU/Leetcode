class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>xor_result;
        int element=0;

        xor_result.push_back(element);

        for(int i=0;i<arr.size();i++){
            element=element^arr[i];
            xor_result.push_back(element);
        }

        vector<int>returning;

        for(int i=0;i<queries.size();i++){
            returning.push_back(xor_result[queries[i][0]]^xor_result[queries[i][1]+1]);
        }

        return returning;
    }
};