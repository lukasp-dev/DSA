/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    const ret = [];

    const inorder = (node) => {
        if(!node) return;
        
        inorder(node.left);
        ret.push(node.val);
        inorder(node.right);
    }

    inorder(root);
    return ret;
};