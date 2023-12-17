#knapsack problem:

capasity = int(input("capasity: "))
n = int(input("amount of things: "))
resources = []
for i in range(n):
    s  = int(input(f"size {i}:"))
    v = int (input(f"value {i}:"))
    resources.append([s, v])
ratio = []
for s, v in resources:
    ratio.append([s, v, v/s])

m = max(ratio, key=lambda x: x[2])
sol = [m]
m = m[2]
if m < capasity:
    print(ratio)
    while m < capasity:
        for s, v, w in sorted(ratio, key=lambda x: x[2], reverse=True):

            if (s+m) <= capasity:
                sol.append([s, v, w])
                m+=s
                break
            if (s*w)+m >= capasity:
                sol.append([s, v, w])
                m += s*w
print(sol, m)
