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
var averageOfLevels = function(root) {
    const ret = [];

    const queue = [];
    queue.push(root);

    while(queue.length > 0){
        const n = queue.length;
        let sum = 0;

        for(let i=0; i<n; i++){
            const curr = queue.shift();
            sum += curr.val;
            if(curr.left) queue.push(curr.left);
            if(curr.right) queue.push(curr.right);
        }
        ret.push(sum/n);
    }

    return ret;
};