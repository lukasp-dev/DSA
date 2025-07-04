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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(!root) return levels;

        bool fromRight = false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int curr_size = q.size();
            vector<int> level_vec;

            for(int i=0; i<curr_size; i++){
                TreeNode* curr = q.front();
                q.pop();

                level_vec.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(fromRight) reverse(level_vec.begin(), level_vec.end());
            levels.push_back(level_vec);
            fromRight = !fromRight;
        }

        return levels;
    }
};