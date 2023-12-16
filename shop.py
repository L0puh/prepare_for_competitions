"""
запомни формулу 
арифметической прогрессии

S = (m+1) * m // 2 => 
должна быть больше
запрашиваемой суммы!( > n )

(признаться, не до конца 
понимаю почему...)

плюс используй жадный 
алгоритм

хинты на данный способ решения
1. дается сортированный список ресурсов
2. дается максимум 

"""


from random import randint


"""

SOLUTION:

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

