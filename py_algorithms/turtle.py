n = int(input("h:"))
m = int(input("w:"))


def main(n, m):
    ans = 0
    while n >= 2 and m >= 2:
        m = m-2
        ans += n+1
        n,m = m, n
    ans += m*n
    print(ans)

main(n, m)

