class Solution
{
public:
    long long f;
    long long fact(int n)
    {
        if (n <= 1)
            return 1;
        return n * fact(n - 1);
    }

    bool isPrime(int n)
    {
        if (n == 4)
            return false;
        long long a = f % n;
        if (a == n - 1)
            return true;
        return false;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> v = {-1, -1};
        int p1 = 0, p2 = 0, dist = INT_MAX;
        f = fact(left);
        if (left != 4 && left != 1 && (f / left) % left == left - 1)
            p1 = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (isPrime(i))
            {
                if (p1 == 0)
                    p1 = i;
                else if (p2 == 0)
                {
                    p2 = i;
                    dist = p2 - p1;
                    v[0] = p1;
                    v[1] = p2;
                }

                else
                {
                    p1 = p2;
                    p2 = i;
                    if (p2 - p1 < dist)
                    {
                        v[0] = p1;
                        v[1] = p2;
                        dist = p2 - p1;
                    }
                }
            }
        }
        return v;
    }
};