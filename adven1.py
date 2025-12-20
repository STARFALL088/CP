ans = 50
cnt=0;
cnt2=0
with open("adven.txt") as f:
    for s in f:
        s = s.strip()
        if not s:
            continue
        last=ans
        if s[0] == 'R':
            ans += int(s[1:])
            if ans>=100:
                cnt2+=(ans//100)
        else:
            ans-=int(s[1:])
            if ans<=0:
                cnt2+=(1-(ans//100))
                ans+=100000
        ans =ans%100
        if ans==0:
            cnt=cnt+1
print(cnt2)
