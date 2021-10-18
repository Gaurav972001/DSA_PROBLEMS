class Solution {
public:
    int i=-1;
    void depth(TreeNode* root, int val, int d){
        if(root==NULL)
            return;
        if(root->val==val){
            i=d;
            return;
        }
        depth(root->left, val, d+1);
        depth(root->right, val, d+1);
    }
    int findDepth(TreeNode* root, int x, int y) {
        depth(root,5, 0);
        return i;
    }
};