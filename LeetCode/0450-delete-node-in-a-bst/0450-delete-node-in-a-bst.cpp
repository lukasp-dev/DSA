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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        while(curr && curr->val != key){
            parent = curr;
            if(curr->val < key){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }

        if(!curr) return root;

        // two children
        if(curr->left && curr->right){
            TreeNode* succParent = curr;
            TreeNode* succ = curr->right;
            while(succ->left){
                succParent = succ;
                succ = succ->left;
            }
            curr->val = succ->val;
            curr = succ;
            parent = succParent;
        }
        
        TreeNode* child = (curr->left) ? curr->left : curr->right;

        // root deletion
        if(!parent){
            delete curr;
            return child;
        }

        //parent adjustment
        if(parent->left == curr) parent->left = child;
        else parent->right = child;
        
        delete curr;
        return root;
    }
};