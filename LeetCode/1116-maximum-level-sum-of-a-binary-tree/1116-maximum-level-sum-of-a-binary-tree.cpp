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
        if(!root) return 0;

        int maxLevel = 0;
        int maxSum = -1e9;
        int currLevel = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            currLevel++;
            int n = q.size();
            int levelSum = 0;

            for(int i=0; i<n; i++){
                TreeNode* curr = q.front(); q.pop();
                levelSum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(levelSum > maxSum){
                maxSum = levelSum;
                maxLevel = currLevel;
            }
        }

        return maxLevel;
    }
};