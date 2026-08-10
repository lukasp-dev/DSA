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
    void getLeaves(vector<int>& vec, TreeNode* node) {
        if(node == nullptr) return;

        if(node->left == nullptr && node->right == nullptr) {
            vec.push_back(node->val);
            return;
        }

        getLeaves(vec, node->left);
        getLeaves(vec, node->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        getLeaves(v1, root1);
        getLeaves(v2, root2);
        return v1 == v2;
    }
};