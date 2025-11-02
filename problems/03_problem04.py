# find first, second and third minimum el in an array 
# in N time

arr = [7, 3, 9, 1, 5, 2, 8]

# f,s,t = inf
# i < f

"""
slide:

i<f
f,s,t
 i, f,s

i<s
s,t
i, s

i<t
  t=c
"""

def getThreeMinumums(nums):
    first_min = second_min = third_min = float('inf')
    for x in nums:
        if x < first_min:
            third_min = second_min
            second_min = first_min
            first_min = x
        elif x < second_min:
            third_min = second_min
            second_min = x
        elif x < third_min:
            third_min = x
    return [first_min,second_min,third_min]

print(getThreeMinumums(arr))