class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for(auto& preq : prerequisites) {
            int a = preq[0];
            int b = preq[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        for(int i=0; i<indegree.size(); ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while(!q.empty()) {
            int u = q.front(); q.pop();

            order.push_back(u);

            for(int v : graph[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

    // 삼항 연산자에서는 항상 타입 명시를 해줘야 한다.
    return order.size() == numCourses ? order : vector<int>{}; 
    }
};