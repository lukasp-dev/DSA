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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int maxLevelSum = -1e9;
        int maxLevel = 1;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int sum = 0;

            for(int i=0; i<n; i++){
                TreeNode* curr = q.front(); q.pop();
                sum+=curr->val;
                
                if(curr->left)q.push(curr->left); 
                if(curr->right)q.push(curr->right);
            }

            if(sum > maxLevelSum){
                maxLevelSum = sum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }
};