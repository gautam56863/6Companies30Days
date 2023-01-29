class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int c = 0;
        long long sum = 0;
        long long mn = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                sum += abs(matrix[i][j]);
                mn = min(mn, (long long)abs(matrix[i][j]));
                if (matrix[i][j] <= 0)
                    c++;
            }
        }
        if (c % 2 == 0)
            return sum;
        else
            return sum - 2 * (mn);
    }
};