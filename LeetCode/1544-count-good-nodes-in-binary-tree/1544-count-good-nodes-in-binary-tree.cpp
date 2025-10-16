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
    int countGoodNodes(TreeNode* root, int maxSoFar){
        if(!root){
            return 0;
        }
        int cnt = 0;

        int curr = root->val;
        int left = 0, right = 0;

        if(curr >= maxSoFar){
            left = countGoodNodes(root->left, curr);
            right = countGoodNodes(root->right, curr);
            cnt++;
        }else{
            left = countGoodNodes(root->left, maxSoFar);
            right = countGoodNodes(root->right, maxSoFar);
        }
        return left + right + cnt;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, 1);
    }
};