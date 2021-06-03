T=(int(input()))
for t in range(T):
    n=int(input())
    arr=input()
    a=[int(x) for x in arr.split()]
    b=a.copy()
    a.sort()
    if b==a:
        print (0)
        continue
    if b[0]==a[0]:
        print (1)
    elif b[n-1]==a[n-1]:
        print (1)
    else :
        print (2)
    
