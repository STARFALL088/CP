import sys
m={}
for s in sys.stdin:
    a=list(map(str,s.split()))
    print(a)
    if a[0]=="var":
        for i in a[3]:
            if i=='$':
                i=''
        m[a[1]]=f'{a[3]}'
    if a[0]=="print":
        _a,_b=map(str,s.split())
        for i in a[1]:
            if i=='$':
                i=''
        print(_b)