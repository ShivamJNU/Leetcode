class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();

    vector<string> vec = strs;

    string prefix = vec[0];

    for (int i = 1; i < vec.size(); i++)
    {
        string temp = "";

        for (int j = 0; j < min(vec[i].length(), prefix.length()); j++)
        {
            if (prefix[j] == vec[i][j])
            {
                temp.push_back(prefix[j]);
            }
            else
            {
                break;
            }
        }

        prefix = temp;
    }

    return prefix;
        
    }
};