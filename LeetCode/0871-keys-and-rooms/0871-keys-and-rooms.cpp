class Solution {
public:
    void visitRooms(vector<vector<int>>& rooms, vector<int>& visited, int roomNo){
        visited[roomNo] = 1;

        vector<int> canVisit = rooms[roomNo];

        for(int nextRoom : canVisit){
            if(!visited[nextRoom]){
                visitRooms(rooms, visited, nextRoom);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);

        visitRooms(rooms, visited, 0);
        
        for(int room : visited){
            if(!room) return false;
        }

        return true;
    }
};