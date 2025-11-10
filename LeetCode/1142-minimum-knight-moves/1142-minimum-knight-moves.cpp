class Solution {
public:
    const vector<int> dy = {-2, -1, 1, 2, 2, 1, -1, -2};
    const vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};

    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});

        set<pair<int,int>> visited;
        visited.insert({0,0});

        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int currX = curr.first.first;
            int currY = curr.first.second;
            int steps = curr.second;

            if(currX == x && currY == y) return steps;

            for(int i=0; i<8; i++){
                int nx = currX + dx[i];
                int ny = currY + dy[i];
                if(nx >= -2 && ny >= -2 && !visited.count({nx, ny})){
                    visited.insert({nx,ny});
                    q.push({{nx, ny}, steps+1});
                }
            }
        }
        return -1;
    }
};