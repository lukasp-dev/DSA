from collections import deque

class Solution:
    def canFinish(
        self,
        numCourses: int,
        prerequisites: list[list[int]]
    ) -> bool:

        in_degree = {i: 0 for i in range(numCourses)}
        dependencies: dict[int, set[int]] = {}

        # Build graph
        for a_i, b_i in prerequisites:
            if b_i not in dependencies:
                dependencies[b_i] = set()

            if a_i not in dependencies[b_i]:
                dependencies[b_i].add(a_i)
                in_degree[a_i] += 1

        # Initialize queue
        dq = deque(
            course
            for course, prereq_num in in_degree.items()
            if prereq_num == 0
        )

        result = []

        # Kahn's Algorithm
        while dq:
            current = dq.popleft()
            result.append(current)

            for child in dependencies.get(current, set()):
                in_degree[child] -= 1

                if in_degree[child] == 0:
                    dq.append(child)

        return len(result) == numCourses