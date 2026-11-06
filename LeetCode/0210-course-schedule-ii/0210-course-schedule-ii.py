class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        dep_graph:dict[int, list[int]] = {i:[] for i in range(numCourses)}
        in_degree:dict[int, int] = {i:0 for i in range(numCourses)}

        for a_i, b_i in prerequisites:
            dep_graph[b_i].append(a_i)
            in_degree[a_i] += 1
        
        dq = deque(
            c for c in in_degree.keys()
            if in_degree[c] == 0
        )

        order = []

        while dq:
            curr = dq.popleft()
            order.append(curr)
            
            for course in dep_graph[curr]:
                in_degree[course] -= 1
                if in_degree[course] == 0:
                    dq.append(course)

        if numCourses == len(order):
            return order
        else:
            return []