class Solution:
    def mySqrt(self, x: int) -> int:
        start = 0
        end = x

        sqrt = -1

        while start <= end:
            mid = start + (end - start) // 2
            sqrd = mid * mid
            if sqrd == x:
                return mid
            elif sqrd < x:
                sqrt = max(sqrt, mid)
                start = mid + 1
            else:
                end = mid - 1
            
        
        return sqrt