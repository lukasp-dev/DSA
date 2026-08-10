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

    pair<int, int> dfs(TreeNode* node) {
        if(node == nullptr) {
            return {-1, -1};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int goLeft = 1 + left.second;
        int goRight = 1 + right.first;

        ret = max({ret, goLeft, goRight});
        
        return {goLeft, goRight};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ret;
    }
};