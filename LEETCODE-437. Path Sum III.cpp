class Solution {
public:
    unordered_map<int , int>m;
    int targetSum;
    int solve(TreeNode* root, int cur_sum){
        if(root==NULL)
            return 0;
        cur_sum+=root->val;
        int count=m[cur_sum-targetSum];
        m[cur_sum]++;
        count+=solve(root->left, cur_sum);
        count+=solve(root->right, cur_sum);
        m[cur_sum]--;
        return count;
    }
    int pathSum(TreeNode* root, int sum) {
        m[0]++;
        targetSum=sum;
        return solve(root, 0);
    }
};