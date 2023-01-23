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
    int pre(TreeNode *root, int status, map<pair<TreeNode *, int>, int> &m)
    {
        if (!root)
            return 0;
        int pick = 0;
        int notpick = 0;
        if (m.find({root, status}) != m.end())
            return m[{root, status}];

        notpick = pre(root->left, 1, m) + pre(root->right, 1, m);

        if (status)
            pick = root->val + pre(root->left, 0, m) + pre(root->right, 0, m);
        m[{root, status}] = max(pick, notpick);
        return max(pick, notpick);
    }
    int rob(TreeNode *root)
    {
        map<pair<TreeNode *, int>, int> m;
        return pre(root, -1, m);
    }
};