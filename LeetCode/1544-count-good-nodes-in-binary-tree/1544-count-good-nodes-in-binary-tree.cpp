class Solution {
public:
    void cntGoodNodes(TreeNode* root, int maxSoFar, int& count){
        if (root == nullptr) {
            return;
        }

        if(maxSoFar <= root->val){
            maxSoFar = root->val;
            count++;
        }

        cntGoodNodes(root->left, maxSoFar, count);
        cntGoodNodes(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 0;
        cntGoodNodes(root, root->val, count);
        return count;
    }
};
