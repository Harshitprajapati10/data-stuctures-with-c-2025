

def bubble_sort(nums):
    for i in range(len(nums)):
        for j in range(len(nums)-i-1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1],nums[j]
    print(nums)

#modified bs
def bubble_sort_modified(nums):
    for i in range(len(nums)):  
        isSwapped = False
        for j in range(len(nums)-i-1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1],nums[j]
                isSwapped = True
        if not isSwapped:
            break
    print(nums)


print(bubble_sort([4,3,2,5,8,7,3]))
print(bubble_sort_modified([4,3,2,5,8,7,3]))