class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        l = 0
        r = len(nums)-1
        ret = []
        left = -1
        right = -1

        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                left = mid
                r = mid - 1
        ret.append(left)

        l = 0
        r = len(nums)-1
        
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                right = mid
                l = mid + 1

        ret.append(right)

        return ret
        
        
        