class Solution
{
public:
    // class Solution {
    // public:
    // 	bool canPartitionKSubsets(vector<int>& nums, int k) {
    // 		int sum = 0;
    // 		sum = accumulate(nums.begin(), nums.end(), sum);
    // 		if (nums.size() < k || sum % k) return false;

    // 		vector<int>visited(nums.size(), false);
    // 		return backtrack(nums, visited, sum / k, 0, 0, k);
    // 	}

    // 	bool backtrack(vector<int>& nums,vector<int>&visited, int target, int curr_sum, int i, int k) {
    // 		if (k == 1) return true;

    // 		if (curr_sum == target) return backtrack(nums, visited, target, 0, 0, k-1);

    // 		for (int j = i; j < nums.size(); j++) {
    // 			if (visited[j] || curr_sum + nums[j] > target) continue;

    // 			visited[j] = true;
    // 			if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
    // 			visited[j] = false;
    // 		}

    // 		return false;
    // 	}
    // };
    bool solve(vector<int> nums, vector<bool> &visited, int currsum, int idx, int subsetsum, int k)
    {
        if (k == 1)
            return true;
        if (currsum > subsetsum)
            return false;
        if (currsum == subsetsum)
        {
            return solve(nums, visited, 0, 0, subsetsum, k - 1);
        }
        for (int i = idx; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            if (solve(nums, visited, currsum + nums[i], i + 1, subsetsum, k))
                return true;
            visited[i] = false;
            // optimization
            if (currsum == 0)
                break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
            return false;
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (nums.size() < k || sum % k)
            return false;
        int subsetsum = sum / k;
        vector<bool> v(n, false);
        // sort array in decreasing order
        sort(nums.begin(), nums.end(), greater<int>());
        return solve(nums, v, 0, 0, subsetsum, k);
    }
};