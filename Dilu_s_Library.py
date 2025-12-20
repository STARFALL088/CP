t=int(input())
for i in range(0,t):
    a,b=map(float,input().split())
    ans=int(round(a/b,100))
    print(int(a*int((10**100))))
    print(ans);
    print(f"{ans}".rstrip('0').rstrip('.'))
