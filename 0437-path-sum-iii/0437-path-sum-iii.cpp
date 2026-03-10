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
typedef long long ll;

class Solution {
public:
    int cnt = 0;
    
    void dfs(TreeNode* node, int targetSum, unordered_map<ll, int>& um, ll accSum){
        if(!node) return;
        accSum += node->val;
        ll complement = accSum - targetSum;
        if(um.count(complement)){
            cnt += um[complement];
        }

        um[accSum]++;
        dfs(node->left, targetSum, um, accSum);
        dfs(node->right, targetSum, um, accSum);
        um[accSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        unordered_map<ll, int> mp;
        mp[0] = 1;

        dfs(root, targetSum, mp, 0);

        return cnt;
    }
};