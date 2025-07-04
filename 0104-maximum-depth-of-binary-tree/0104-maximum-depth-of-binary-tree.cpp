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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int levels = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                TreeNode* now = q.front(); q.pop();

                if(now->left) q.push(now->left); 
                if(now->right) q.push(now->right);
            }
            levels++;
        }

        return levels;
    }
};