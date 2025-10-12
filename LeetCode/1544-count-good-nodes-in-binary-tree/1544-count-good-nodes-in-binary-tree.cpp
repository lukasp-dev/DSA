class Solution {
public:
    int cntGoodNodes(TreeNode* root, int maxSoFar){
        if (root == nullptr) {
            return 0;
        }

        int append = 0;
        if(maxSoFar <= root->val){
            maxSoFar = root->val;
            append = 1;
        }

        return cntGoodNodes(root->left, maxSoFar) + cntGoodNodes(root->right, maxSoFar) + append;
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return cntGoodNodes(root, root->val);
    }
};
