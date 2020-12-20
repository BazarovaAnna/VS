led=[0]*8
i=0
n=7
for k in range(100):
    print(i)
    led1=n-i
    if i!=n:
        led2=n-i-1
    else:
        led2=n
        i=-1
    led[led1]='*'
    led[led2]='*'
    print(led)
    led[led1]=0
    led[led2]=0
    i=i+1
