# waf for selection sort


def selection_sort(nums):
     for i in range(len(nums)):
         min_index = i
         for j in range(i+1,len(nums)):
              if nums[j] < nums[min_index]:
                   min_index = j
         
         nums[i],nums[min_index] = nums[min_index],nums[i]
     return nums
              
def selection_sort_stable(nums):
     for i in range(len(nums)):
         min_index = i
         for j in range(i+1,len(nums)):
              if nums[j] < nums[min_index]:
                   min_index = j
         min_value = nums[min_index]
         while(min_index>i):
             nums[min_index] = nums[min_index-1]
             min_index-=1
         nums[i] = min_value
        #  if(nums[min_index] != nums[i]):
        #       nums[i],nums[min_index] = nums[min_index],nums[i]
     return nums       
        #   
          

print(selection_sort([4,3,2,5,8,7,3]))
print(selection_sort_stable([4,3,2,5,8,7,3]))


"""
stablize selection sort by
 -- select min from right
 -- take it in a variable(key)
 -- move one shift right i till minindex
 -- put key at i
"""