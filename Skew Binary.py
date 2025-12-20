import sys
for s in sys.stdin:
    if s=='0':
        break;
    ans=0
    s=s[::-1][1:]
    for i in range (0,len(s)):
       ans+=(2**(i+1)-1)*int(s[i])
    print(ans)
