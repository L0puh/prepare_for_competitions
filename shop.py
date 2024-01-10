"""
S = (m+1) * m // 2 > n 
using greedy algorighm

"""

def get(n):
    l = []
    for i in range(n):
        l.append(n-i)
    return l

def main(m, n):
    if (m+1)*m//2 < n:
        print(0)
        return [0]
    l = get(m)
    s = m
    solution = [s]
    while s < n:
        for i in l:
            if i in solution:
                continue
            if i+s <= n:
                solution.append(i)
                s+=i
    print(solution)
    return solution

m = int(input("max: "))
n = int(input("needed: "))
main(m, n)

