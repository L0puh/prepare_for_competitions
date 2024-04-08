import math

def main(a):
    res = math.factorial(a)
    cnt = 0
    s = str(res)
    for c in s[::-1]:
        if c != '0': break 
        cnt+=1
    return cnt

if __name__ == "__main__": 
    for i in range(500):
        print(i, main(i))
