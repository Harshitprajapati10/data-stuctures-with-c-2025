# in an array print next greater element for every element. here, NGE is for an element x is the first greater element on the right side of x in the array.If no greater element exists for an element , the NGE is -1;what is the time


nums = [4, 5, 2, 25]
# [13, 7, 6, 12]

def getNGE(nums):
    stack = []
    NGE = []
    for num in nums:
        if not stack:
            stack.append(num)
        while not stack and num > stack[-1]:
            NGE.append(num)
            stack.pop()
        if num < stack[-1]:
            stack.append(num)

def next_greater_elements(arr):
    n = len(arr)
    nge = [-1] * n  # Initialize all NGE values as -1
    stack = []      # Stack to store indices of elements

    for i in range(n):
        # While stack is not empty and current element is greater than element at stack's top
        while stack and arr[i] > arr[stack[-1]]:
            index = stack.pop()
            nge[index] = arr[i]  # Current element is NGE for popped element

        stack.append(i)  # Push current element index onto stack

    return nge

# Example usage
arr = [4, 5, 2, 25]
print(next_greater_elements(arr))  # Output: [5, 25, 25, -1]
