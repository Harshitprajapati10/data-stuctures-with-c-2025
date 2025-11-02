# maximum sliding window

class Solution:
    def getMax(self,nums):
        max_val = nums[0]
        for num in nums:
            if max_val < num:
                max_val = num
        return max_val

    def maxSlidingWindow(self, nums, k: int):
        s,e = 0, k-1
        n = len(nums)
        ans = []
        while(e<len(nums)): # e:2->7
            ans.append(self.getMax(nums[s:e+1]))
            s+=1
            e+=1
        return ans

nums = [1,3,-1,-3,5,3,6,7]
k = 3
obj = Solution()
ans = obj.maxSlidingWindow(nums,k)
print(ans)


# solution using deque
