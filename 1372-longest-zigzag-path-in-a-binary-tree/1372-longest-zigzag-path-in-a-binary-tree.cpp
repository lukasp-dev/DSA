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
int _max = 0;

void go(TreeNode* node, int depth, int dir){
    if(!node) return;

    _max = max(_max, depth);

    if(dir == 0) {
        go(node->right, depth+1, !dir);
        go(node->left, 1, dir);
    }
    if(dir == 1) {
        go(node->left, depth+1, !dir);
        go(node->right, 1, dir);
    } 
}

public:
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        //dir: 0->left, 1->right
        if(root->left) go(root, 0, 0);
        if(root->right) go(root, 0, 1);

        return _max;
    }
};