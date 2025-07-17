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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(!root) return [];

    const ret = [];
    const queue = [root];

    while(queue.length > 0){
        const n = queue.length;
        let sub = [];
        for(let i=0; i<n; i++){
            const curr = queue.shift();
            sub.push(curr.val);
            if(curr.left) queue.push(curr.left);
            if(curr.right) queue.push(curr.right);
        }
        ret.push(sub);
    }

    return ret;
};