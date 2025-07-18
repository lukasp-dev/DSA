/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]];
    const m = grid.length, n = grid[0].length;
    let count = 0;

    const dfs = (x, y) => {
        if(x < 0 ||  x >= m || y < 0 || y >= n || grid[x][y] === "0") return;
        grid[x][y] = "0";

        for(const [dx, dy] of dirs){
            const nx = x + dx, ny = y + dy;
            
            dfs(nx, ny);
        }
    }

    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(grid[i][j] === '1'){
                count++;
                dfs(i, j);
            }
        }
    }

    return count;
};