/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var minScore = function(n, roads) {
    const graph = Array.from({length: n+1}, () => []);
    for( const [a, b, d] of roads) {
        graph[a].push([b, d]);
        graph[b].push([a, d]);
    }

    let min = Infinity;
    const visited = new Set();
    const queue = [1];
    visited.add(1);

    while(queue.length > 0){
        const curr = queue.shift();
        for(const [neighbor, dist] of graph[curr]){
            min = Math.min(min, dist);
            if(!visited.has(neighbor)){
                queue.push(neighbor);
                visited.add(neighbor);
            }
        }
    }

    return min;
};