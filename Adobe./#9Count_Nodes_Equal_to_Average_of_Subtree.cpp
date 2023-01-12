/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int c = 0;
    pair<int, int> h(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        auto left = h(root->left);
        auto right = h(root->right);
        int l_sum = left.first;
        int r_sum = right.first;
        int l_cnt = left.second;
        int r_cnt = right.second;

        int sum = l_sum + r_sum + root->val;
        int cnt = l_cnt + r_cnt + 1;
        if (root->val == (sum / cnt))
            c++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode *root)
    {
        h(root);
        return c;
    }
};