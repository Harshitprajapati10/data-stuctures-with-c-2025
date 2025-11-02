# normal quick sort

nums = [1,11,3,25,17,9,14,10]

def quick_sort_helper(nums,start,end):
    if start >= end - 1:
        return
    p2 = start-1
    p1 = start
    pivot = nums[end-1]
    while p1<end-1:
        if nums[p1] >= pivot:
            p1+=1
        else:
            # swap p1,p2+1
            nums[p1],nums[p2+1] = nums[p2+1],nums[p1]
            p1+=1
            p2+=1
    nums[p2 + 1], nums[end - 1] = nums[end - 1], nums[p2 + 1]
    quick_sort_helper(nums, start, p2 + 1)
    quick_sort_helper(nums, p2 + 2, end)

    print(nums) 

def quick_sort(nums):
    quick_sort_helper(nums,0,len(nums))
quick_sort(nums)

"""
# normal quick sort

nums = [1,11,3,25,17,9,14,10]

def quick_sort_helper(nums,start,end):
    if(start>end):
        return
    p2 = start-1
    p1 = start
    pivot = nums[end-1]
    while p1<end-2:
        if nums[p1] >= pivot:
            p1+=1
        else:
            # swap p1,p2+1
            nums[p1],nums[p2+1] = nums[p2+1],nums[p1]
            p1+=1
            p2+=1
    nums[p1+1],nums[p2+1] = nums[p2+1],nums[p1+1]
    quick_sort_helper(nums,start,p2)
    quick_sort_helper(nums,p2+2,end)
    print(nums) 

def quick_sort(nums):
    quick_sort_helper(nums,0,len(nums))
quick_sort(nums)


"""
