/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void setParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(node == nullptr) return;

        if(node->left) {
            parent[node->left] = node;
            setParent(node->left, parent);
        }

        if(node->right) {
            parent[node->right] = node;
            setParent(node->right, parent);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == nullptr) return {};
        if(k == 0) return {target->val};

        unordered_map<TreeNode*, TreeNode*> parent;

        setParent(root, parent);
        unordered_set<TreeNode*> visited;

        int steps = 0;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        vector<int> kAwayNodes;

        while(!q.empty() && k > steps) {
            int n = q.size();
            steps++;
            
            for(int i=0; i<n; ++i) {
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                    if(k == steps) kAwayNodes.push_back(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                    if(k == steps) kAwayNodes.push_back(curr->right->val);
                }
                if(parent.count(curr) && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                    if(k == steps) kAwayNodes.push_back(parent[curr]->val);
                }
            }
        }
        
        return kAwayNodes;
    }
};