#define ll long long
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {

        int mod = 1e9 + 7;
        vector<pair<ll, ll>> adj[n + 1];

        for (auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<ll> dist(n + 1, 1e18);
        dist[0] = 0;
        vector<ll> ways(n + 1, 0);
        ways[0] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();

            ll src = x.second;
            ll dis = x.first;

            for (auto it : adj[src])
            {
                ll nextnode = it.first;
                ll nextdis = it.second;

                if (dist[nextnode] > dis + nextdis)
                {
                    dist[nextnode] = dis + nextdis;
                    pq.push({dist[nextnode], nextnode});

                    ways[nextnode] = ways[src];
                }
                else if (dist[nextnode] == dis + nextdis)
                {
                    ways[nextnode] = (ways[src] + ways[nextnode]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
