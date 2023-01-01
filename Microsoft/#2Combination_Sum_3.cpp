class Solution
{
public:
    void help(int j, int k, int n, vector<vector<int>> &ans, vector<int> &dk)
    {
        if (k == 0)
        {
            if (n == 0)
            {
                ans.push_back(dk);
            }
            return;
        }
        for (int i = j; i <= 9; i++)
        {
            if (i <= n)
            {
                dk.push_back(i);
                help(i + 1, k - 1, n - i, ans, dk);
                dk.pop_back();
            }
            else
                return;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> dk;
        help(1, k, n, ans, dk);
        return ans;
    }
};