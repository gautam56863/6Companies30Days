class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> par, dis;
    // Find the parent and distance from node 0
    void dfs(int u, int p = 0, int d = 0)
    {
        dis[u] = d;
        par[u] = p;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u, d + 1);
        }
    }
    // Find total sum to each node
    int dfs2(int u, vector<int> &amount, int p = 0)
    {
        int ret = amount[u];
        int mxc = -INT_MAX;
        for (int v : adj[u])
        {
            if (v != p)
            {
                mxc = max(mxc, dfs2(v, amount, u));
            }
        }
        // if the node is leaf we just return its amount
        if (mxc == -INT_MAX)
            return ret;
        else
            return ret + mxc;
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        adj.resize(n, vector<int>());
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs(0);
        int cur = bob;
        int bob_dis = 0;
        // update the path of from Bob to 0
        while (cur != 0)
        {
            if (dis[cur] > bob_dis)
            {
                amount[cur] = 0;
            }
            else if (dis[cur] == bob_dis)
            {
                amount[cur] /= 2;
            }
            cur = par[cur];
            bob_dis++;
        }
        return dfs2(0, amount);
    }
};
// class Solution {
// public:

//     void dfs(int idx,int bob,vector<vector<int>>&adj,vector<int>&vis,vector<vector<int>>&paths,vector<int>&d,vector<int>&diff)
//     {
//         vis[idx]=1;
//         d.push_back(idx);
//         if(idx==bob)
//         {
//             diff=d;
//         }
//         if(adj[idx].size()==1 && idx!=0)
//         {
//             paths.push_back(d);
//             return;
//         }

//         for(auto it:adj[idx])
//         {
//             if(!vis[it])
//             {
//                 dfs(it,bob,adj,vis,paths,d,diff);
//                 d.pop_back();
//                 vis[it]=0;
//             }
//         }

//     }
//     int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
//         vector<vector<int>>paths;
//         vector<int>d;
//         vector<vector<int>>adj(edges.size()+1);
//         vector<int>vis(edges.size()+1,0);
//         vector<int>diff;
//         for(auto it:edges)
//         {
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }

//         dfs(0,bob,adj,vis,paths,d,diff);
//         reverse(diff.begin(),diff.end());

//         int mx=INT_MIN;
//         for(auto it:paths)
//         {
//             vector<int>vi(edges.size()+1,0);
//             int pf=0;
//             int i=0;int j=0;
//             while(i<it.size() && j<diff.size())
//             {
//                 if(it[i]==diff[j])
//                 {
//                     pf+=amount[it[i]]/2;
//                 }
//                 else if(vi[it[i]]==0)
//                 pf+=amount[it[i]];
//                 vi[it[i]]=1;
//                 vi[diff[j]]=1;
//                 i++;
//                 j++;
//             }
//             while(i<it.size())
//             {
//                 if(vi[it[i]]==0)
//                 pf+=amount[it[i]];
//                 i++;
//             }
//             mx=max(mx,pf);
//         }
//         return mx;

//     }
// };