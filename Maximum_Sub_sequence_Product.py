while(True):
    try:
        a=list(map(int,input().split()))
        mx=a[0]
        for i in range (0,len(a)-1):
            ans=1
            for j in range(i,len(a)-1):
                ans=ans*a[j]
                mx=max(mx,ans)
        print(mx)
    except EOFError:
        break