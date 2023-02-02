class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int i = n - 1, j = n - 1;
        int mx = INT_MIN;
        unordered_map<int, int> m;
        while (j >= 0)
        {
            if (m.size() < 3)
                m[fruits[j]]++;

            if (m.size() > 2)
            {
                mx = max(mx, i - j);
                while (m.size() > 2)
                {
                    m[fruits[i]]--;
                    if (m[fruits[i]] == 0)
                        m.erase(fruits[i]);
                    i--;
                }
            }
            j--;
        }
        mx = max(mx, i - j);
        return mx;
    }
};