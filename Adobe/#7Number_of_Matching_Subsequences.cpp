class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        unordered_map<char, vector<int>> m;
        int i = 0;
        for (auto it : s)
        {
            m[it].push_back(i++);
        }
        for (int i = 0; i < words.size(); i++)
        {
            int latest = -1;
            for (int j = 0; j < words[i].size(); j++)
            {
                auto it = upper_bound(m[words[i][j]].begin(), m[words[i][j]].end(), latest);
                if (it == (m[words[i][j]].end()))
                    break;
                latest = *it;
                if (j == words[i].size() - 1)
                    ans++;
            }
        }
        return ans;
    }
};