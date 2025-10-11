import math
x=int(input())
ans=1
baad=int(math.log(2,x))
while(True):
    z=x%10;
    if(z<9):
        x=x-pow(10,baad)
    baad=baad-1
    ans=ans*9
    if(baad==1):
        break
if(x<19):
    ans=9
print(ans)
