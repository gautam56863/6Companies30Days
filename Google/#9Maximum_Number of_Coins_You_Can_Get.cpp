class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int i = 0;
        int j = piles.size() - 1;
        int sum = 0;
        while (i < j)
        {
            sum += piles[j - 1];
            j = j - 2;
            i = i + 1;
        }
        return sum;
    }
};