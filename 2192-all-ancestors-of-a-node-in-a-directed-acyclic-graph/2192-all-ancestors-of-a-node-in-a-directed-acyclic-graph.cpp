class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        // Just tree the edges in an opposite manner and do BFS on each node.

        // {from, to} -> {to, from}

        vector<vector<int>> Graph(n);

        for (auto &e : edges)
        {
            int src = e[1];
            int dst = e[0];

            Graph[src].push_back(dst);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            // Run BFS on the ith node.

            queue<int> Q;

            vector<int> visited(n);
            
            Q.push(i);

            while (!Q.empty())
            {
                int nod = Q.front();
                Q.pop();

                visited[nod] = 1;

                for (auto &child : Graph[nod])
                {
                    if (!visited[child])
                    {
                        Q.push(child);
                    }
                }
            }

            vector<int> temp;

            for (int j = 0; j < n; j++)
            {
                if (visited[j] && (j!=i))
                {
                    temp.push_back(j);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};