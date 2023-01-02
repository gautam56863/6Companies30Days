class Solution
{
public:
    bool dfs(int idx, vector<int> &vis, vector<vector<int>> &adj, vector<int> &dfsvis)
    {
        vis[idx] = 1;
        dfsvis[idx] = 1;
        for (auto it : adj[idx])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, adj, dfsvis))
                    return true;
            }
            else if (dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[idx] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, adj, dfsvis))
                    return false;
            }
        }
        return true;
    }
};