# find two repeating elements in array
# range 1->n

import math

A = [4,2,4,5,2,3,1] # out = [4,2]

def getSqrt(n):
    if n==0 or n==1: return n
    low,high,ans = 1,n,0
    while(low<=high):
        mid = (low+high)//2
        if mid*mid == n: return mid
        elif mid*mid <n:
            ans = mid
            low = mid +1
        else: high = mid-1
    return ans

def get_factorial(n, memo={}):
    if n == 0 or n == 1:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = n * get_factorial(n - 1, memo)
    return memo[n]

def getTwoRepeatingEl(A):
    n = max(A)
    sum_of_range = (n*(n+1))//2
    prod_of_range = get_factorial(n)
    sum_of_arr = sum(A)
    prod_of_arr = math.prod(A)
    X_plus_Y = sum_of_arr - sum_of_range
    X_dot_Y = prod_of_arr//prod_of_range
    X_minus_Y = getSqrt(((X_plus_Y)**2)-4*(X_dot_Y))
    X = (X_plus_Y + X_minus_Y)//2
    Y = (X_plus_Y - X_minus_Y)//2
    return [X,Y]

print(getTwoRepeatingEl(A))