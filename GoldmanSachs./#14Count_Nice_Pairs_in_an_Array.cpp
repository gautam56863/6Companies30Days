class Solution
{
public:
    int rev(int a)
    {
        int ans = 0;
        while (a > 0)
        {
            ans = ans * 10 + a % 10;
            a = a / 10;
        }
        return ans;
    }
    int countNicePairs(vector<int> &nums)
    {
        int c = 0;
        int mod = (int)(1e9 + 7);
        unordered_map<int, long> m;
        for (auto it : nums)
        {
            m[it - rev(it)]++;
        }
        for (auto it : m)
        {
            long f = it.second;
            c = c + (((f) * (f - 1)) / 2) % mod;
        }
        return c % mod;
    }
};
