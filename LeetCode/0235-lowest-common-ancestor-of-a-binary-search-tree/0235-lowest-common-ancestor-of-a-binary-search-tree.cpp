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
        int pVal = p->val, qVal = q->val;

        while(tmp){
            int curr = tmp->val;

            if(curr < pVal && curr < qVal){
                tmp = tmp -> right;
            }else if(curr > pVal && curr > qVal){
                tmp = tmp -> left;
            }else{
                return tmp;
            }
        }

        return nullptr;
    }
};