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
    int res = 0;

    void countGoodNodes(TreeNode* node, int maxVal){
        if(!node){
            return;
        }
        countGoodNodes(node->left, max(node->val, maxVal));
        countGoodNodes(node->right, max(node->val, maxVal));
        if(node->val >= maxVal) res++;
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        countGoodNodes(root, root->val);
        return res;
    }
};