/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* tmp = root;

        while(tmp){
            int pVal = p->val, qVal = q->val, currVal = tmp->val;

            if(currVal < pVal && currVal < qVal){
                tmp = tmp->right;
            }else if(currVal > pVal && currVal > qVal){
                tmp = tmp->left;
            }else{
                return tmp;
            }
        }

        return nullptr;
    }
};