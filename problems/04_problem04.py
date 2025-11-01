# sorted array of non -negative numbers. WAF to find smallest el not  present in the array

# two pointer
nums = [0, 1, 2, 6, 9, 11, 15]
A = [1, 2, 3, 4, 5]
B = [0, 1, 2, 3, 4, 5, 6, 7]
C = [0, 1,2, 4, 6, 13]

def smallestElnotPresent(nums):
    if not nums:
        return 0
    if nums[0] != 0:
        return 0
    if nums[1] != 1: return 1
    f,s = 1,2
    while(s<len(nums)): # s:0->6
        if nums[s] == nums[f]+1:
            f+=1
            s+=1
        else:
            return (f+1)
    # s is ar end
    return s


# time -> O(N)

print(smallestElnotPresent(nums)) #3
print(smallestElnotPresent(A))
print(smallestElnotPresent(B)) # 8 
print(smallestElnotPresent(C)) # 3