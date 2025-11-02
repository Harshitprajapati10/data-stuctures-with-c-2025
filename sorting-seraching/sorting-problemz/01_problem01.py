# Given an array find index of two elements so that that is less than or equal to target


A = [5,4,6,8,3]
tar = 7
# ans = [1,4]
# {5:0,4:1,6:2,8:1}

def getIndex(A,tar):
    Map = {}
    for i in range(len(A)):
        if tar-A[i] in Map:
            return [Map[tar-A[i]],i]
        Map[A[i]] = i
    return [-1,-1]

print(getIndex(A,tar))

# time : N
# space :N
# sorting: time = nlgn, spa



# what is the array is sorted

B = [2,5,6,8,9,11]
K = 15
# out  = [2,4]

def getIndexinSorted(A,K):
    s,e = 0, len(A)-1
    # print(s,e)
    while(s<e):
        # print(s,e)
        if(A[s]+A[e]>K):e-=1
        elif(A[s]+A[e]<K):s+=1
        else:return [s,e]
    return [-1,-1]

print(getIndexinSorted(B,K))


# time: N
# space :1