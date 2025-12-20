a,b,c=map(int,input().split())
gap=a-b
x=a//b
if gap<=0 or x<c:
    print("No")
else :
    print("Yes")
