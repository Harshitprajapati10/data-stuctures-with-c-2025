

def prints(a, n, index):
    b = [None] *2*n
    i = 0

    # copy a[]to b[] two times
    while i<n:
        b[i] = b[n+i] = a[i]
        i+=1
    i = index
    while i<n+index:
        print(b[i], end = " ")
        i += 1

def printsTwo(a, n, ind):
     i = ind
     while i < n + ind :
        print(a[(i % n)], end = " ")
        i = i + 1
    
# Driver Code
a = ['A', 'B', 'C', 'D', 'E', 'F']
n = len(a);
prints(a, n, 3);
print()
printsTwo(a, n, 3);

"""
b = [None] * 12
b = ['A', 'B', 'C', 'D', 'E', 'F','A', 'B', 'C', 'D', 'E', 'F']
i loops from 3 till 9
answer :  'D', 'E', 'F','A', 'B',C
"""