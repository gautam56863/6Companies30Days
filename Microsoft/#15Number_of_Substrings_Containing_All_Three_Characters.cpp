class Solution
{
public:
    int numberOfSubstrings(string s)
    {

        int n = s.size();
        int c = 0;

        int i = 0;
        int j = 0;
        vector<int> v(3, 0);
        while (j < n)
        {
            v[s[j] - 'a']++;
            if (v[0] > 0 && v[1] > 0 && v[2] > 0)
            {
                while (i <= j - 2 && v[0] > 0 && v[1] > 0 && v[2] > 0)
                {

                    c += n - j;
                    v[s[i] - 'a']--;
                    i++;
                }
            }
            j++;
        }

        return c;
    }
};