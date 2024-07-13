class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        set<int> left;
        set<int> right;
        map<int, int> m1;

        for (int i = 0; i < positions.size(); i++)
        {

            m1[positions[i]] = i;

            if (directions[i] == 'L')
            {
                left.insert(positions[i]);
            }
            else
            {
                right.insert(positions[i]);
            }
        }

        vector<int> surviving;

        while (left.size() > 0 && right.size() > 0)
        {

            auto it2 = right.end();
            it2--;

            auto it1 = left.upper_bound(*it2);

            if (it1 == left.end())
            {
                surviving.push_back(m1[(*it2)]);
                right.erase(it2);
                continue;
            }

            int idx1 = m1[*it1];
            int idx2 = m1[*it2];

            if (healths[idx1] == healths[idx2])
            {
                left.erase(it1);
                right.erase(it2);
            }
            else if (healths[idx1] > healths[idx2])
            {
                healths[idx1]--;
                right.erase(it2);
            }
            else
            {
                healths[idx2]--;
                left.erase(it1);
            }
        }

        for (auto &e : left)
        {
            surviving.push_back(m1[e]);
        }

        for (auto &e : right)
        {
            surviving.push_back(m1[e]);
        }

        sort(surviving.begin(), surviving.end());

        for (auto &e : surviving)
        {
            e = healths[e];
        }

        return surviving;
    }
};