for i in range(0,int(input())):
    n,k=map(int,input().split())
    p=list(map(int,input().split()))
    for i in p:
        if i%k==0:
            print(1,end='')
        else:
            print(0,end='')
    print('')
