#define p pair<int,int>
class Solution {
public:
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map<int,int>m;
        priority_queue<p,vector<p>,greater<p>>pq;
        int res=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++)
        {
            res=gcd(res,numsDivide[i]);
            if(res==1)
            break;
        }
        for(auto it:nums)
        {
            m[it]++;
        }
        for(auto it:m)
        {
            pq.push({it.first,it.second});
        }
        int c=0;
        while(!pq.empty())
        {
            p l=pq.top();
            pq.pop();
            int f=0;
            if(res%l.first==0)
            return c;
        c+=l.second;
        }
        if(c==nums.size())
        return -1;
        return c;
        
    }
};
