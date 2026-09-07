class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        prefixmax=max(nums[0],nums[1])
        prefixmin=min(nums[0],nums[1])
        for i in range(2,len(nums)):
            prefixmax=max(prefixmax,nums[i])
            prefixmin=min(prefixmin,nums[i])
            if prefixmax-prefixmin<=k:
                return i
        return -1