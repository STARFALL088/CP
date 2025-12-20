while True:
    try:
        t,a,b=map(int,input().split())
        ans= (t**a -1)//(t**b-1)
        if ((t**a -1)%(t**b-1) or ans>=10**99):
            print(f"({t}^{a}-1)/({t}^{b}-1) is not an integer with less than 100 digits.")
        else:
            print(f"({t}^{a}-1)/({t}^{b}-1) {int(ans)}")
    except EOFError:
        break