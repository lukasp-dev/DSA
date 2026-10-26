class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        l_t = 1
        r_t = max(piles)
        
        while l_t < r_t:
            mid = l_t + (r_t - l_t)//2
            if self.canEat(piles, mid, h):
                r_t = mid
            else:
                l_t = mid+1
        
        return l_t



    
    def canEat(self, piles:list[int], speed: int, h: int) -> bool:
        time = 0
        for pile in piles:
            time += pile // speed if pile % speed == 0 else pile // speed + 1
        return time <= h
