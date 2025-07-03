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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(!root) {return levels;}

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            levels.push_back({});
            int level_length = q.size();

            for(int i=0; i<level_length; i++){
                TreeNode* curr = q.front();
                q.pop();
                levels[level].push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        return levels;
    }
};