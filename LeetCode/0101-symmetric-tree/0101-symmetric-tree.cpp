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
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) return true;

        if (!root1 || !root2) return false;

        if (root1->val != root2->val) return false;

        bool isSameLeft = isSameTree(root1->left, root2->left);
        bool isSameRight = isSameTree(root1->right, root2->right);
        
        return isSameLeft && isSameRight;
    }

    void flipTree(TreeNode* root){
        if(root == nullptr){
            return;
        }

        flipTree(root->left);
        flipTree(root->right);

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    bool isSymmetric(TreeNode* root) {
        flipTree(root->right);

        return isSameTree(root->left, root->right);
    }
};