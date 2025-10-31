"""
[6,4,1,7,3,2,5]
# i^2 +j^2 = k^2
# ans = [1,4,6]
"""

A = [6,4,1,7,3,2,5]
"""
[(0,6),(1,4),(2,1),(3,7),(4,3),(5,2),(6,5)]
.sort()
[(2,1),(5,2),(4,3),(1,4),(6,5),(0,6),(3,7)]

Map = {6:0,4:1,1:2,7:3,3:4,2:5,5:6}

.sort() and square
[1,4,9,16,25,36,49]

k = 49
search for i ,j

k reverse loop
    find i,j forward loop, while(S<=e)
        if found
            return [i,j,k] // i=2,j=3,k=4 // ind[i,j,k] = 0
        if >
            e--
        if <
            s++
"""

def getIndex(A):
    indexed = list(enumerate(A))
    indexed.sort(key=lambda x:x[1])
    # print(indexed)
    #square each element
    A.sort()
    for i in range(len(A)): A[i] = A[i]**2
    for k in range(len(A)-1,1,-1):
        s,e = 0,len(A)-2
        while(s<e):
            if A[s]+A[e] == A[k]:
                return [indexed[s][0],indexed[e][0],indexed[k][0]]
            elif A[s]+A[e] > A[k]:
                e -=1
            else: s+=1
    return [-1,-1,-1]

            

print(getIndex(A))