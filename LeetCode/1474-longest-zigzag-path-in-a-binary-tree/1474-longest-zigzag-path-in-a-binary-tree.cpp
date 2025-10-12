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
    // left: 0, right: 1
    void explore(TreeNode* node, int depth, int nextDir, int& maxLength){
        if(node == nullptr) return;

        maxLength = max(maxLength, depth);

        // go left
        if(node->left){
            if(nextDir == 0)  // continuing left after right
                explore(node->left, depth + 1, 1, maxLength);
            else              // same dir as before → reset
                explore(node->left, 1, 1, maxLength);
        }

        // go right
        if(node->right){
            if(nextDir == 1)  // continuing right after left
                explore(node->right, depth + 1, 0, maxLength);
            else              // same dir as before → reset
                explore(node->right, 1, 0, maxLength);
        }
    }

    int longestZigZag(TreeNode* root) {
        int maxLength = 0;
        explore(root, 0, 0, maxLength);  // direction doesn't matter at root
        return maxLength;
    }
};
