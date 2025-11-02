# values whose sum is closest to zero

# [60,-10,70,-80,-85]

# out : [-80,-85]
def getSumClosestToZero(A):
    if len(A) < 2:
        return None  
    A.sort() 
    s, e = 0, len(A) - 1
    closest_sum = float('inf')
    pair = (None, None)
    while s < e:
        curr_sum = A[s] + A[e]
        if abs(curr_sum) < abs(closest_sum):
            closest_sum = curr_sum
            pair = (A[s], A[e])

        if curr_sum < 0:
            s += 1
        else:
            e -= 1
    return pair


A = [60,-10,70,80,-85]
print(getSumClosestToZero(A))