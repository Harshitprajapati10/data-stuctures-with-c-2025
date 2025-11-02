# Given an array of n numbers. Give an algorithm for finding the element which appears the maximum number of times in the array


def maxRep(A):#using dict
    map = {}
    for i in range(len(A)):
        if A[i] in map:map[A[i]] += 1
        else:map[A[i]] = 1
    return max(map, key = map.get)

def maxRepOpt(A):
    n = len(A)
    el,index  = 0,0
    for i in range(n):
        A[A[i]%n]+=n
    for i in range(n):
        if(A[i]//n>el):
            el = A[i]//n
            index = i
    return index


print(maxRep([3,2,1,2,2,2,3]))
print(maxRepOpt([3,2,1,2,2,3]))