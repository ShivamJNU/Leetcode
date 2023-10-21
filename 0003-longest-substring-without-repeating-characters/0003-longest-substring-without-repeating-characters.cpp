class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set1;
        int left = 0, right = 0;
        int maxa = 0;
        
        for (int i = 0; i < s.length() && right < s.length() && left < s.length(); i++) {
            if (set1.find(s[right]) == set1.end()) {
                set1.insert(s[right]);
                right++;
                int length = right - left;
                maxa = max(maxa, length);
                
            } else {
                while (set1.find(s[right]) != set1.end()&&right!=left) {
                    set1.erase(s[left]);
                    left++;
                }
                set1.insert(s[right]);
                right++;
            }

        }

        return maxa;
    }
};

