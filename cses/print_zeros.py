import math

def main(a):
    res = math.factorial(a)
    cnt = 0
    s = str(res)
    for c in s[::-1]:
        if c != '0': break 
        cnt+=1
    return cnt

def check(a):
    ans = 0
    while (a/5 >= 1):
        ans+=int(a/5)
        a/=5
    return int(ans)

if __name__ == "__main__": 
    t = True
    for i in range(500):
        if (main(i) != check(i)):
            t = False
            print("wrong: ", i, main(i), check(i))
    if t: print("all good")
