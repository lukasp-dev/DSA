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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;

        if(!root) return levels;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int q_size = q.size();
            vector<int> level;
            for(int i=0; i<q_size; i++){
                TreeNode* curr = q.front(); q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levels.push_back(level);
        }

        reverse(levels.begin(), levels.end());
        return levels;
    }
};