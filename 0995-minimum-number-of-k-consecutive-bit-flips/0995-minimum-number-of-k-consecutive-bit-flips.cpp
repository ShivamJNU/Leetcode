class Solution {
public:
            int minKBitFlips(vector<int> &nums, int k)
        {

            vector<int> indices;

            int ans = 0;

            for (int i = 0; i < nums.size(); i++)
            {

                auto it = lower_bound(indices.begin(), indices.end(), (i - k + 1));

                int cnt = 0;

                if (it != indices.end())
                {
                    int curr = (it - indices.begin());

                    cnt = (indices.size() - curr);
                }

                if (cnt % 2 == 1)
                {
                    nums[i] = (nums[i] ^ 1);
                }

                if (nums[i] == 0)
                {

                    if ((i + k - 1) >= nums.size())
                    {
                        continue;
                    }

                    nums[i] = 1;

                    indices.push_back(i);
                    ans++;
                }
            }

            for (auto &e : nums)
            {
                if (e == 0)
                {
                    return -1;
                }
            }

            return ans;
        }
};