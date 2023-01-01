class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<int, int> m;
        unordered_map<int, int> m2;
        int c = 0, d = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                c++;
            }
            else
            {
                m[secret[i] - '0']++;
                m2[guess[i] - '0']++;
            }
        }
        for (auto it : m)
        {
            if (m2.find(it.first) != m2.end())
            {
                d = d + min(m2[it.first], it.second);
            }
        }

        string a = to_string(c) + 'A' + to_string(d) + 'B';
        return a;
    }
};