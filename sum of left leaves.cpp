class Solution
{
public:
    int helper(TreeNode *root, int state)
    {
        if (root == NULL)
            return 0;
        if (!root->left && !root->right && state == 1)
            return root->val;
        return helper(root->left, 1) + helper(root->right, 2);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        return helper(root, 0);
    }
};

// BFS-
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                if (cur->left != NULL)
                {
                    q.push(cur->left);
                    if (!cur->left->left && !cur->left->right)
                        ans += cur->left->val;
                }
                if (cur->right != NULL)
                    q.push(cur->right);
                q.pop();
            }
        }
        return ans;
    }
};