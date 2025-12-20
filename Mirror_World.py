t= int(input())
for _ in range(0,t):
    s=input()
    a,b=map(str,s.split())
    s=s[::-1]
    _b,_a=map(int,s.split())
    if _a==_b:
        print(f"{a} = {b}")
    elif _a>_b:
        print(f"{a} > {b}")
    else:
        print(f"{a} < {b}")