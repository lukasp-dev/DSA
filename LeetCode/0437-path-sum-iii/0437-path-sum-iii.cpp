class Solution {
public:
    void dfs(TreeNode* root, int targetSum, unordered_map<long long, int>& prefixLookup, int& count, long long prefixSum){
        if(root == nullptr) return;

        prefixSum += root->val;
        long long complement = prefixSum - targetSum;

        if (prefixLookup.count(complement)) {
            count += prefixLookup[complement];
        }

        prefixLookup[prefixSum]++;

        dfs(root->left, targetSum, prefixLookup, count, prefixSum);
        dfs(root->right, targetSum, prefixLookup, count, prefixSum);

        prefixLookup[prefixSum]--;
        if (prefixLookup[prefixSum] == 0)
            prefixLookup.erase(prefixSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        
        int count = 0;
        unordered_map<long long, int> prefixLookup;
        prefixLookup[0] = 1;

        dfs(root, targetSum, prefixLookup, count, 0LL);

        return count;
    }
};
