class Solution:
    def search(self, nums: list[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            mid_idx = l + (r - l) // 2
            mid_val = nums[mid_idx]

            if mid_val == target:
                return mid_idx

            # Left half is sorted
            if nums[l] <= mid_val:
                if nums[l] <= target < mid_val:
                    r = mid_idx - 1
                else:
                    l = mid_idx + 1

            # Right half is sorted
            else:
                if mid_val < target <= nums[r]:
                    l = mid_idx + 1
                else:
                    r = mid_idx - 1

        return -1