class Solution
{
public:
    bool h(int i, int j, int n, int m, vector<vector<int>> &grid, int &f)
    {
        grid[i][j] = 1;
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
        {
            f = 1;
        }

        if (i + 1 <= n - 1 && grid[i + 1][j] == 0)
            h(i + 1, j, n, m, grid, f);
        if (i - 1 >= 0 && grid[i - 1][j] == 0)
            h(i - 1, j, n, m, grid, f);
        if (j + 1 <= m - 1 && grid[i][j + 1] == 0)
            h(i, j + 1, n, m, grid, f);
        if (j - 1 >= 0 && grid[i][j - 1] == 0)
            h(i, j - 1, n, m, grid, f);
        if (f == 1)
            return false;
        return true;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    int f = 0;
                    if (h(i, j, n, m, grid, f))
                        c++;
                }
            }
        }
        return c;
    }
};