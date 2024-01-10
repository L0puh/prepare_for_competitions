a = [1, 2, 5, 10, 50, 100, 500, 1000, 2000, 5000]


def main(s):
    m = 0
    # finds the "floor"
    for i in a:
        if i > s:
            break
        if i > m:
            m=i

    sol = [m]
    
    while m < s:
        for i in reversed(a):
            # finds always the max result
            if i+m <= s:
                sol.append(i)
                m+=i
                break # you need the break
                      # cuz otherwise it grabs
                      # smaller ones too
    return sol 

def solution(s):
    coins = []
    for x in reversed(a):
        coins += [x] * (s // x)
        s %= x
    return coins


s = int(input())
if (solution(s) == main(s)):
    print("OK", main(s))
main(s)
