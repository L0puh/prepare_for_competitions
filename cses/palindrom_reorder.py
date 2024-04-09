n = input()
m = {x:0 for x in n}
for c in n:
    m[c]+=1
s = ''
l = 0
rest = ''
target = 0
for key in m:
    i = m[key]
    if i == 1 or i % 2 != 0:
        target += 1
    if target > 1:
        print("NO SOLUTION")
        quit(0)
    if i % 2 == 0:
        i//=2
        while i:
            i-=1
            s+=key
    else:
        while i:
            i-=1
            rest += key
print(s+rest+s[::-1])
        

