import math

_ = int(input())
t = int(input())
l = []
for i in range(t):
    x1, y1, x2, y2, x3, y3 = map(int, input().split(" "))

    a = (math.pow(y2-y1, 2) + math.pow(x2-x1, 2))
    b = (math.pow(y3-y2, 2) + math.pow(x3-x2, 2))
    c = (math.pow(y3-y1, 2) + math.pow(x3-x1, 2))
    l.append([int(a), int(b), int(c)]) 

count = 0
ans = []
print(l)
for i in range(t):
    a, b, c = l[i]
    for k in range(len(l)):
        if a in l[i] and b in l[i] or a in l[i] and c in l[i]\
                and b in l[i] and c in l[i]:
            print(a, b, c)    

for i in range(1,  len(ans)):
    print(ans[i-1])
    if ans[i] == ans[i-1]:
        continue
