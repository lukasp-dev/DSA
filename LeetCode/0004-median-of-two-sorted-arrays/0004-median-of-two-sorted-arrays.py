class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        # Binary search on smaller array (nums2)
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        half = (m + n + 1) // 2

        l = -1
        r = n - 1

        while l <= r:
            mid = l + (r - l) // 2

            # nums2 partition
            left2 = nums2[mid] if mid >= 0 else float('-inf')
            right2 = nums2[mid + 1] if mid + 1 < n else float('inf')

            # nums1 partition
            i = half - mid - 2

            left1 = nums1[i] if i >= 0 else float('-inf')
            right1 = nums1[i + 1] if i + 1 < m else float('inf')

            if left1 > right2:
                l = mid + 1

            elif left2 > right1:
                r = mid - 1

            else:
                # Correct partition
                if (m + n) % 2 == 1:
                    return max(left1, left2)

                return (max(left1, left2) + min(right1, right2)) / 2