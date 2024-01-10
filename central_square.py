"""
! check even solutions 
(mult coordinates then)
"""

def main():
    n = int(input()) 
    m = int(input())
    target = False
    if n % 2 == 0 or m % 2 == 0:
        target = True
    while m-2 > 0 and n-2 > 0:
        m=m-2
        n=n-2
    if target: print(n*m)
    else: print(max(n, m))

if __name__ == "__main__":
    main()
