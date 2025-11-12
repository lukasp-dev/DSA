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
    int getMax(TreeNode* node, int depth){
        if(!node){
            return depth;
        }

        return max(getMax(node->left, depth+1), getMax(node->right, depth+1));
    }

    int maxDepth(TreeNode* root) {
        return getMax(root, 0);
    }
};