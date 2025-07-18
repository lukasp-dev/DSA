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
 * @return {boolean}
 */
var isValidBST = function(root) {
    let prev = -Infinity;

    const validate = (num) => {
        if(prev > num) return false;
        else{
            prev = num;
            return true;
        }
    }

    const inorder = (node) => {
        if (!node) return true;

        if (!inorder(node.left)) return false;

        if (node.val <= prev) return false;
        prev = node.val;

        if (!inorder(node.right)) return false;

        return true;
    };

    return inorder(root);
};