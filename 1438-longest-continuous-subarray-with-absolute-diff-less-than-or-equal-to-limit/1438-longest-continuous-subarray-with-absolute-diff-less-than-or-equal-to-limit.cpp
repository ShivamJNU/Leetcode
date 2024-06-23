class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int left = 0, right = 0;

        map<int, int> m1;

        int maxa = 1;

        while (right < nums.size()) {

            m1[nums[right]]++;

            auto it = m1.begin();

            int fst = it->first;

            it = m1.end();

            it--;

            int snd = it->first;

            int diff = abs(fst - snd);

            while (diff > limit) {

                m1[nums[left]]--;

                if (m1[nums[left]] == 0) {
                    m1.erase(nums[left]);
                }

                left++;

                it = m1.begin();

                fst = it->first;

                it = m1.end();

                it--;

                snd = it->first;

                diff = abs(fst - snd);
            }

            maxa = max(maxa, right - left + 1);

            right++;
        }

        return maxa;
    }
};