class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(i + 1);
        int start = 0;
        k--;
        while (v.size() > 1)
        {
            start = (start + k) % v.size();
            cout << start << " " << endl;
            v.erase(v.begin() + start);
        }
        return v[0];
    }
};