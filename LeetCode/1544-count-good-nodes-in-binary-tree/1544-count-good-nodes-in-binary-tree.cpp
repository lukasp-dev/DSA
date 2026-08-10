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
    int countGoodNodes(TreeNode* node, int maxSoFar){
        if(node == nullptr) return 0;

        int leftCount = countGoodNodes(node->left, max(maxSoFar, node->val));
        int rightCount = countGoodNodes(node->right, max(maxSoFar, node->val));

        if(node->val >= maxSoFar) return 1 + leftCount + rightCount;
        else return leftCount + rightCount;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, -1e9);
    }
};