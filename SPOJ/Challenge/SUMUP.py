t=int(input())
for i in range(t): 
    x=float(input()) 
    val=((x*(x+1))/(2*(x**2+x+1))) 
    print(format(val,'.5f'))