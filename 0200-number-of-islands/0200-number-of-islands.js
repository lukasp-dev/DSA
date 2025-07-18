/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    let count = 0;

    const bfs = (i, j) => {
        const queue = [[i, j]];
        grid[i][j] = '0';

        while(queue.length > 0){
            const [x, y] = queue.shift();

            for(const [dx, dy] of [[0, 1], [1, 0], [0, -1], [-1, 0]]){
                const nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                grid[nx][ny] === '1'){
                    grid[nx][ny] = '0';
                    queue.push([nx, ny]);
                }
            }
        }
    };

    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(grid[i][j] === '1'){
                count++;
                bfs(i, j);
            }
        }
    }

    return count;
};