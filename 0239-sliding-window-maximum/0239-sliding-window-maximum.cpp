class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> pq;
        vector<int>vec1;

        for(int i=0;i<k;i++){
            pq.insert(nums[i]);
        }

        auto it=pq.rbegin();

        vec1.push_back(*it);

        for(int i=k;i<nums.size();i++){
            pq.erase(pq.lower_bound(nums[i-k]));
            pq.insert(nums[i]);

            auto it=pq.rbegin();
            vec1.push_back(*it);
        }

        return vec1;

    }
};