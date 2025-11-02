# given a array of nums, waf to check whether if duplicates are present or not

def D(A):
    for i in range(len(A)):
        if A[abs(A[i])] < 0:
            return True
        A[abs(A[i])] = -A[abs(A[i])]
        # print(A)
    return False

def D2(A): # use sorting
    A.sort()
    for i in range(1, len(A)):
        if A[i] == A[i - 1]:
            return True
    return False


print(D([3,2,1,2,2,2,3]))
print(D2([3,2,1,2,2,2,3]))