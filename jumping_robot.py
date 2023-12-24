n = int(input("n: "))
f = int(input("f: "))
d = [0] * n
if f == 1:
    d= list(map(int, input("d: \n").split(" ")))
else:
    m, x, y, z = map(int, input().split(" "))
    c = list(map(int, input("d: \n").split(" ")))
    print(c)
    for i in range(n):
        if m <= i and i <= n:
            d[i] = ((x* d[i-2] + y * d[i-1] + z) % pow(10, 9)) + 1
        elif  m-1 >= i: 
            d[i] = c[i]
ans = []
d+=d
print(d)
for i in range(n):
    a = d[i]
    for k in range(n):
        if a + k >= d[i+k]:
            print(a+k, d[i+k])
            exit()
            ans.append([a, d[i+k]-k])

# print(max(ans, key=lambda x: x[1]))

