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
    vector<int> result;
    void postOrder(TreeNode* node){
        if(!node) return;
        if(node->left) postOrder(node->left);
        if(node->right) postOrder(node->right);
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return result;
    }
};