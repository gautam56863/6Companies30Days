class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int mx = INT_MIN;
        int sum = 0;
        int a = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            a += nums[i];
            sum += i * nums[i];
        }
        mx = sum;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            sum = sum + a - nums.size() * (nums[i]);
            mx = max(mx, sum);
        }
        return mx;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int  a=0,b=i+1;
        //     for(int j=1;j<nums.size();j++)
        //     {
        //         a+=(j*nums[b++]);
        //         b=b%nums.size();
        //     }
        //     mx=max(mx,a);
        // }
        // return mx;
    }
};
