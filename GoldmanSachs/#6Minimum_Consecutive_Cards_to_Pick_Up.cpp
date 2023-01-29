class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {

        int i = 0;
        int j = 0;
        int n = cards.size();
        unordered_map<int, int> m;
        int ans = (int)(1e9 + 7);
        while (j < n)
        {
            m[cards[j]]++;
            if (m[cards[j]] > 1)
            {
                while (m[cards[j]] > 1)
                {
                    m[cards[i]]--;
                    i++;
                }
                ans = min(ans, j - i + 2);
            }
            j++;
        }
        if (ans == 1000000007)
            return -1;
        else
            return ans;
    }
};
