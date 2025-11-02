# first repaeated element in array

def FirstRepeated(A):
    Map = {}
    for i in range(len(A)):
        if A[i] in Map and Map[A[i]] > 0:
            Map[A[i]] = -Map[A[i]]
        Map[A[i]] = i+1
        #return key based on max value
    return max(Map, key = Map.get)

print(FirstRepeated([3,2,1,2,2,3])) # 3