fib = [1,1,2,3]
def rekursiv(n):
    if(n <=2):
        return 1
    return rekursiv(n-1)+rekursiv(n-2)

def iterativ(n):
    a, b = 1, 1
    for i in range(3, n+1):
        m = a+b
        b=a
        a=m
        
    return a


def dynamisch(n):
    n-=1
    while len(fib)<=n :
        length = len(fib)
        fib.append(fib[length-1]+fib[length-2])
    return fib[n]
    

for i in range(7):
    print(iterativ(i))

