class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0;

        for (auto& e : logs) {
            if (e == "./") {
                continue;
            } else if (e == "../") {
                if (ops > 0) {
                    ops--;
                }
            } else {
                ops++;
            }
        }

        return ops;
    }
};