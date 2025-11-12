class Solution {
public:
    int cnt = 0;

    void countPath(TreeNode* node, int targetSum, unordered_map<long long, int>& lookup, long long accSum) {
        if (!node) return;

        accSum += node->val;

        if (lookup.count(accSum - targetSum)) {
            cnt += lookup[accSum - targetSum];
        }

        lookup[accSum]++;

        countPath(node->left, targetSum, lookup, accSum);
        countPath(node->right, targetSum, lookup, accSum);

        lookup[accSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        unordered_map<long long, int> lookup;
        lookup[0] = 1;
        countPath(root, targetSum, lookup, 0LL);
        return cnt;
    }
};
