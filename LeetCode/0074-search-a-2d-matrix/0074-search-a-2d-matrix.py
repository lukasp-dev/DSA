class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        
        return self.search(matrix, 0, n*m-1, target)

    def search(self, matrix, l, r, target) -> bool:
        if l > r:
            return False
        
        m = len(matrix[0])
        mid = (l+r)//2
        val = matrix[mid//m][mid%m]
        
        if val > target:
            return self.search(matrix, l, mid-1, target)
        elif val < target:
            return self.search(matrix, mid+1, r, target)
        else:
            return True