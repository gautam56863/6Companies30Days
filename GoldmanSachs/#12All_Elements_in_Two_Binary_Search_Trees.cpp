class Solution
{
public:
    vector<int> v;
    void pre(TreeNode *root)
    {
        if (!root)
            return;
        v.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        pre(root1);
        pre(root2);
        sort(v.begin(), v.end());
        return v;
    }
};