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
var rightSideView = function(root) {
    if(!root) return [];
    const ret = [];

    const queue = [];
    queue.push(root);

    while(queue.length > 0){
        const n = queue.length;

        for(let i=0; i<n; i++){
            const curr = queue.shift();
            if(i == n-1){
                ret.push(curr.val);
            }
            if(curr.left) queue.push(curr.left);
            if(curr.right) queue.push(curr.right);
        }
    }

    return ret;
};