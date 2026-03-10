class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int roomNum, vector<int>& visited){
        visited[roomNum] = 1;
        
        for(int togo : rooms[roomNum]){
            if(!visited[togo]){
                dfs(rooms, togo, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        // visited[0] = 1;

        dfs(rooms, 0, visited);

        for(int hasVisit : visited){
            if(!hasVisit) return false;
        }

        return true;
    }
};