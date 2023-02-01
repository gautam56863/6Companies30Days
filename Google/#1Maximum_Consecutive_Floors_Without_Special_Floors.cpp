class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {

        sort(special.begin(), special.end());
        int mx = 0;
        mx = max(mx, (special[0] - 1) - (bottom) + 1);
        for (int i = 0; i < special.size() - 1; i++)
        {
            mx = max(mx, (special[i + 1] - 1) - (special[i] + 1) + 1);
        }
        mx = max(mx, top - (special[special.size() - 1] + 1) + 1);
        return mx;
    }
};