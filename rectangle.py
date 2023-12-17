"""
не могу проверить ответы через 
код, но вероятно верно....
польностью все сама написала.
кайф то какой!! 

"""

def rec(rec_h, rec_v, m):
    for h in reversed(rec_h):
        for v in reversed(rec_v):
            if (h+1) * (v+1) == m:
                return [v, h]


def main(data):
    a, b, k, m = data

    v = a - 1
    h = b - 1

    if a <= 1:
        h = 0
    if b <= 1:
        v = 0

    possible_m = []
    for i in range(1, a*b+1):
        if a*b % i == 0:
            possible_m.append(i)
    if a*b % 2 != 0:
        for i in range(1, max(possible_m)):
            if i % 2 == 0:
                if i not in possible_m:
                    possible_m.append(i)

    if h == 0 and v == 0:
        return []
    elif v+h <  k :
        return []
    elif m > a*b and m < k:
        return []
    elif m not in possible_m:
        return []
    else:
        sol = []
        rec_h = [i for i in range(b)] 
        rec_v = [i for i in range(a)]
        return rec(rec_h, rec_v, m)


t = int(input())
sol = []
for i in range(t):
    data = list(map(int, input().split()))
    sol.append( main(data))
for i in sol:
    if i:
        print(i[0], i[1])
    else:
        print(-1)
