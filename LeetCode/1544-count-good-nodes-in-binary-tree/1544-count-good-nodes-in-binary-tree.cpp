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
class Solution {
public:
    int ret = 0;

    void dfs(TreeNode* root, int maxSoFar){
        if(!root) return;
        if(maxSoFar <= root->val){
            ret++; maxSoFar = root->val;
        }
        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root, root->val);
        return ret;
    }
};