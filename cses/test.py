c = 0
for i in range(0, 10000):
    if (i > 9 and i < 100):
        print(i, c, c+1)
        c+=2
    elif (i >= 100 and i < 1000):
        print(i, c, c+1, c+2)
        c+=3
    elif (i >= 1000):
        print(i, c, c+1, c+2, c+3)
        c+=4
    else:
        print(i, c)
        c+=1
