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
    int getNumbers(TreeNode* node, long long targetSum, long long prefixSum, unordered_map<long long, int>& prefixes) {
        if(node == nullptr) return 0;

        prefixSum += node->val;

        int ret = 0;

        if(prefixes.count(prefixSum - targetSum)) {
            ret += prefixes[prefixSum - targetSum];
        }

        prefixes[prefixSum]++;

        ret += getNumbers(node->left, targetSum, prefixSum, prefixes);
        ret +=  getNumbers(node->right, targetSum, prefixSum, prefixes);

        prefixes[prefixSum]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixes;

        prefixes[0] = 1;

        return getNumbers(root, targetSum, 0, prefixes);
    }
};