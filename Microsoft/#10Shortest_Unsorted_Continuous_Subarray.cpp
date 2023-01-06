class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int c = 0;
        int i = 0;
        int n = nums.size();
        while (i < n && nums[i] == a[i])
        {
            i++;
            c++;
        }
        if (i == n)
            return n - c;
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] == a[j])
        {
            j--;
            c++;
        }
        return n - c;
        // stack<int>stk;
        // int i=0;
        // while(i<nums.size())
        // {
        //     if(nums[i]<=nums[i+1])
        //     stk.push(nums[i]);
        //     else
        //     break;
        // }
    }
};