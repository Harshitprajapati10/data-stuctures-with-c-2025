# find the missing number

def getMissing(A):
    N = len(A) + 1
    tSum = (N*(N+1))//2
    aSum = 0
    for i in range(len(A)): aSum += A[i]
    return tSum-aSum

def getMissingXOR(A): # prevent overflow
    X,Y = 0,0
    for i in range(len(A)):
        X = X^A[i]
    for j in range(1,len(A)+2):
        Y = Y^j
    return X^Y

A= [1,2,4,6,7,3,8]
print(getMissing(A))
print(getMissingXOR(A))


# find number occuring odd number of times

def getODDoccurence(A):
    X = 0
    for i in range(len(A)): X ^= A[i]
    return X

print(getODDoccurence([1,2,3,2,3,1,3]))#3