/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function(grid) {
    const n = grid.length;
    if(grid[0][0] === 1 || grid[n-1][n-1] === 1){
        return -1;
    }
    
    const dirs = [[1, 0], [0, 1], [-1, 0], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1]];
    let dist = 1;

    const queue = [[0, 0]];
    grid[0][0] = 1;
    
    while(queue.length > 0){
        const size = queue.length;

        for(let i=0; i<size; i++){
            const [x, y] = queue.shift();
            if(x === n-1 && y === n-1){
                return dist;
            } 

            for(const [dx, dy] of dirs){
                const nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < n &&
                ny >= 0 && ny < n &&
                grid[nx][ny] === 0){
                    grid[nx][ny] = 1;
                    queue.push([nx, ny]);
                }
            }
        } 
        dist++;
    }

    return -1;
};