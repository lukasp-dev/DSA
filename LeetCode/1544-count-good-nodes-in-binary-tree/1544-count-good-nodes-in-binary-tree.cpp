class Solution {
public:
    int cntGoodNodes(TreeNode* root, int maxSoFar){
        if (root == nullptr) {
            return 0;
        }

        int append;

        if (root->val >= maxSoFar) {
            append = 1;
            maxSoFar = root->val;
        }else{
            append = 0;
        }
        
        return cntGoodNodes(root->left, maxSoFar) + cntGoodNodes(root->right, maxSoFar) + append;
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return cntGoodNodes(root, root->val);
    }
};
