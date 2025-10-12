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
    void checkLeaves(TreeNode* node, vector<int>& vec){
        if(node->left == nullptr && node->right == nullptr){
            vec.push_back(node->val);
            return;
        }
        
        if(node->right == nullptr){
            checkLeaves(node->left, vec);
        }else if(node->left == nullptr){
            checkLeaves(node->right, vec); 
        }else{
            checkLeaves(node->left, vec); checkLeaves(node->right, vec);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> firstLeaves;
        vector<int> secondLeaves;

        checkLeaves(root1, firstLeaves);
        checkLeaves(root2, secondLeaves);

        return firstLeaves == secondLeaves;
    }
};