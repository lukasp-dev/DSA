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
    void getLeaf(TreeNode* node, vector<int>& vec){
        if (!node) return;
        if(!node->left && !node->right){
            vec.push_back(node->val);
            return;
        }

        getLeaf(node->left, vec);
        getLeaf(node->right, vec);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;

        getLeaf(root1, vec1);
        getLeaf(root2, vec2);

        return vec1 == vec2;
    }
};