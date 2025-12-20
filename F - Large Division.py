for i in range(0,int(input())):
    a,b=map(int,input().split())
    if a%b!=0:
        print(f"Case {i+1}: not divisible")
    else:
        print(f"Case {i+1}: divisible")

